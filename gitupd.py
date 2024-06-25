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

def get_local_commit():
    output, _, _ = run_command("git rev-parse HEAD")
    return output

def get_remote_commit(remote_url):
    output, _, _ = run_command(f"git ls-remote {remote_url} HEAD")
    return output.split()[0] if output else None

def clone_repository(remote_url, temp_dir):
    _, _, return_code = run_command(f"git clone {remote_url} {temp_dir}")
    return return_code == 0

def main():
    # Get the current working directory (repository root)
    repo_root = os.getcwd()
    
    # Get the remote URL
    remote_url = get_remote_url()
    if not remote_url:
        print("Error: Unable to get remote URL. Make sure you're in a git repository.")
        return

    # Get the local and remote commit hashes
    local_commit = get_local_commit()
    remote_commit = get_remote_commit(remote_url)

    if not remote_commit:
        print("Error: Unable to fetch remote commit hash.")
        return

    if local_commit == remote_commit:
        print("Local repository is up to date.")
        return

    print("Remote repository is newer. Cloning...")

    # Create a temporary directory for cloning
    with tempfile.TemporaryDirectory() as temp_dir:
        # Clone the repository to the temporary directory
        if not clone_repository(remote_url, temp_dir):
            print("Error: Failed to clone the repository.")
            return

        # Copy the contents of the temp directory to the current directory
        for item in os.listdir(temp_dir):
            s = os.path.join(temp_dir, item)
            d = os.path.join(repo_root, item)
            if os.path.isdir(s):
                shutil.copytree(s, d, dirs_exist_ok=True)
            else:
                shutil.copy2(s, d)

    print("Repository has been successfully updated.")

if __name__ == "__main__":
    main()