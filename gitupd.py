import subprocess
import sys

def run_command(command):
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    output, error = process.communicate()
    return output.decode('utf-8').strip(), error.decode('utf-8').strip(), process.returncode

def check_and_update_repo():
    print("Fetching latest changes from remote...")
    _, _, return_code = run_command("git fetch")
    if return_code != 0:
        print("Error: Failed to fetch from remote.")
        return

    print("Checking for updates...")
    local_hash, _, _ = run_command("git rev-parse HEAD")
    remote_hash, _, _ = run_command("git rev-parse @{u}")

    if local_hash != remote_hash:
        print("Updates available. Pulling changes...")
        output, error, return_code = run_command("git pull")
        if return_code == 0:
            print("Successfully updated the repository.")
            print(output)
        else:
            print("Error occurred while pulling changes:")
            print(error)
    else:
        print("Local repository is up to date.")

if __name__ == "__main__":
    check_and_update_repo()