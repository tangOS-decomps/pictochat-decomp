import os, sys, subprocess, json, re

# Class declarations and symbol mappings
CPP_CLASS_FILES = {
    'src/arm9/PaletteColorEngine.cpp': {
        'symbols': {
            '_ZN18PaletteColorEngine10InitBoundsEv': ('0x0232517c', '0xc'),
            '_ZN18PaletteColorEngine13StepAnimationEv': ('0x0232519c', '0x28'),
            '_ZN18PaletteColorEngine10ResetStateEv': ('0x023251c4', '0xa'),
            '_ZN18PaletteColorEngine14GetActiveColorEv': ('0x023251e4', '0x6')
        },
        'content': """// ==========================================================
// C++ Class Implementation: PaletteColorEngine
// ==========================================================

class PaletteColorEngine {
public:
    unsigned short m_cur;   // 0x0
    unsigned short m_lo;    // 0x2
    unsigned short m_hi;    // 0x4
    unsigned short m_flag;  // 0x6

    void InitBounds();
    void StepAnimation();
    void ResetState();
    int GetActiveColor();
};

// decomp: module=unk_autoload_0 addr=0x0232517c name=_ZN18PaletteColorEngine10InitBoundsEv
void PaletteColorEngine::InitBounds() {
    this->m_cur = 0;
    this->m_flag = 0;
    this->m_lo = 40;
    this->m_hi = 45;
}

// decomp: module=unk_autoload_0 addr=0x0232519c name=_ZN18PaletteColorEngine13StepAnimationEv
void PaletteColorEngine::StepAnimation() {
    this->m_cur = this->m_cur + 1;
    if (this->m_cur == this->m_lo || this->m_cur == this->m_hi) {
        this->m_flag = 1;
    }
    if (this->m_cur > this->m_hi) {
        this->m_cur = this->m_lo + 1;
    }
}

// decomp: module=unk_autoload_0 addr=0x023251c4 name=_ZN18PaletteColorEngine10ResetStateEv
void PaletteColorEngine::ResetState() {
    this->m_cur = 0;
    this->m_flag = 0;
}

// decomp: module=unk_autoload_0 addr=0x023251e4 name=_ZN18PaletteColorEngine14GetActiveColorEv
int PaletteColorEngine::GetActiveColor() {
    return this->m_hi;
}
"""
    },
    'src/arm9/TextLayoutEngine.cpp': {
        'symbols': {
            '_ZN16TextLayoutEngine8DrawTextEiii': ('0x02329628', '0xc'),
            '_ZN16TextLayoutEngine9DrawGlyphEiii': ('0x02329634', '0xc'),
            '_ZN16TextLayoutEngine7SetFontEii': ('0x02329640', '0x10'),
            '_ZN16TextLayoutEngine10SetSpacingEii': ('0x02329650', '0xc'),
            '_ZN16TextLayoutEngine13SetLineHeightEii': ('0x0232965c', '0xc')
        },
        'content': """// ==========================================================
// C++ Class Implementation: TextLayoutEngine
// ==========================================================

extern "C" int FUN_02329668(void *self, int a, int b, int code);

class TextLayoutEngine {
public:
    int DrawText(int a, int b, int c);
    int DrawGlyph(int a, int b, int c);
    int SetFont(int a, int b);
    int SetSpacing(int a, int b);
    int SetLineHeight(int a, int b);
};

// decomp: module=unk_autoload_0 addr=0x02329628 name=_ZN16TextLayoutEngine8DrawTextEiii
int TextLayoutEngine::DrawText(int a, int b, int c) {
    return FUN_02329668(this, a, b, 5);
}

// decomp: module=unk_autoload_0 addr=0x02329634 name=_ZN16TextLayoutEngine9DrawGlyphEiii
int TextLayoutEngine::DrawGlyph(int a, int b, int c) {
    return FUN_02329668(this, a, b, 6);
}

// decomp: module=unk_autoload_0 addr=0x02329640 name=_ZN16TextLayoutEngine7SetFontEii
int TextLayoutEngine::SetFont(int a, int b) {
    return FUN_02329668(this, 0, a, 4);
}

// decomp: module=unk_autoload_0 addr=0x02329650 name=_ZN16TextLayoutEngine10SetSpacingEii
int TextLayoutEngine::SetSpacing(int a, int b) {
    return FUN_02329668(this, a, 0, 0x34);
}

// decomp: module=unk_autoload_0 addr=0x0232965c name=_ZN16TextLayoutEngine13SetLineHeightEii
int TextLayoutEngine::SetLineHeight(int a, int b) {
    return FUN_02329668(this, a, 0, 0x39);
}
"""
    }
}

syms_file = r'config\arm9\symbols.txt'
classified_file = r'config\arm9\classified_symbols.json'

print("Converting C-style sources to formal C++ Class structures...\n")

# 1. Update source files
for fpath, info in CPP_CLASS_FILES.items():
    with open(fpath, 'w') as f:
        f.write(info['content'])
    print(f"Updated {fpath} with formal C++ class member methods.")

# 2. Update config/arm9/symbols.txt & classified_symbols.json
with open(syms_file, 'r') as f:
    lines = f.readlines()

new_lines = []
for line in lines:
    for fpath, info in CPP_CLASS_FILES.items():
        for mangled_name, (addr, size) in info['symbols'].items():
            if f"addr={addr}" in line:
                line = re.sub(r'name=\S+', f'name={mangled_name}', line)
    new_lines.append(line)

with open(syms_file, 'w') as f:
    f.writelines(new_lines)
print(f"Updated {syms_file}")

with open(classified_file, 'r') as f:
    classified_data = json.load(f)

for s in classified_data:
    for fpath, info in CPP_CLASS_FILES.items():
        for mangled_name, (addr, size) in info['symbols'].items():
            if s['addr'] == addr:
                s['name'] = mangled_name

with open(classified_file, 'w') as f:
    json.dump(classified_data, f, indent=2)
print(f"Updated {classified_file}")

# 3. Re-run configure.py
subprocess.run([sys.executable, 'configure.py'], check=True)
print("\nRe-ran configure.py successfully!")
