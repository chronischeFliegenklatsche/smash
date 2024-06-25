import os
import git
from git import Repo

def clone_if_newer():
    current_dir = os.getcwd()
    
    try:
        repo = Repo(current_dir)
        
        # Fetch the latest changes from the remote
        origin = repo.remotes.origin
        origin.fetch()
        
        # Get the hash of the latest local commit
        local_commit = repo.head.commit.hexsha
        
        # Get the hash of the latest remote commit
        remote_commit = origin.refs[repo.active_branch.name].commit.hexsha
        
        if local_commit != remote_commit:
            print("Remote repository is newer. Cloning...")
            
            # Get the remote URL
            remote_url = origin.url
            
            # Move up one directory
            os.chdir('..')
            
            # Clone the repository
            new_dir = current_dir + '_new'
            Repo.clone_from(remote_url, new_dir)
            
            print(f"Repository cloned to {new_dir}")
            print("Please review the new clone and replace the old directory if desired.")
        else:
            # Check for any differences between local and remote
            diff = repo.git.diff('HEAD', f'origin/{repo.active_branch.name}')
            if diff:
                print("Remote repository has changes. Cloning...")
                # Perform cloning as before
                remote_url = origin.url
                os.chdir('..')
                new_dir = current_dir + '_new'
                Repo.clone_from(remote_url, new_dir)
                print(f"Repository cloned to {new_dir}")
                print("Please review the new clone and replace the old directory if desired.")
            else:
                print("Local repository is up to date. No action needed.")
    
    except git.exc.InvalidGitRepositoryError:
        print("This directory is not a valid Git repository.")
    except Exception as e:
        print(f"An error occurred: {str(e)}")

if __name__ == "__main__":
    clone_if_newer()