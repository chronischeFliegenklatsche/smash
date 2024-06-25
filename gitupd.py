import os
import subprocess
import shutil
import tempfile

def run_command(command):
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    output, error = process.communicate()
    return output.decode('utf-8').strip(), error.decode('utf-8').strip(), process.returncode

def get_remote_url():
    output, _, _ = run_command("git config --get remote.origin.url")
    return output

def get_local_refs():
    output, _, _ = run_command("git show-ref")
    return set(line.split()[0] for line in output.splitlines() if not line.endswith('/HEAD'))

def get_remote_refs(remote_url):
    output, _, _ = run_command(f"git ls-remote {remote_url}")
    return set(line.split()[0] for line in output.splitlines() if not line.endswith('/HEAD'))

def pull_repository():
    _, _, return_code = run_command("git pull")
    return return_code == 0

def main():
    # Get the current working directory (repository root)
    repo_root = os.getcwd()
    
    # Get the remote URL
    remote_url = get_remote_url()
    if not remote_url:
        print("Error: Unable to get remote URL. Make sure you're in a git repository.")
        return

    print(f"Remote URL: {remote_url}")

    # Fetch the latest changes from remote
    print("Fetching latest changes from remote...")
    run_command("git fetch")

    # Get the local and remote refs
    local_refs = get_local_refs()
    remote_refs = get_remote_refs(remote_url)

    print("Local refs:")
    print(local_refs)
    print("\nRemote refs:")
    print(remote_refs)

    if local_refs == remote_refs:
        print("Local repository is up to date.")
        return

    print("Remote repository has changes. Updating local repository...")

    # Pull the latest changes
    if pull_repository():
        print("Repository has been successfully updated.")
    else:
        print("Error: Failed to update the repository.")

if __name__ == "__main__":
    main()