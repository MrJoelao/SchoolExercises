#!/bin/bash

# Verifica se fzf è installato
if ! command -v fzf &> /dev/null; then
    echo "Assicurati di avere installato 'fzf'."
    exit 1
fi

# Funzione per aggiungere un repository come subtree
add_subtree() {
    local repo_name=$1
    local repo_url=$2
    local target_dir=$3
    local branch=$4

    echo "Aggiungendo il repository $repo_name (branch: $branch) nella cartella $target_dir..."

    # Aggiungi il repository remoto
    git remote add "$repo_name" "$repo_url"

    # Esegui il fetch del repository remoto
    git fetch "$repo_name"

    # Aggiungi il subtree specificando esplicitamente il branch, senza squash
    git subtree add --prefix="$target_dir/$repo_name" "$repo_name" "$branch"

    echo "Repository $repo_name (branch: $branch) aggiunto con successo come subtree in $target_dir."
}

# Loop per aggiungere più repository
while true; do
    # Chiedi se si vuole creare una nuova cartella
    read -p "Vuoi creare una nuova cartella? (s/n): " create_dir
    
    if [[ "$create_dir" =~ ^[Ss]$ ]]; then
        read -p "Inserisci il nome della nuova cartella: " new_dir
        mkdir -p "$new_dir"
        target_dir="$new_dir"
    else
        # Funzione per listare le cartelle del percorso corrente
        list_dirs() {
            local current_path="${1:-.}"
            find "$current_path" -maxdepth 1 -type d -not -path '*/\.*' -not -path "$current_path" -printf '%P\n' | sort
        }

        # Usa fzf per navigare le cartelle in modo interattivo
        current_dir="."
        while true; do
            target_dir=$(list_dirs "$current_dir" | \
                fzf --prompt="Seleziona la cartella ($current_dir): " \
                    --header="Usa → per entrare nella cartella, ← per tornare indietro, Enter per selezionare" \
                    --preview="find '$current_dir/{}' -maxdepth 1 -type d -not -path '*/\.*' -not -path '$current_dir/{}' -printf '%P\n' | sort" \
                    --preview-window=right:50% \
                    --bind="right:execute(echo {} >> /dev/null && [[ -d '$current_dir/{}' ]] && echo '$current_dir/{}' > /tmp/fzf_dir)+abort" \
                    --bind="left:execute(echo {} >> /dev/null && dirname '$current_dir' > /tmp/fzf_dir)+abort" \
                    --bind="enter:accept")

            # Se l'utente preme ESC o non seleziona nulla
            if [ -z "$target_dir" ] && [ ! -f /tmp/fzf_dir ]; then
                echo "Nessuna cartella selezionata. Uscita."
                rm -f /tmp/fzf_dir
                break
            fi

            # Se l'utente ha premuto destra o sinistra (navigazione)
            if [ -f /tmp/fzf_dir ]; then
                current_dir=$(cat /tmp/fzf_dir)
                rm -f /tmp/fzf_dir
                continue
            fi

            # L'utente ha selezionato una cartella con Enter
            target_dir="$current_dir/$target_dir"
            target_dir=${target_dir#./}
            break
        done
    fi

    # Usa fzf per selezionare il repository locale
    echo "Seleziona il repository locale:"
    repo_path=$(find ~ -name ".git" -type d -prune 2>/dev/null | sed 's/\/.git$//' | fzf --prompt="Seleziona il repository: ")
    
    if [ -z "$repo_path" ]; then
        echo "Nessun repository selezionato. Uscita."
        break
    fi

    # Estrai il nome del repository dal path
    repo_name=$(basename "$repo_path")
    if [ "$repo_name" == "exit" ]; then
        break
    fi

    # Costruisci l'URL locale del repository
    repo_url="file://$repo_path"

    echo "Repository selezionato: $repo_name"
    echo "Path: $repo_path"
    echo "URL: $repo_url"

    # Chiedi il branch del repository mostrando anche i commit
    cd "$repo_path"
    
    # Funzione per visualizzare i commit di un branch
    show_commits() {
        local branch=$1
        git log --format="%C(yellow)%h%C(reset) - %C(cyan)%ar%C(reset) - %s" $branch | \
        fzf --prompt="Commit del branch $branch (← per tornare): " \
            --header-first \
            --header="=== Commit History ===\n" \
            --layout=reverse \
            --border=rounded \
            --margin=5% \
            --padding=5% \
            --bind="left:abort" \
            --preview="git show --color=always {1}" \
            --preview-window=right:60%
        return $?
    }

    # Selezione del branch con preview dei commit
    while true; do
        branch=$(git branch --format='%(refname:short)' | \
                fzf --prompt="Seleziona il branch: " \
                    --header-first \
                    --header="=== Branch Disponibili ===\n(q per uscire)" \
                    --layout=reverse \
                    --border=rounded \
                    --margin=5% \
                    --padding=5% \
                    --preview='git log --format="%C(yellow)%h%C(reset) - %C(cyan)%ar%C(reset) - %s" {}' \
                    --preview-window=right:60%)

        # Se l'utente preme q o ESC nella selezione del branch
        if [ -z "$branch" ] && [ $? -ne 130 ]; then
            echo "Selezione branch annullata."
            exit 1
        fi

        # Se è stato selezionato un branch, esci dal ciclo
        if [ ! -z "$branch" ]; then
            break
        fi
    done
    
    cd - > /dev/null

    # Se non viene selezionato un branch, usa main come default
    branch=${branch:-main}

    # Verifica se ci sono modifiche non committate
    if [[ $(git status --porcelain) ]]; then
        echo "ATTENZIONE: Ci sono modifiche non committate nel repository."
        read -p "Vuoi procedere comunque? (s/n): " proceed_anyway
        if [[ ! "$proceed_anyway" =~ ^[Ss]$ ]]; then
            echo "Operazione annullata. Fai commit o stash delle modifiche prima di procedere."
            continue
        fi
        echo "Procedendo con modifiche non committate..."
    fi

    # Mostra il riepilogo delle operazioni
    echo -e "\n=== RIEPILOGO DELLE OPERAZIONI ==="
    echo "Directory di destinazione: $target_dir"
    echo "Repository: $repo_name"
    echo "URL: $repo_url"
    echo "Branch: $branch"
    echo -e "\nI seguenti comandi verranno eseguiti:"
    echo "1. git remote add $repo_name $repo_url"
    echo "2. git fetch $repo_name"
    echo "3. git subtree add --prefix=$target_dir/$repo_name $repo_name $branch"
    
    # Chiedi conferma
    read -p $'\nVuoi procedere con queste operazioni? (s/n): ' confirm
    if [[ "$confirm" =~ ^[Ss]$ ]]; then
        add_subtree "$repo_name" "$repo_url" "$target_dir" "$branch"
    else
        echo "Operazione annullata."
        continue
    fi

done

echo "Operazione completata."
