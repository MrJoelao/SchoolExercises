#!/bin/bash

# Funzione per gestire l'interruzione con Ctrl+C
trap 'echo -e "\\n\\e[1;31m✘ Operazione interrotta dall'\''utente.\\e[0m"; rm -f /tmp/fzf_dir; exit 1' INT

# Parse command line arguments
SKIP_REPO_PROMPT=false
while getopts "y" opt; do
    case $opt in
        y)
            SKIP_REPO_PROMPT=true
            ;;
        \?)
            echo "Usage: $0 [-y] (y: skip repository prompt)"
            exit 1
            ;;
    esac
done

# Check if dependencies are installed
for cmd in fzf; do
    if ! command -v "$cmd" &> /dev/null; then
        echo "Make sure you have '$cmd' installed."
        exit 1
    fi
done

# Function to print colored boxes
print_box() {
    local text="$1"
    local width=60
    local padding=$(( (width - ${#text}) / 2 ))
    
    echo -e "\\e[1;36m┌$( printf '─%.0s' $(seq 1 $width) )┐"
    echo -e "│$( printf ' %.0s' $(seq 1 $padding) )$text$( printf ' %.0s' $(seq 1 $((width - ${#text} - padding))) )│"
    echo -e "└$( printf '─%.0s' $(seq 1 $width) )┘\\e[0m"
}

# Show current repository information
current_repo_path=$(git rev-parse --show-toplevel 2>/dev/null)
current_repo_name=$(basename "$current_repo_path" 2>/dev/null)
current_branch=$(git rev-parse --abbrev-ref HEAD 2>/dev/null)
current_commit=$(git rev-parse --short HEAD 2>/dev/null)
current_author=$(git config user.name 2>/dev/null)
current_email=$(git config user.email 2>/dev/null)

if [ -n "$current_repo_name" ]; then
    print_box "CURRENT REPOSITORY"
    echo -e "\\e[1;32m➜ Repository Name:\\e[0m $current_repo_name"
    echo -e "\\e[1;32m➜ Local Path:\\e[0m $current_repo_path"
    echo -e "\\e[1;32m➜ Current Branch:\\e[0m $current_branch"
    echo -e "\\e[1;32m➜ Latest Commit:\\e[0m $current_commit"
    echo -e "\\e[1;32m➜ Git User:\\e[0m $current_author ($current_email)"
    
    # Mostra lo stato delle modifiche
    if [[ $(git status --porcelain) ]]; then
        echo -e "\\e[1;33m➜ Status:\\e[0m Repository has uncommitted changes"
    else
        echo -e "\\e[1;32m➜ Status:\\e[0m Working tree clean"
    fi
    
    # Mostra informazioni sui remote
    echo -e "\\e[1;32m➜ Remote URLs:\\e[0m"
    git remote -v | awk '!seen[$0]++' | sed 's/^/  /'
    
    # Mostra numero di branch
    branch_count=$(git branch | wc -l)
    echo -e "\\e[1;32m➜ Branches:\\e[0m $branch_count total"
    
    # Mostra ultimi 3 commit
    echo -e "\\e[1;32m➜ Recent Commits:\\e[0m"
    git log -3 --pretty=format:"  %C(yellow)%h%Creset - %s %C(cyan)(%cr)%Creset" --abbrev-commit
    echo -e "\\n"
    
    if [ "$SKIP_REPO_PROMPT" = true ]; then
        echo -e "\\e[1;32m➜\\e[0m Using current repository (auto-selected)\\n"
        use_current="y"
    else
        read -p "$(echo -e "\\e[1;33m??\\e[0m Do you want to work on this repository? (y/n): ")" use_current
    fi

    if [[ "$use_current" =~ ^[Yy]$ ]]; then
        cd "$current_repo_path" || exit
    fi
else
    echo -e "\\e[1;31m✘ You are not in a git repository.\\e[0m"
    use_current="n"
fi

if [[ ! "$use_current" =~ ^[Yy]$ ]]; then
    print_box "REPOSITORY SELECTION"
    echo "Select a repository to work on:"
    target_repo=$(find ~ -name ".git" -type d -prune 2>/dev/null | sed 's/\/.git$//' | \
                 fzf --prompt="$(echo -e "\\e[1;36m⟫\\e[0m Select destination repository: ")" \
                     --border=rounded \
                     --margin=5% \
                     --padding=5%)
    
    if [ -z "$target_repo" ]; then
        echo -e "\\e[1;31m✘ No repository selected. Exiting.\\e[0m"
        exit 1
    fi
    
    cd "$target_repo" || exit
fi

# Funzione per eseguire l'operazione di aggiunta del subtree
perform_subtree_add() {
    local repo_name=$1
    local repo_url=$2
    local target_dir=$3
    local branch=$4
    local create_dir=$5

    if [ "$target_dir" = "." ]; then
        if ! git subtree add --prefix="$repo_name" "$repo_name" "$branch"; then
            return 1
        fi
    elif [[ "$create_dir" =~ ^[Yy]$ ]]; then
        echo -e "\\e[1;36m➜\\e[0m Creating directory $target_dir..."
        if ! mkdir -p "$target_dir"; then
            echo -e "\\e[1;31m✘ Failed to create directory\\e[0m"
            return 1
        fi
        echo -e "\\e[1;32m✓\\e[0m Directory created\\n"
        if ! git subtree add --prefix="$target_dir/$repo_name" "$repo_name" "$branch"; then
            return 1
        fi
    else
        if ! git subtree add --prefix="$target_dir/$repo_name" "$repo_name" "$branch"; then
            return 1
        fi
    fi
    return 0
}

# Function to add a repository as subtree
add_subtree() {
    local repo_name=$1
    local repo_url=$2
    local target_dir=$3
    local branch=$4
    local create_dir=$5
    local max_attempts=3
    local attempt=1

    print_box "ADDING SUBTREE IN PROGRESS"
    echo -e "\\e[1;36m➜\\e[0m Adding repository \\e[1;33m$repo_name\\e[0m [branch: \\e[1;33m$branch\\e[0m]"
    echo -e "\\e[1;36m➜\\e[0m Destination folder: \\e[1;33m$target_dir\\e[0m\\n"

    # Spinner for the process
    spin() {
        local pid=$1
        local delay=0.1
        local spinstr='⠋⠙⠹⠸⠼⠴⠦⠧⠇⠏'
        while [ "$(ps a | awk '{print $1}' | grep "$pid")" ]; do
            local temp=${spinstr#?}
            printf " \\e[1;36m%c\\e[0m  " "$spinstr"
            local spinstr=$temp${spinstr%"$temp"}
            sleep $delay
            printf "\\b\\b\\b\\b"
        done
        printf "    \\b\\b\\b\\b"
    }

    # Add remote repository with error handling
    echo -e "\\e[1;36m➜\\e[0m Adding remote..."
    if ! git remote add "$repo_name" "$repo_url" 2>/dev/null; then
        if git remote get-url "$repo_name" >/dev/null 2>&1; then
            echo -e "\\e[1;33m⚠ Remote already exists, updating URL...\\e[0m"
            git remote set-url "$repo_name" "$repo_url"
        else
            echo -e "\\e[1;31m✘ Failed to add remote\\e[0m"
            return 1
        fi
    fi
    echo -e "\\e[1;32m✓\\e[0m Remote added/updated\\n"

    # Fetch remote repository with error handling
    echo -e "\\e[1;36m➜\\e[0m Fetching..."
    if ! git fetch "$repo_name" 2>/dev/null; then
        echo -e "\\e[1;31m✘ Failed to fetch remote repository\\e[0m"
        git remote remove "$repo_name" 2>/dev/null
        return 1
    fi
    echo -e "\\e[1;32m✓\\e[0m Fetch completed\\n"

    # Add subtree with multiple attempts
    while [ $attempt -le $max_attempts ]; do
        echo -e "\\e[1;36m➜\\e[0m Adding subtree (attempt $attempt of $max_attempts)..."
        
        if perform_subtree_add "$repo_name" "$repo_url" "$target_dir" "$branch" "$create_dir"; then
            echo -e "\\e[1;32m✓\\e[0m Subtree added successfully\\n"
            
            # Remove the remote after successful operation
            echo -e "\\e[1;36m➜\\e[0m Cleaning up remote..."
            if git remote remove "$repo_name" 2>/dev/null; then
                echo -e "\\e[1;32m✓\\e[0m Remote removed\\n"
            else
                echo -e "\\e[1;33m⚠ Could not remove remote\\e[0m\\n"
            fi
            
            print_box "OPERATION COMPLETED"
            echo -e "\\e[1;32m✓\\e[0m Repository \\e[1;33m$repo_name\\e[0m successfully added!"
            return 0
        else
            if [[ $(git status --porcelain) ]]; then
                echo -e "\\e[1;33m⚠ Uncommitted changes detected\\e[0m"
                read -p "$(echo -e "\\e[1;33m??\\e[0m Do you want to stash changes and retry? (y/n): ")" stash_changes
                
                if [[ "$stash_changes" =~ ^[Yy]$ ]]; then
                    echo -e "\\e[1;36m➜\\e[0m Stashing changes..."
                    git stash save "Temporary stash for subtree operation"
                    
                    if perform_subtree_add "$repo_name" "$repo_url" "$target_dir" "$branch" "$create_dir"; then
                        echo -e "\\e[1;32m✓\\e[0m Subtree added successfully"
                        echo -e "\\e[1;36m➜\\e[0m Restoring stashed changes..."
                        git stash pop
                        
                        # Remove the remote after successful operation
                        echo -e "\\e[1;36m➜\\e[0m Cleaning up remote..."
                        if git remote remove "$repo_name" 2>/dev/null; then
                            echo -e "\\e[1;32m✓\\e[0m Remote removed\\n"
                        else
                            echo -e "\\e[1;33m⚠ Could not remove remote\\e[0m\\n"
                        fi
                        
                        print_box "OPERATION COMPLETED"
                        echo -e "\\e[1;32m✓\\e[0m Repository \\e[1;33m$repo_name\\e[0m successfully added!"
                        return 0
                    fi
                fi
            fi
        fi
        
        ((attempt++))
        if [ $attempt -le $max_attempts ]; then
            echo -e "\\e[1;33m⚠ Retrying...\\e[0m\\n"
        fi
    done

    # Remove remote if all attempts failed
    echo -e "\\e[1;36m➜\\e[0m Cleaning up remote after failure..."
    git remote remove "$repo_name" 2>/dev/null
    echo -e "\\e[1;31m✘ Failed to add subtree after $max_attempts attempts\\e[0m"
    return 1
}

# Loop to add multiple repositories
while true; do
    print_box "FOLDER CONFIGURATION"
    read -p "$(echo -e "\\e[1;33m??\\e[0m Do you want to use a folder? (y/n): ")" use_folder
    
    if [[ "$use_folder" =~ ^[Yy]$ ]]; then
        read -p "$(echo -e "\\e[1;33m??\\e[0m Do you want to create a new folder? (y/n): ")" create_dir
        
        if [[ "$create_dir" =~ ^[Yy]$ ]]; then
            read -p "$(echo -e "\\e[1;33m??\\e[0m Enter the new folder name: ")" new_dir
            target_dir="$new_dir"
        else
            # Function to list folders in current path
            list_dirs() {
                local current_path="${1:-.}"
                find "$current_path" -maxdepth 1 -type d -not -path '*/\.*' -not -path "$current_path" -printf '%P\n' | sort
            }

            # Use fzf for interactive folder navigation
            current_dir="."
            while true; do
                target_dir=$(list_dirs "$current_dir" | \
                    fzf --prompt="$(echo -e "\\e[1;36m⟫\\e[0m Select folder ($current_dir): ")" \
                        --header="Use → to enter folder, ← to go back, Enter to select" \
                        --preview="tree '$current_dir/{}' -L 2 -C" \
                        --preview-window=right:50% \
                        --border=rounded \
                        --margin=5% \
                        --padding=5% \
                        --bind="right:execute(echo {} >> /dev/null && [[ -d '$current_dir/{}' ]] && echo '$current_dir/{}' > /tmp/fzf_dir)+abort" \
                        --bind="left:execute(echo {} >> /dev/null && dirname '$current_dir' > /tmp/fzf_dir)+abort" \
                        --bind="enter:accept")

                if [ -z "$target_dir" ] && [ ! -f /tmp/fzf_dir ]; then
                    echo -e "\\e[1;31m✘ No folder selected. Exiting.\\e[0m"
                    rm -f /tmp/fzf_dir
                    break
                fi

                if [ -f /tmp/fzf_dir ]; then
                    current_dir=$(cat /tmp/fzf_dir)
                    rm -f /tmp/fzf_dir
                    continue
                fi

                target_dir="$current_dir/$target_dir"
                target_dir=${target_dir#./}
                break
            done
        fi
    else
        target_dir="."
    fi

    print_box "REPOSITORY SELECTION"
    echo "Select local repository:"
    repo_path=$(find ~ -name ".git" -type d -prune 2>/dev/null | sed 's/\/.git$//' | \
               fzf --prompt="$(echo -e "\\e[1;36m⟫\\e[0m Select repository: ")" \
                   --preview="tree {} -L 2 -C" \
                   --preview-window=right:50% \
                   --border=rounded \
                   --margin=5% \
                   --padding=5%)
    
    if [ -z "$repo_path" ]; then
        echo -e "\\e[1;31m✘ No repository selected. Exiting.\\e[0m"
        break
    fi

    repo_name=$(basename "$repo_path")
    if [ "$repo_name" == "exit" ]; then
        break
    fi

    repo_url="file://$repo_path"

    print_box "SELECTED REPOSITORY"
    echo -e "\\e[1;32m➜ Name:\\e[0m $repo_name"
    echo -e "\\e[1;32m➜ Path:\\e[0m $repo_path"
    echo -e "\\e[1;32m➜ URL:\\e[0m $repo_url"

    # Salva il percorso della repository corrente
    current_repo_path=$(pwd)
    
    # Cambia alla repository selezionata per controllare le modifiche
    cd "$repo_path" || exit
    
    # Controlla le modifiche non committate nella repository selezionata
    if [[ $(git status --porcelain) ]]; then
        echo -e "\\e[1;33m⚠ WARNING: There are uncommitted changes in the selected repository.\\e[0m"
        read -p "$(echo -e "\\e[1;33m??\\e[0m Do you want to proceed anyway? (y/n): ")" proceed_anyway
        if [[ ! "$proceed_anyway" =~ ^[Yy]$ ]]; then
            echo -e "\\e[1;31m✘ Operation cancelled. Commit or stash your changes before proceeding.\\e[0m"
            cd "$current_repo_path" || exit
            continue
        fi
        echo -e "\\e[1;33m➜ Proceeding with uncommitted changes...\\e[0m"
    fi
    
    # Torna alla repository originale
    cd "$current_repo_path" || exit

    # Function to display branch commits
    show_commits() {
        local branch=$1
        git log --format="%C(yellow)%h%C(reset) - %C(cyan)%ar%C(reset) - %s" "$branch" | \
        fzf --prompt="$(echo -e "\\e[1;36m⟫\\e[0m Commits for branch $branch (← to go back): ")" \
            --header-first \
            --header="=== Commit History ===\\n" \
            --layout=reverse \
            --border=rounded \
            --margin=5% \
            --padding=5% \
            --bind="left:abort" \
            --preview="git show --color=always {1}" \
            --preview-window=right:60%
        return $?
    }

    print_box "BRANCH SELECTION"
    while true; do
        # Salva il percorso corrente
        current_path=$(pwd)
        # Vai alla repository sorgente
        cd "$repo_path" || exit

        branch=$(git branch --format='%(refname:short)' | \
                fzf --prompt="$(echo -e "\\e[1;36m⟫\\e[0m Select branch: ")" \
                    --header-first \
                    --header="=== Available Branches ===\\n(q to exit)" \
                    --layout=reverse \
                    --border=rounded \
                    --margin=5% \
                    --padding=5% \
                    --preview='git log --format="%C(yellow)%h%C(reset) - %C(cyan)%ar%C(reset) - %s" {}' \
                    --preview-window=right:60%)

        # Torna alla repository di destinazione
        cd "$current_path" || exit

        if [ -z "$branch" ] && [ $? -ne 130 ]; then
            echo -e "\\e[1;31m✘ Branch selection cancelled.\\e[0m"
            exit 1
        fi

        if [ -n "$branch" ]; then
            break
        fi
    done
    
    branch=${branch:-main}

    print_box "OPERATIONS SUMMARY"
    if [ "$target_dir" = "." ]; then
        echo -e "\\e[1;32m➜ Directory:\\e[0m No folder (adding directly)"
    else
        echo -e "\\e[1;32m➜ Directory:\\e[0m $target_dir"
        if [[ "$create_dir" =~ ^[Yy]$ ]]; then
            echo -e "\\e[1;32m➜ Directory Action:\\e[0m Create new directory"
        fi
    fi
    echo -e "\\e[1;32m�� Repository:\\e[0m $repo_name"
    echo -e "\\e[1;32m➜ URL:\\e[0m $repo_url"
    echo -e "\\e[1;32m➜ Branch:\\e[0m $branch"
    echo -e "\\n\\e[1;36mCommands that will be executed:\\e[0m"
    if [ "$target_dir" = "." ]; then
        echo -e "  1. git remote add $repo_name $repo_url"
        echo -e "  2. git fetch $repo_name"
        echo -e "  3. git subtree add --prefix=$repo_name $repo_name $branch"
    elif [[ "$create_dir" =~ ^[Yy]$ ]]; then
        echo -e "  1. mkdir -p $target_dir"
        echo -e "  2. git remote add $repo_name $repo_url"
        echo -e "  3. git fetch $repo_name"
        echo -e "  4. git subtree add --prefix=$target_dir/$repo_name $repo_name $branch"
    else
        echo -e "  1. git remote add $repo_name $repo_url"
        echo -e "  2. git fetch $repo_name"
        echo -e "  3. git subtree add --prefix=$target_dir/$repo_name $repo_name $branch"
    fi
    
    read -r -p "$(echo -e "\\n\\e[1;33m??\\e[0m Do you want to proceed with these operations? (y/n): ")" confirm
    if [[ "$confirm" =~ ^[Yy]$ ]]; then
        add_subtree "$repo_name" "$repo_url" "$target_dir" "$branch" "$create_dir"
    else
        echo -e "\\e[1;31m✘ Operation cancelled.\\e[0m"
        continue
    fi

done

echo -e "\\n\\e[1;32m✓ All operations completed successfully!\\e[0m"
