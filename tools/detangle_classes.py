import os, sys, subprocess, json

# Class consolidation plan mapping class names to member function filenames
CLASS_CONSOLIDATION_PLAN = {
    'VRAM': [
        'VRAM_GetEngineBBaseAddr.cpp'
    ],
    'EXMEM': [
        'EXMEM_GetAndResetConfig.cpp'
    ],
    'PacketHeader': [
        'SetPacketHeader.cpp'
    ],
    'SVC': [
        'SVC_WaitByLoop.cpp',
        'SVC_CpuSet.cpp',
        'SVC_FastCopy.cpp',
        'SVC_GetCRC16.cpp',
        'SVC_IsDebuggerPresent.cpp',
        'SVC_CustomCall.cpp'
    ],
    'ChatContext': [
        'GetContextField14.cpp',
        'InvokeSystemCallback.cpp'
    ],
    'IRQ': [
        '_ZN3IRQ7DisableEv_02332080.cpp',
        '_ZN3IRQ7RestoreEj_02332094.cpp',
        '_ZN3IRQ10DisableAllEv_023320ac.cpp',
        '_ZN3IRQ10RestoreAllEj_023320c0.cpp',
        '_ZN3IRQ6EnableEv.cpp'
    ],
    'CP15': [
        '_ZN4CP159EnableMPUEv.cpp',
        '_ZN4CP1510DisableMPUEv.cpp',
        '_ZN4CP1514FlushDataCacheEv.cpp',
        '_ZN4CP1514FlushDataCacheEjj.cpp',
        '_ZN4CP1516DrainWriteBufferEv.cpp',
        '_ZN4CP1516WaitForInterruptEv.cpp',
        '_ZN4CP1519InvalidateDataCacheEjj.cpp'
    ],
    'MultiCopy': [
        'MultiCopy32Bytes.cpp',
        'MultiCopyHalf.cpp',
        'MultiCopy_Int.cpp',
        'MultiStore16.cpp',
        'MultiStore32Bytes.cpp',
        'MultiStore_Int_02000d3c.cpp',
        'MultiStore_Int_02337440.cpp'
    ]
}

src_dir = r'src\arm9'

print("Detangling functions into clean C++ Class Files...")

for class_name, files in CLASS_CONSOLIDATION_PLAN.items():
    existing_files = [f for f in files if os.path.exists(os.path.join(src_dir, f))]
    if not existing_files:
        print(f"Skipping {class_name}: no files exist")
        continue

    target_class_file = os.path.join(src_dir, f"{class_name}.cpp")
    content_blocks = []
    content_blocks.append(f"// ==========================================================\n")
    content_blocks.append(f"// C++ Class Implementation: {class_name}\n")
    content_blocks.append(f"// ==========================================================\n\n")

    for f in existing_files:
        path = os.path.join(src_dir, f)
        with open(path, 'r') as fp:
            file_text = fp.read().strip()
        content_blocks.append(f"// --- {f} ---\n{file_text}\n\n")

    # Write consolidated class file
    with open(target_class_file, 'w') as fp:
        fp.write(''.join(content_blocks))
    print(f"Created consolidated class file: src/arm9/{class_name}.cpp ({len(existing_files)} methods)")

    # Remove individual fragmented files via git rm
    for f in existing_files:
        path = os.path.join(src_dir, f)
        if os.path.abspath(path) != os.path.abspath(target_class_file):
            subprocess.run(['git', 'rm', '-f', path], check=True)
            print(f"  git rm {f}")

    # Stage new class file
    subprocess.run(['git', 'add', target_class_file], check=True)

# Re-run configure.py
subprocess.run([sys.executable, 'configure.py'], check=True)
print("\nRe-ran configure.py successfully!")
