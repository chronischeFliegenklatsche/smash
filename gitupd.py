import subprocess

def run_command(command):
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    output, error = process.communicate()
    return output.decode('utf-8').strip(), error.decode('utf-8').strip(), process.returncode

def check_and_update_repo():
    print("Fetching latest changes from remote...")
    fetch_output, fetch_error, fetch_return_code = run_command("git fetch")
    if fetch_return_code != 0:
        print("Error: Failed to fetch from remote.")
        print(fetch_error)
        return

    print("Checking for updates...")
    local_hash, local_error, local_return_code = run_command("git rev-parse HEAD")
    if local_return_code != 0:
        print("Error: Failed to get local HEAD.")
        print(local_error)
        return

    remote_hash, remote_error, remote_return_code = run_command("git rev-parse @{u}")
    if remote_return_code != 0:
        print("Error: Failed to get remote HEAD.")
        print(remote_error)
        return

    print(f"Local HEAD: {local_hash}")
    print(f"Remote HEAD: {remote_hash}")

    if local_hash != remote_hash:
        print("Updates available. Pulling changes...")
        pull_output, pull_error, pull_return_code = run_command("git pull")
        if pull_return_code == 0:
            print("Successfully updated the repository.")
            print(pull_output)
        else:
            print("Error occurred while pulling changes:")
            print(pull_error)
    else:
        print("Local repository is up to date.")

if __name__ == "__main__":
    check_and_update_repo()