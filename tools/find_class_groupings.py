import os, re, json

src_dir = r'src\arm9'
files = sorted([f for f in os.listdir(src_dir) if f.endswith('.cpp')])

print(f"Analyzing {len(files)} 100% byte-matched source files in {src_dir} for C++ class groupings:\n")

with open(r'config\arm9\symbols.txt', 'r') as sf:
    syms_text = sf.read()

functions_info = []

for f in files:
    path = os.path.join(src_dir, f)
    with open(path, 'r') as fp:
        content = fp.read()

    m = re.search(r'addr=(0x[0-9a-fA-F]+)\s+name=(\S+)', content)
    if m:
        addr_str = m.group(1)
        name_str = m.group(2)
        addr_int = int(addr_str, 16)
        functions_info.append({
            'file': f,
            'name': name_str,
            'addr_str': addr_str,
            'addr_int': addr_int,
            'content': content
        })

# Sort by address
functions_info.sort(key=lambda x: x['addr_int'])

# Group contiguous function blocks (within 0x100 bytes of each other)
clusters = []
curr_cluster = []

for info in functions_info:
    if not curr_cluster:
        curr_cluster.append(info)
    else:
        prev = curr_cluster[-1]
        if info['addr_int'] - prev['addr_int'] <= 0x100:
            curr_cluster.append(info)
        else:
            clusters.append(curr_cluster)
            curr_cluster = [info]

if curr_cluster:
    clusters.append(curr_cluster)

print(f"Found {len(clusters)} contiguous C++ class clusters across {len(functions_info)} matching functions:\n")

for idx, cl in enumerate(clusters):
    if len(cl) > 1:
        addr_range = f"{cl[0]['addr_str']} - {cl[-1]['addr_str']}"
        print(f"=== Cluster {idx+1}: {len(cl)} methods ({addr_range}) ===")
        for item in cl:
            print(f"   {item['file']} ({item['name']} @ {item['addr_str']})")
        print("-" * 50)
