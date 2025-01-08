#!/bin/bash

# Definizione dei colori e simboli
COLOR_GREEN="\\e[1;32m"
COLOR_RED="\\e[1;31m"
COLOR_YELLOW="\\e[1;33m" 
COLOR_CYAN="\\e[1;36m"
COLOR_RESET="\\e[0m"

SYMBOL_SUCCESS="✓"
SYMBOL_ERROR="✘"
SYMBOL_WARNING="⚠"
SYMBOL_ARROW="➜"
SYMBOL_QUESTION="??"

# Simboli colorati preformattati
CHECKMARK="${COLOR_GREEN}${SYMBOL_SUCCESS}${COLOR_RESET}"
CROSS="${COLOR_RED}${SYMBOL_ERROR}${COLOR_RESET}"
WARNING="${COLOR_YELLOW}${SYMBOL_WARNING}${COLOR_RESET}"
ARROW="${COLOR_CYAN}${SYMBOL_ARROW}${COLOR_RESET}"
QUESTION="${COLOR_YELLOW}${SYMBOL_QUESTION}${COLOR_RESET}"
PROMPT="${COLOR_CYAN}⟫${COLOR_RESET}"

# Funzione helper per formattare un simbolo con un colore specifico
format_symbol() {
    local color=$1
    local symbol=$2
    echo "${color}${symbol}${COLOR_RESET}"
}

# Funzione per stampare messaggi colorati
print_colored() {
    local color=$1
    local symbol=$2
    local message=$3
    echo -e "${color}${symbol}${COLOR_RESET} ${message}"
}

# Funzione per stampare messaggi di successo
print_success() {
    print_colored "$COLOR_GREEN" "$SYMBOL_SUCCESS" "$1"
}

# Funzione per stampare errori
print_error() {
    print_colored "$COLOR_RED" "$SYMBOL_ERROR" "$1"
}

# Funzione per stampare warning
print_warning() {
    print_colored "$COLOR_YELLOW" "$SYMBOL_WARNING" "$1"
}

# Funzione per stampare info
print_info() {
    print_colored "$COLOR_CYAN" "$SYMBOL_ARROW" "$1"
}

# Funzione per stampare domande
print_question() {
    print_colored "$COLOR_YELLOW" "$SYMBOL_QUESTION" "$1"
}

# Funzione per gestire l'interruzione con Ctrl+C
trap 'print_error "Operazione interrotta dall'\''utente."; rm -f /tmp/fzf_dir; exit 1' INT

# Funzione per mostrare l'help
show_help() {
    cat << EOF
Usage: $0 [options]

Options:
    -y              Skip repository prompt
    -r REPO_PATH    Specify the repository path to add
    -b BRANCH       Specify the branch (default: main)
    -d DIR          Specify the target directory (default: .)
    -c              Create the target directory if it doesn't exist
    -h              Show this help message
    
Examples:
    $0                                          # Interactive mode
    $0 -y                                       # Skip prompts in interactive mode
    $0 -r ~/myrepo -b develop -d libs -c       # Add ~/myrepo (develop branch) to libs/myrepo
    $0 -r ~/myrepo -d .                        # Add ~/myrepo to current directory
EOF
    exit 0
}

# Modifica la sezione di parsing degli argomenti:
SKIP_REPO_PROMPT=false
REPO_PATH=""
TARGET_DIR="."
BRANCH="main"
CREATE_DIR=false

# Parse command line arguments
while getopts "yr:b:d:ch" opt; do
    case $opt in
        y)
            SKIP_REPO_PROMPT=true
            ;;
        r)
            REPO_PATH="$OPTARG"
            ;;
        b)
            BRANCH="$OPTARG"
            ;;
        d)
            TARGET_DIR="$OPTARG"
            ;;
        c)
            CREATE_DIR=true
            ;;
        h)
            show_help
            ;;
        \?)
            echo -e "${CROSS} Invalid option: -$OPTARG"
            show_help
            ;;
        :)
            echo -e "${CROSS} Option -$OPTARG requires an argument."
            show_help
            ;;
    esac
done

# Dopo il parsing degli argomenti, aggiungi:

# Se sono stati forniti gli argomenti necessari, esegui in modalità non interattiva
if [ -n "$REPO_PATH" ]; then
    if [ ! -d "$REPO_PATH/.git" ]; then
        echo -e "${CROSS} $REPO_PATH is not a valid git repository"
        exit 1
    fi

    repo_name=$(basename "$REPO_PATH")
    repo_url="file://$REPO_PATH"

    print_box "OPERATIONS SUMMARY"
    echo -e "${ARROW} Repository: ${repo_name}"
    echo -e "${ARROW} Branch: ${BRANCH}"
    echo -e "${ARROW} Target Directory: ${TARGET_DIR}"
    if [ "$CREATE_DIR" = true ]; then
        echo -e "${ARROW} Will create directory if needed"
    fi

    if [ "$SKIP_REPO_PROMPT" = false ]; then
        read -r -p "$(echo -e "${QUESTION} Do you want to proceed? (y/n): ")" confirm
        if [[ ! "$confirm" =~ ^[Yy]$ ]]; then
            echo -e "${CROSS} Operation cancelled."
            exit 1
        fi
    fi

    add_subtree "$repo_name" "$repo_url" "$TARGET_DIR" "$BRANCH" "$CREATE_DIR"
    echo -e "\\n${CHECKMARK} Operation completed successfully!"
    exit 0
fi

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
    print_info "Repository Name: $current_repo_name"
    print_info "Local Path: $current_repo_path"
    print_info "Current Branch: $current_branch"
    print_info "Latest Commit: $current_commit"
    print_info "Git User: $current_author ($current_email)"
    
    # Mostra lo stato delle modifiche
    if [[ $(git status --porcelain) ]]; then
        print_warning "Status: Repository has uncommitted changes"
    else
        print_success "Status: Working tree clean"
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
        read -p "$(echo -e "${QUESTION} Do you want to work on this repository? (y/n): ")" use_current
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
                 fzf --prompt="$(echo -e "${PROMPT} Select destination repository: ")" \
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
    echo -e "${ARROW} Adding repository ${repo_name} [branch: ${branch}]"
    echo -e "${ARROW} Destination folder: ${target_dir}\\n"

    # Spinner for the process
    spin() {
        local pid=$1
        local delay=0.1
        local spinstr='⠋⠙⠹⠸⠼⠴⠦⠧⠇⠏'
        while [ "$(ps a | awk '{print $1}' | grep "$pid")" ]; do
            local temp=${spinstr#?}
            printf " ${COLOR_CYAN}%c${COLOR_RESET}  " "$spinstr"
            local spinstr=$temp${spinstr%"$temp"}
            sleep $delay
            printf "\\b\\b\\b\\b"
        done
        printf "    \\b\\b\\b\\b"
    }

    # Add remote repository with error handling
    echo -e "${ARROW} Adding remote..."
    if ! git remote add "$repo_name" "$repo_url" 2>/dev/null; then
        if git remote get-url "$repo_name" >/dev/null 2>&1; then
            echo -e "${WARNING} Remote already exists, updating URL..."
            git remote set-url "$repo_name" "$repo_url"
        else
            echo -e "${CROSS} Failed to add remote"
            return 1
        fi
    fi
    echo -e "${CHECKMARK} Remote added/updated"

    # Fetch remote repository with error handling
    echo -e "${ARROW} Fetching..."
    if ! git fetch "$repo_name" 2>/dev/null; then
        echo -e "${CROSS} Failed to fetch remote repository"
        git remote remove "$repo_name" 2>/dev/null
        return 1
    fi
    echo -e "${CHECKMARK} Fetch completed"

    # Add subtree with multiple attempts
    while [ $attempt -le $max_attempts ]; do
        echo -e "${ARROW} Adding subtree (attempt $attempt of $max_attempts)..."
        
        if perform_subtree_add "$repo_name" "$repo_url" "$target_dir" "$branch" "$create_dir"; then
            echo -e "${CHECKMARK} Subtree added successfully"
            
            # Remove the remote after successful operation
            echo -e "${ARROW} Cleaning up remote..."
            if git remote remove "$repo_name" 2>/dev/null; then
                echo -e "${CHECKMARK} Remote removed"
            else
                echo -e "${WARNING} Could not remove remote"
            fi
            
            print_box "OPERATION COMPLETED"
            echo -e "${CHECKMARK} Repository ${repo_name} successfully added!"
            return 0
        else
            if [[ $(git status --porcelain) ]]; then
                echo -e "${WARNING} Uncommitted changes detected"
                read -p "$(echo -e "${QUESTION} Do you want to stash changes and retry? (y/n): ")" stash_changes
                
                if [[ "$stash_changes" =~ ^[Yy]$ ]]; then
                    echo -e "${ARROW} Stashing changes..."
                    git stash save "Temporary stash for subtree operation"
                    
                    if perform_subtree_add "$repo_name" "$repo_url" "$target_dir" "$branch" "$create_dir"; then
                        echo -e "${CHECKMARK} Subtree added successfully"
                        echo -e "${ARROW} Restoring stashed changes..."
                        git stash pop
                        
                        # Remove the remote after successful operation
                        echo -e "${ARROW} Cleaning up remote..."
                        if git remote remove "$repo_name" 2>/dev/null; then
                            echo -e "${CHECKMARK} Remote removed"
                        else
                            echo -e "${WARNING} Could not remove remote"
                        fi
                        
                        print_box "OPERATION COMPLETED"
                        echo -e "${CHECKMARK} Repository ${repo_name} successfully added!"
                        return 0
                    fi
                fi
            fi
        fi
        
        ((attempt++))
        if [ $attempt -le $max_attempts ]; then
            echo -e "${WARNING} Retrying..."
        fi
    done

    # Remove remote if all attempts failed
    echo -e "${ARROW} Cleaning up remote after failure..."
    git remote remove "$repo_name" 2>/dev/null
    echo -e "${CROSS} Failed to add subtree after $max_attempts attempts"
    return 1
}

# Loop to add multiple repositories
while true; do
    print_box "FOLDER CONFIGURATION"
    read -p "$(echo -e "${QUESTION} Do you want to use a folder? (y/n): ")" use_folder
    
    if [[ "$use_folder" =~ ^[Yy]$ ]]; then
        read -p "$(echo -e "${QUESTION} Do you want to create a new folder? (y/n): ")" create_dir
        
        if [[ "$create_dir" =~ ^[Yy]$ ]]; then
            read -p "$(echo -e "${QUESTION} Enter the new folder name: ")" new_dir
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
                    fzf --prompt="$(echo -e "${PROMPT} Select folder ($current_dir): ")" \
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
                    echo -e "${CROSS} No folder selected. Exiting."
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
               fzf --prompt="$(echo -e "${PROMPT} Select repository: ")" \
                   --preview="tree {} -L 2 -C" \
                   --preview-window=right:50% \
                   --border=rounded \
                   --margin=5% \
                   --padding=5%)
    
    if [ -z "$repo_path" ]; then
        echo -e "${CROSS} No repository selected. Exiting."
        break
    fi

    repo_name=$(basename "$repo_path")
    if [ "$repo_name" == "exit" ]; then
        break
    fi

    repo_url="file://$repo_path"

    print_box "SELECTED REPOSITORY"
    echo -e "${ARROW} Name: ${repo_name}"
    echo -e "${ARROW} Path: ${repo_path}"
    echo -e "${ARROW} URL: ${repo_url}"

    # Salva il percorso della repository corrente
    current_repo_path=$(pwd)
    
    # Cambia alla repository selezionata per controllare le modifiche
    cd "$repo_path" || exit
    
    # Controlla le modifiche non committate nella repository selezionata
    if [[ $(git status --porcelain) ]]; then
        echo -e "${WARNING} WARNING: There are uncommitted changes in the selected repository."
        read -p "$(echo -e "${QUESTION} Do you want to proceed anyway? (y/n): ")" proceed_anyway
        if [[ ! "$proceed_anyway" =~ ^[Yy]$ ]]; then
            echo -e "${CROSS} Operation cancelled. Commit or stash your changes before proceeding."
            cd "$current_repo_path" || exit
            continue
        fi
        echo -e "${ARROW} Proceeding with uncommitted changes..."
    fi
    
    # Torna alla repository originale
    cd "$current_repo_path" || exit

    # Function to display branch commits
    show_commits() {
        local branch=$1
        git log --format="%C(yellow)%h%C(reset) - %C(cyan)%ar%C(reset) - %s" "$branch" | \
        fzf --prompt="$(echo -e "${PROMPT} Commits for branch $branch (← to go back): ")" \
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
                fzf --prompt="$(echo -e "${PROMPT} Select branch: ")" \
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
            echo -e "${CROSS} Branch selection cancelled."
            exit 1
        fi

        if [ -n "$branch" ]; then
            break
        fi
    done
    
    branch=${branch:-main}

    print_box "OPERATIONS SUMMARY"
    if [ "$target_dir" = "." ]; then
        echo -e "${ARROW} Directory: No folder (adding directly)"
    else
        echo -e "${ARROW} Directory: ${target_dir}"
        if [[ "$create_dir" =~ ^[Yy]$ ]]; then
            echo -e "${ARROW} Directory Action: Create new directory"
        fi
    fi
    echo -e "${ARROW} Repository: ${repo_name}"
    echo -e "${ARROW} URL: ${repo_url}"
    echo -e "${ARROW} Branch: ${branch}"
    echo -e "\\n${ARROW}Commands that will be executed:"
    if [ "$target_dir" = "." ]; then
        echo -e "  1. git remote add ${repo_name} ${repo_url}"
        echo -e "  2. git fetch ${repo_name}"
        echo -e "  3. git subtree add --prefix=${repo_name} ${repo_name} ${branch}"
    elif [[ "$create_dir" =~ ^[Yy]$ ]]; then
        echo -e "  1. mkdir -p ${target_dir}"
        echo -e "  2. git remote add ${repo_name} ${repo_url}"
        echo -e "  3. git fetch ${repo_name}"
        echo -e "  4. git subtree add --prefix=${target_dir}/${repo_name} ${repo_name} ${branch}"
    else
        echo -e "  1. git remote add ${repo_name} ${repo_url}"
        echo -e "  2. git fetch ${repo_name}"
        echo -e "  3. git subtree add --prefix=${target_dir}/${repo_name} ${repo_name} ${branch}"
    fi
    
    read -r -p "$(echo -e "\\n${QUESTION} Do you want to proceed with these operations? (y/n): ")" confirm
    if [[ "$confirm" =~ ^[Yy]$ ]]; then
        add_subtree "$repo_name" "$repo_url" "$target_dir" "$branch" "$create_dir"
    else
        echo -e "${CROSS} Operation cancelled."
        continue
    fi

done

echo -e "\\n${CHECKMARK} All operations completed successfully!"
