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
    return output

def get_remote_refs(remote_url):
    output, _, _ = run_command(f"git ls-remote {remote_url}")
    return output

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