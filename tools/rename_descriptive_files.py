import os, sys, json, subprocess

# Exact map of file basenames to clear, meaningful names describing what the function does and why it exists
FILE_RENAME_MAP = {
    'msl_runtime_02336710.cpp': ('VRAM_GetEngineBBaseAddr.cpp', 'FUN_02336710', 'VRAM_GetEngineBBaseAddr'),
    'msl_runtime_02332884.cpp': ('EXMEM_GetAndResetConfig.cpp', 'FUN_02332884', 'EXMEM_GetAndResetConfig'),
    'msl_runtime_02332df4.cpp': ('memcpy_bytes.cpp', 'FUN_02332df4', 'memcpy_bytes'),
    'msl_runtime_02332e38.cpp': ('memcmp.cpp', 'FUN_02332e38', 'memcmp'),
    'strlen_02332e1c.cpp': ('memchr.cpp', 'FUN_02332e1c', 'memchr'),
    'msl_runtime_02334584.cpp': ('strlen_s8.cpp', 'FUN_02334584', 'strlen_s8'),
    'msl_runtime_023345fc.cpp': ('wcslen.cpp', 'FUN_023345fc', 'wcslen'),
    'msl_runtime_02336444.cpp': ('SetPacketHeader.cpp', 'FUN_02336444', 'SetPacketHeader'),
    'msl_stub_02332d10.cpp': ('SVC_WaitByLoop.cpp', 'FUN_02332d10', 'SVC_WaitByLoop'),
    'msl_stub_02332d2e.cpp': ('SVC_CpuSet.cpp', 'FUN_02332d2e', 'SVC_CpuSet'),
    'msl_stub_02332d32.cpp': ('SVC_FastCopy.cpp', 'FUN_02332d32', 'SVC_FastCopy'),
    'msl_stub_02332d3a.cpp': ('SVC_GetCRC16.cpp', 'FUN_02332d3a', 'SVC_GetCRC16'),
    'msl_stub_02332d42.cpp': ('SVC_IsDebuggerPresent.cpp', 'FUN_02332d42', 'SVC_IsDebuggerPresent'),
    'msl_stub_02332d4e.cpp': ('SVC_CustomCall.cpp', 'FUN_02332d4e', 'SVC_CustomCall'),
    'msl_stub_02332d84.cpp': ('SafeStoreByte.cpp', 'FUN_02332d84', 'SafeStoreByte'),
    'msl_stub_023371d8.cpp': ('SetGlobalStateByte.cpp', 'FUN_023371d8', 'SetGlobalStateByte'),
    'msl_stub_023381a8.cpp': ('GetContextField14.cpp', 'FUN_023381a8', 'GetContextField14'),
    'msl_runtime_02332c68.cpp': ('InvokeSystemCallback.cpp', 'FUN_02332c68', 'InvokeSystemCallback'),
    'msl_runtime_02332e38.cpp': ('memcmp.cpp', 'FUN_02332e38', 'memcmp'),
}

src_dir = r'src\arm9'
syms_file = r'config\arm9\symbols.txt'
classified_file = r'config\arm9\classified_symbols.json'

print("Renaming source files to precise functional names...")

# 1. Update config/arm9/symbols.txt
with open(syms_file, 'r') as f:
    lines = f.readlines()

new_lines = []
for line in lines:
    for old_file, (new_file, old_func, new_func) in FILE_RENAME_MAP.items():
        if f"name={old_func} " in line:
            line = line.replace(f"name={old_func} ", f"name={new_func} ")
    new_lines.append(line)

with open(syms_file, 'w') as f:
    f.writelines(new_lines)
print(f"Updated {syms_file}")

# 2. Update config/arm9/classified_symbols.json
with open(classified_file, 'r') as f:
    classified_data = json.load(f)

for s in classified_data:
    for old_file, (new_file, old_func, new_func) in FILE_RENAME_MAP.items():
        if s['name'] == old_func:
            s['name'] = new_func

with open(classified_file, 'w') as f:
    json.dump(classified_data, f, indent=2)
print(f"Updated {classified_file}")

# 3. Rename files in src/arm9 and update internal function name inside file
for old_file, (new_file, old_func, new_func) in FILE_RENAME_MAP.items():
    old_path = os.path.join(src_dir, old_file)
    new_path = os.path.join(src_dir, new_file)

    if os.path.exists(old_path):
        # Update function name inside file content
        with open(old_path, 'r') as f:
            content = f.read()

        content = content.replace(f"name={old_func}", f"name={new_func}")
        content = content.replace(f"{old_func}(", f"{new_func}(")

        with open(old_path, 'w') as f:
            f.write(content)

        # Git rename
        subprocess.run(['git', 'mv', old_path, new_path], check=True)
        print(f"  git mv {old_file} -> {new_file} (function: {new_func})")

# 4. Regenerate build.ninja
subprocess.run([sys.executable, 'configure.py'], check=True)
print("Re-ran configure.py successfully!")
