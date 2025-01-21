# 🎓 School Projects & Utilities

This repository serves as a centralized hub for all my school projects, exercises, and related utilities. 

## 🛠 Utilities

### Git Subtree Manager (`add_subtrees.sh`)

A utility script that simplifies the process of adding Git repositories as subtrees. This is particularly useful for incorporating multiple projects.

#### Features

- Interactive repository selection using `fzf`
- Support for both interactive and non-interactive modes
- Automatic directory management
- Branch selection
- Comprehensive error handling

#### Requirements

- Git
- fzf (for interactive mode)
- Bash shell

#### Installation

1. Clone this repository
2. Make the script executable:
   ```bash
   chmod +x add_subtrees.sh
   ```

#### Usage

1. **Interactive Mode** 
   ```bash
   ./add_subtrees.sh
   ```
   This will guide you through:
   - Selecting the source repository
   - Choosing the destination directory
   - Selecting the branch
   - Confirming operations

2. **Non-Interactive Mode** (Useful for scripts)
   ```bash
   ./add_subtrees.sh -n [-p /path/to/repo] [-d target/dir] [-b branch] [-c] [-s]
   ```
   Available options:
   - `-n, --non-interactive`: Run in non-interactive mode
   - `-p, --path PATH`: Path to repository to add as subtree (if not provided, uses current repository)
   - `-d, --dir DIR`: Destination directory for subtree (optional)
   - `-b, --branch BRANCH`: Branch to use (default: main)
   - `-c, --create-dir`: Create destination directory if it doesn't exist
   - `-s, --stash`: Automatically stash changes when conflicts occur
   - `-h, --help`: Show help message

   Note: If `-p` is not provided, the script will use the current repository. If you're not in a git repository and `-p` is not provided, the script will exit with an error.