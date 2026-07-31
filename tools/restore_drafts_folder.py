import os, subprocess, sys

print("Restoring all non-matching candidate drafts into dedicated 'drafts/' directory...\n")

# Get list of files deleted in previous commit (1309fd4 or HEAD)
res = subprocess.run(['git', 'diff-tree', '--no-commit-id', '--name-only', '-r', 'HEAD'], capture_output=True, text=True, check=True)
deleted_files = [line.strip() for line in res.stdout.splitlines() if line.startswith('src/')]

draft_count = 0

for file_path in deleted_files:
    if not file_path.endswith('.cpp'): continue
    # Compute corresponding drafts path
    draft_path = file_path.replace('src/', 'drafts/', 1)
    draft_dir = os.path.dirname(draft_path)

    os.makedirs(draft_dir, exist_ok=True)

    # Restore content from parent commit HEAD~1
    show_res = subprocess.run(['git', 'show', f'HEAD~1:{file_path}'], capture_output=True, text=True)
    if show_res.returncode == 0:
        with open(draft_path, 'w') as f:
            f.write(show_res.stdout)
        draft_count += 1

print(f"Restored {draft_count} non-matching candidate drafts into drafts/ directory!")

# Stage drafts directory
subprocess.run(['git', 'add', 'drafts/'], check=True)

# Re-run configure.py
subprocess.run([sys.executable, 'configure.py'], check=True)
print("Re-ran configure.py successfully!")
