import os
import subprocess
import sys

def run_command(command):
    try:
        result = subprocess.run(command, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        return result.stdout.strip()
    except subprocess.CalledProcessError as e:
        print(f"Error executing command: {e}")
        print(f"Error output: {e.stderr}")
        sys.exit(1)

def get_current_branch():
    return run_command(["git", "rev-parse", "--abbrev-ref", "HEAD"])

def is_repo_clean():
    status = run_command(["git", "status", "--porcelain"])
    return len(status) == 0

def fetch_remote():
    run_command(["git", "fetch", "origin"])

def get_local_commit():
    return run_command(["git", "rev-parse", "HEAD"])

def get_remote_commit(branch):
    return run_command(["git", "rev-parse", f"origin/{branch}"])

def pull_changes():
    run_command(["git", "pull", "origin"])

def main():
    # Check if we're inside a git repository
    if not os.path.exists(".git"):
        print("This script must be run from the root of a git repository.")
        print("Please navigate to the root directory of your Git repository and run the script again.")
        sys.exit(1)

    # Get current branch
    current_branch = get_current_branch()

    # Check if the repository is clean
    if not is_repo_clean():
        print("The repository has uncommitted changes. Please commit or stash them before running this script.")
        sys.exit(1)

    # Fetch the latest changes from remote
    print("Fetching latest changes from remote...")
    fetch_remote()

    # Get local and remote commit hashes
    local_commit = get_local_commit()
    remote_commit = get_remote_commit(current_branch)

    # Compare local and remote commits
    if local_commit != remote_commit:
        print(f"Remote version is newer. Pulling changes for branch '{current_branch}'...")
        pull_changes()
        print("Repository updated successfully.")
    else:
        print("Local repository is up to date.")

if __name__ == "__main__":
    os.chdir(os.path.dirname(os.path.abspath(__file__)))
    main()