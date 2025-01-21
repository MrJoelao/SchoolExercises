#!/bin/bash

# Color and symbol constants
readonly C_BLUE="\\e[1;36m"
readonly C_GREEN="\\e[1;32m"
readonly C_YELLOW="\\e[1;33m"
readonly C_RED="\\e[1;31m"
readonly C_RESET="\\e[0m"

readonly ARROW="${C_BLUE}➜${C_RESET}"
readonly CHECK="${C_GREEN}✓${C_RESET}"
readonly WARN="${C_YELLOW}⚠${C_RESET}"
readonly ERROR="${C_RED}✘${C_RESET}"
readonly QUESTION="${C_YELLOW}??${C_RESET}"
readonly PROMPT="${C_BLUE}⟫${C_RESET}"

# Additional flags for non-interactive mode
STASH_ON_CONFLICT=false
USE_CURRENT_REPO=false

# Helper functions for common operations
print_success() {
    echo -e "${CHECK} $1"
}

print_error() {
    echo -e "${ERROR} $1"
}

print_warning() {
    echo -e "${WARN} $1"
}

print_info() {
    echo -e "${ARROW} $1"
}

print_prompt() {
    echo -e "${PROMPT} $1"
}

ask_question() {
    read -p "$(echo -e "${QUESTION} $1: ")" response
    echo "$response"
}

# Function to print colored boxes
print_box() {
    local text="$1"
    local width=60
    local padding=$(( (width - ${#text}) / 2 ))
    
    echo -e "${C_BLUE}┌$( printf '─%.0s' $(seq 1 $width) )┐"
    echo -e "│$( printf ' %.0s' $(seq 1 $padding) )$text$( printf ' %.0s' $(seq 1 $((width - ${#text} - padding))) )│"
    echo -e "└$( printf '─%.0s' $(seq 1 $width) )┘${C_RESET}"
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
SKIP_REPO_PROMPT=false
NON_INTERACTIVE=false
REPO_PATH=""
TARGET_DIR=""
BRANCH=""
CREATE_DIR=false

# Show help
show_help() {
    cat << EOF
$(print_box "Git Subtree Manager")

A utility script that simplifies adding Git repositories as subtrees.

USAGE
    Interactive Mode:
        $0
    
    Non-Interactive Mode:
        $0 -n [-p /path/to/repo] [-d target/dir] [-b branch] [-c] [-s]

OPTIONS
    -n, --non-interactive    Run script without user interaction
    -p, --path PATH         Path to repository to add as subtree
                           (if not provided, uses current repository)
    -d, --dir DIR          Destination directory for subtree
    -b, --branch BRANCH    Branch to use (default: main)
    -c, --create-dir       Create destination directory if it doesn't exist
    -s, --stash           Automatically stash changes when conflicts occur
    -h, --help            Show this help message

EXAMPLE
    Add a repository as subtree in a specific directory with auto-stash:
        $0 -n -p ~/projects/myrepo -d libs/mylib -b develop -s -c

NOTE: If -p is not provided, the script will use the current repository.
      If you're not in a git repository and -p is not provided, the script will exit with an error.
EOF
    exit 1
}

# Parse both short and long options
TEMP=$(getopt -o 'nyp:d:b:chs' --long 'non-interactive,yes,path:,dir:,branch:,create-dir,help,stash,use-current' -n "$0" -- "$@")

if [ $? -ne 0 ]; then
    echo -e "${ERROR} Error: Invalid options"
    show_help
fi

eval set -- "$TEMP"
unset TEMP

while true; do
    case "$1" in
        '-n'|'--non-interactive')
            NON_INTERACTIVE=true
            shift
            continue
            ;;
        '-y'|'--yes')
            SKIP_REPO_PROMPT=true
            shift
            continue
            ;;
        '-p'|'--path')
            REPO_PATH="$2"
            shift 2
            continue
            ;;
        '-d'|'--dir')
            TARGET_DIR="$2"
            shift 2
            continue
            ;;
        '-b'|'--branch')
            BRANCH="$2"
            shift 2
            continue
            ;;
        '-c'|'--create-dir')
            CREATE_DIR=true
            shift
            continue
            ;;
        '-h'|'--help')
            show_help
            ;;
        '-s'|'--stash')
            STASH_ON_CONFLICT=true
            shift
            continue
            ;;
        '--use-current')
            USE_CURRENT_REPO=true
            shift
            continue
            ;;
        '--')
            shift
            break
            ;;
        *)
            echo -e "${ERROR} Error: Internal error!"
            exit 1
            ;;
    esac
done

# Validate non-interactive mode requirements
if [ "$NON_INTERACTIVE" = true ]; then
    if [ -z "$REPO_PATH" ]; then
        echo -e "${ERROR} Error: Non-interactive mode requires -p/--path REPO_PATH"
        show_help
    fi
fi

# Check if dependencies are installed
for cmd in fzf; do
    if ! command -v "$cmd" &> /dev/null; then
        echo "Make sure you have '$cmd' installed."
        exit 1
    fi
done

# Show current repository information
current_repo_path=$(git rev-parse --show-toplevel 2>/dev/null)
current_repo_name=$(basename "$current_repo_path" 2>/dev/null)
current_branch=$(git rev-parse --abbrev-ref HEAD 2>/dev/null)
current_commit=$(git rev-parse --short HEAD 2>/dev/null)
current_author=$(git config user.name 2>/dev/null)
current_email=$(git config user.email 2>/dev/null)

if [ -n "$current_repo_name" ]; then
    print_box "CURRENT REPOSITORY"
    echo -e "${ARROW} Repository Name: ${C_GREEN}$current_repo_name${C_RESET}"
    echo -e "${ARROW} Local Path: ${C_GREEN}$current_repo_path${C_RESET}"
    echo -e "${ARROW} Current Branch: ${C_GREEN}$current_branch${C_RESET}"
    echo -e "${ARROW} Latest Commit: ${C_GREEN}$current_commit${C_RESET}"
    echo -e "${ARROW} Git User: ${C_GREEN}$current_author ($current_email)${C_RESET}"
    
    # Mostra lo stato delle modifiche
    if [[ $(git status --porcelain) ]]; then
        echo -e "${ARROW} Status: ${C_YELLOW}Repository has uncommitted changes${C_RESET}"
    else
        echo -e "${ARROW} Status: ${C_GREEN}Working tree clean${C_RESET}"
    fi
    
    # Mostra informazioni sui remote
    echo -e "${ARROW} Remote URLs:"
    git remote -v | awk '!seen[$0]++' | sed 's/^/  /'
    
    # Mostra numero di branch
    branch_count=$(git branch | wc -l)
    echo -e "${ARROW} Branches: ${C_GREEN}$branch_count total${C_RESET}"
    
    # Mostra ultimi 3 commit
    echo -e "${ARROW} Recent Commits:"
    git log -3 --pretty=format:"  %C(yellow)%h%Creset - %s %C(cyan)(%cr)%Creset" --abbrev-commit
    echo -e "\\n"
    
    # Se è stato fornito un REPO_PATH, usa quello
    if [ -n "$REPO_PATH" ]; then
        use_current="n"
    else
        # Se non è stato fornito un REPO_PATH, usa la repository corrente
        echo -e "${ARROW} Using current repository (auto-selected)\\n"
        use_current="y"
    fi

    if [[ "$use_current" =~ ^[Yy]$ ]]; then
        cd "$current_repo_path" || exit
    fi
else
    echo -e "${ERROR} You are not in a git repository."
    # Se non siamo in una repository, richiedi REPO_PATH
    if [ -z "$REPO_PATH" ]; then
        echo -e "${ERROR} No repository path provided and not in a git repository."
        exit 1
    fi
    use_current="n"
fi

if [[ ! "$use_current" =~ ^[Yy]$ ]]; then
    # Se è stato fornito un REPO_PATH, usalo
    if [ -n "$REPO_PATH" ]; then
        if [ ! -d "$REPO_PATH" ]; then
            echo -e "${ERROR} Repository path does not exist: $REPO_PATH"
            exit 1
        fi
        target_repo="$REPO_PATH"
    else
        # Altrimenti usa la selezione interattiva
        print_box "REPOSITORY SELECTION"
        echo "${PROMPT} Select a repository to work on:"
        target_repo=$(find ~ -name ".git" -type d -prune 2>/dev/null | sed 's/\/.git$//' | \
                     fzf --prompt="${PROMPT} Select destination repository: " \
                         --border=rounded \
                         --margin=5% \
                         --padding=5%)
        
        if [ -z "$target_repo" ]; then
            echo -e "${ERROR} No repository selected. Exiting."
            exit 1
        fi
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
        echo -e "${ARROW} Creating directory $target_dir..."
        if ! mkdir -p "$target_dir"; then
            echo -e "${ERROR} Failed to create directory"
            return 1
        fi
        echo -e "${CHECK} Directory created\\n"
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
    print_info "Adding repository ${C_YELLOW}$repo_name${C_RESET} [branch: ${C_YELLOW}$branch${C_RESET}]"
    print_info "Destination folder: ${C_YELLOW}$target_dir${C_RESET}\\n"

    # Spinner for the process
    spin() {
        local pid=$1
        local delay=0.1
        local spinstr='⠋⠙⠹⠸⠼⠴⠦⠧⠇⠏'
        while [ "$(ps a | awk '{print $1}' | grep "$pid")" ]; do
            local temp=${spinstr#?}
            printf " ${C_BLUE}%c${C_RESET}  " "$spinstr"
            local spinstr=$temp${spinstr%"$temp"}
            sleep $delay
            printf "\\b\\b\\b\\b"
        done
        printf "    \\b\\b\\b\\b"
    }

    # Add remote repository with error handling
    print_info "Adding remote..."
    if ! git remote add "$repo_name" "$repo_url" 2>/dev/null; then
        if git remote get-url "$repo_name" >/dev/null 2>&1; then
            print_warning "Remote already exists, updating URL..."
            git remote set-url "$repo_name" "$repo_url"
        else
            print_error "Failed to add remote"
            return 1
        fi
    fi
    print_success "Remote added/updated\\n"

    # Fetch remote repository with error handling
    print_info "Fetching..."
    if ! git fetch "$repo_name" 2>/dev/null; then
        print_error "Failed to fetch remote repository"
        git remote remove "$repo_name" 2>/dev/null
        return 1
    fi
    print_success "Fetch completed\\n"

    # Add subtree with multiple attempts
    while [ $attempt -le $max_attempts ]; do
        print_info "Adding subtree (attempt $attempt of $max_attempts)..."
        
        if perform_subtree_add "$repo_name" "$repo_url" "$target_dir" "$branch" "$create_dir"; then
            print_success "Subtree added successfully\\n"
            
            # Remove the remote after successful operation
            print_info "Cleaning up remote..."
            if git remote remove "$repo_name" 2>/dev/null; then
                print_success "Remote removed\\n"
            else
                print_warning "Could not remove remote\\n"
            fi
            
            print_box "OPERATION COMPLETED"
            print_success "Repository ${C_YELLOW}$repo_name${C_RESET} successfully added!"
            return 0
        else
            if [[ $(git status --porcelain) ]]; then
                print_warning "Uncommitted changes detected"
                if [ "$NON_INTERACTIVE" = true ]; then
                    if [ "$STASH_ON_CONFLICT" = true ]; then
                        print_info "Automatically stashing changes..."
                        git stash save "Temporary stash for subtree operation"
                        # ... resto del codice per lo stash
                    else
                        print_error "Working tree has modifications. Cannot add."
                        return 1
                    fi
                else
                    read -p "$(echo -e "${PROMPT} Do you want to stash changes and retry? (y/n): ")" stash_changes
                    
                    if [[ "$stash_changes" =~ ^[Yy]$ ]]; then
                        print_info "Stashing changes..."
                        git stash save "Temporary stash for subtree operation"
                        
                        if perform_subtree_add "$repo_name" "$repo_url" "$target_dir" "$branch" "$create_dir"; then
                            print_success "Subtree added successfully"
                            print_info "Restoring stashed changes..."
                            git stash pop
                            
                            # Remove the remote after successful operation
                            print_info "Cleaning up remote..."
                            if git remote remove "$repo_name" 2>/dev/null; then
                                print_success "Remote removed\\n"
                            else
                                print_warning "Could not remove remote\\n"
                            fi
                            
                            print_box "OPERATION COMPLETED"
                            print_success "Repository ${C_YELLOW}$repo_name${C_RESET} successfully added!"
                            return 0
                        fi
                    fi
                fi
            fi
        fi
        
        ((attempt++))
        if [ $attempt -le $max_attempts ]; then
            print_warning "Retrying...\\n"
        fi
    done

    # Remove remote if all attempts failed
    print_info "Cleaning up remote after failure..."
    git remote remove "$repo_name" 2>/dev/null
    print_error "Failed to add subtree after $max_attempts attempts"
    return 1
}

# Modify the main logic to handle non-interactive mode first
if [ "$NON_INTERACTIVE" = true ]; then
    if [ -z "$TARGET_DIR" ]; then
        TARGET_DIR="."
    fi
    
    if [ ! -d "$REPO_PATH" ]; then
        echo -e "${ERROR} Error: Repository path does not exist: $REPO_PATH"
        exit 1
    fi
    
    repo_name=$(basename "$REPO_PATH")
    repo_url="file://$REPO_PATH"
    branch=${BRANCH:-main}
    
    print_box "OPERATIONS SUMMARY"
    echo -e "${ARROW} Directory: ${C_GREEN}$TARGET_DIR${C_RESET}"
    echo -e "${ARROW} Repository: ${C_GREEN}$repo_name${C_RESET}"
    echo -e "${ARROW} URL: ${C_GREEN}$repo_url${C_RESET}"
    echo -e "${ARROW} Branch: ${C_GREEN}$branch${C_RESET}"
    
    add_subtree "$repo_name" "$repo_url" "$TARGET_DIR" "$branch" "$CREATE_DIR"
    echo -e "\\n${ARROW} Operation completed!"
    exit 0
fi

# Interactive mode loop (il resto del codice esistente)
while true; do
    print_box "FOLDER CONFIGURATION"
    read -p "$(echo -e "${PROMPT} Do you want to use a folder? (y/n): ")" use_folder
    
    if [[ "$use_folder" =~ ^[Yy]$ ]]; then
        read -p "$(echo -e "${PROMPT} Do you want to create a new folder? (y/n): ")" create_dir
        
        if [[ "$create_dir" =~ ^[Yy]$ ]]; then
            read -p "$(echo -e "${PROMPT} Enter the new folder name: ")" new_dir
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
                    fzf --prompt="${PROMPT} Select folder ($current_dir): " \
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
                    echo -e "${ERROR} No folder selected. Exiting."
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
    echo "${PROMPT} Select local repository:"
    repo_path=$(find ~ -name ".git" -type d -prune 2>/dev/null | sed 's/\/.git$//' | \
               fzf --prompt="${PROMPT} Select repository: " \
                   --preview="tree {} -L 2 -C" \
                   --preview-window=right:50% \
                   --border=rounded \
                   --margin=5% \
                   --padding=5%)
    
    if [ -z "$repo_path" ]; then
        echo -e "${ERROR} No repository selected. Exiting."
        break
    fi

    repo_name=$(basename "$repo_path")
    if [ "$repo_name" == "exit" ]; then
        break
    fi

    repo_url="file://$repo_path"

    print_box "SELECTED REPOSITORY"
    echo -e "${ARROW} Name: ${C_GREEN}$repo_name${C_RESET}"
    echo -e "${ARROW} Path: ${C_GREEN}$repo_path${C_RESET}"
    echo -e "${ARROW} URL: ${C_GREEN}$repo_url${C_RESET}"

    # Salva il percorso della repository corrente
    current_repo_path=$(pwd)
    
    # Cambia alla repository selezionata per controllare le modifiche
    cd "$repo_path" || exit
    
    # Controlla le modifiche non committate nella repository selezionata
    if [[ $(git status --porcelain) ]]; then
        echo -e "${WARN} WARNING: There are uncommitted changes in the selected repository."
        read -p "$(echo -e "${PROMPT} Do you want to proceed anyway? (y/n): ")" proceed_anyway
        if [[ ! "$proceed_anyway" =~ ^[Yy]$ ]]; then
            echo -e "${ERROR} Operation cancelled. Commit or stash your changes before proceeding."
            cd "$current_repo_path" || exit
            continue
        fi
        echo -e "${ARROW} Proceeding with uncommitted changes..."
        echo -e "${ARROW} Proceeding with uncommitted changes..."
    fi
    
    # Torna alla repository originale
    cd "$current_repo_path" || exit

    # Function to display branch commits
    show_commits() {
        local branch=$1
        git log --format="%C(yellow)%h%C(reset) - %C(cyan)%ar%C(reset) - %s" "$branch" | \
        fzf --prompt="${PROMPT} Commits for branch $branch (← to go back): " \
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
                fzf --prompt="${PROMPT} Select branch: " \
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
            echo -e "${ERROR} Branch selection cancelled."
            exit 1
        fi

        if [ -n "$branch" ]; then
            break
        fi
    done
    
    branch=${branch:-main}

    print_box "OPERATIONS SUMMARY"
    if [ "$target_dir" = "." ]; then
        echo -e "${ARROW} Directory: ${C_GREEN}No folder (adding directly)${C_RESET}"
    else
        echo -e "${ARROW} Directory: ${C_GREEN}$target_dir${C_RESET}"
        if [[ "$create_dir" =~ ^[Yy]$ ]]; then
            echo -e "${ARROW} Directory Action: ${C_GREEN}Create new directory${C_RESET}"
        fi
    fi
    echo -e "${ARROW} Repository: ${C_GREEN}$repo_name${C_RESET}"
    echo -e "${ARROW} URL: ${C_GREEN}$repo_url${C_RESET}"
    echo -e "${ARROW} Branch: ${C_GREEN}$branch${C_RESET}"
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
    
    read -r -p "$(echo -e "${PROMPT} Do you want to proceed with these operations? (y/n): ")" confirm
    if [[ "$confirm" =~ ^[Yy]$ ]]; then
        add_subtree "$repo_name" "$repo_url" "$target_dir" "$branch" "$create_dir"
    else
        echo -e "${ERROR} Operation cancelled."
        continue
    fi

done

echo -e "\\n${ARROW} All operations completed successfully!"
