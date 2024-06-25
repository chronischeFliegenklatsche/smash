import os
import subprocess

def run_command(command):
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    output, error = process.communicate()
    return output.decode('utf-8').strip(), error.decode('utf-8').strip()

def clone_if_newer():
    current_dir = os.getcwd()
    
    try:
        # Fetch the latest changes from the remote
        _, error = run_command("git fetch")
        if error:
            print(f"Error fetching from remote: {error}")
            return

        # Get the name of the current branch
        branch, error = run_command("git rev-parse --abbrev-ref HEAD")
        if error:
            print(f"Error getting current branch: {error}")
            return

        # Check if there are any differences between local and remote
        diff, error = run_command(f"git diff HEAD origin/{branch}")
        if error:
            print(f"Error checking for differences: {error}")
            return

        if diff:
            print("Remote repository has changes. Cloning...")
            
            # Get the remote URL
            remote_url, error = run_command("git config --get remote.origin.url")
            if error:
                print(f"Error getting remote URL: {error}")
                return

            # Move up one directory
            os.chdir('..')
            
            # Clone the repository
            new_dir = os.path.basename(current_dir) + '_new'
            output, error = run_command(f"git clone {remote_url} {new_dir}")
            if error:
                print(f"Error cloning repository: {error}")
                return

            print(f"Repository cloned to {new_dir}")
            print("Please review the new clone and replace the old directory if desired.")
        else:
            print("Local repository is up to date. No action needed.")

    except Exception as e:
        print(f"An error occurred: {str(e)}")

if __name__ == "__main__":
    clone_if_newer()