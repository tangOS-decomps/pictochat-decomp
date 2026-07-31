import os, sys, subprocess, json, re

# Restore 100% byte-matching C implementations in src/arm9
CPP_CLASS_FILES = {
    'src/arm9/PaletteColorEngine.cpp': """// ==========================================================
// C++ Class Implementation: PaletteColorEngine.cpp
// ==========================================================

// --- PaletteColorEngine ---
//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232517c name=Palette_InitBounds
void Palette_InitBounds(char *p)
{
    *(short *)(p + 0x0) = 0;
    *(short *)(p + 0x6) = 0;
    *(short *)(p + 0x2) = 40;
    *(short *)(p + 0x4) = 45;
}

// decomp: module=unk_autoload_0 addr=0x0232519c name=Palette_StepAnimation
struct Counter {
    unsigned short cur;
    unsigned short lo;
    unsigned short hi;
    unsigned short flag;
};
void Palette_StepAnimation(struct Counter *c)
{
    c->cur = c->cur + 1;
    if (c->cur == c->lo || c->cur == c->hi) {
        c->flag = 1;
    }
    if (c->cur > c->hi) {
        c->cur = c->lo + 1;
    }
}

// decomp: module=unk_autoload_0 addr=0x023251c4 name=Palette_ResetState
void Palette_ResetState(char *p)
{
    *(short *)(p + 0x0) = 0;
    *(short *)(p + 0x6) = 0;
}

// decomp: module=unk_autoload_0 addr=0x023251e4 name=Palette_GetActiveColor
int Palette_GetActiveColor(unsigned short *p)
{
    return p[3];
}

}
""",
    'src/arm9/TextLayoutEngine.cpp': """// ==========================================================
// C++ Class Implementation: TextLayoutEngine.cpp
// ==========================================================

// --- TextLayoutEngine ---
//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x02329628 name=TextLayout_DrawText
extern int FUN_02329668(int a, int b, int c, int code);
int TextLayout_DrawText(int a, int b, int c) {
    return FUN_02329668(a, b, c, 5);
}

// decomp: module=unk_autoload_0 addr=0x02329634 name=TextLayout_DrawGlyph
int TextLayout_DrawGlyph(int a, int b, int c) {
    return FUN_02329668(a, b, c, 6);
}

// decomp: module=unk_autoload_0 addr=0x02329640 name=TextLayout_SetFont
int TextLayout_SetFont(int a, int b) {
    return FUN_02329668(a, 0, b, 4);
}

// decomp: module=unk_autoload_0 addr=0x02329650 name=TextLayout_SetSpacing
int TextLayout_SetSpacing(int a, int b) {
    return FUN_02329668(a, b, 0, 0x34);
}

// decomp: module=unk_autoload_0 addr=0x0232965c name=TextLayout_SetLineHeight
int TextLayout_SetLineHeight(int a, int b) {
    return FUN_02329668(a, b, 0, 0x39);
}

}
"""
}

# Create formal C++ Class Headers in include/
HEADERS = {
    'include/PaletteColorEngine.h': """#ifndef PALETTE_COLOR_ENGINE_H
#define PALETTE_COLOR_ENGINE_H

extern "C" {
    void Palette_InitBounds(char *p);
    void Palette_StepAnimation(void *c);
    void Palette_ResetState(char *p);
    int Palette_GetActiveColor(unsigned short *p);
}

class PaletteColorEngine {
private:
    unsigned short m_cur;   // 0x0
    unsigned short m_lo;    // 0x2
    unsigned short m_hi;    // 0x4
    unsigned short m_flag;  // 0x6

public:
    inline void InitBounds() { Palette_InitBounds((char *)this); }
    inline void StepAnimation() { Palette_StepAnimation((void *)this); }
    inline void ResetState() { Palette_ResetState((char *)this); }
    inline int GetActiveColor() const { return Palette_GetActiveColor((unsigned short *)this); }
};

#endif // PALETTE_COLOR_ENGINE_H
""",
    'include/TextLayoutEngine.h': """#ifndef TEXT_LAYOUT_ENGINE_H
#define TEXT_LAYOUT_ENGINE_H

extern "C" {
    int TextLayout_DrawText(int a, int b, int c);
    int TextLayout_DrawGlyph(int a, int b, int c);
    int TextLayout_SetFont(int a, int b);
    int TextLayout_SetSpacing(int a, int b);
    int TextLayout_SetLineHeight(int a, int b);
}

class TextLayoutEngine {
public:
    inline int DrawText(int b, int c) { return TextLayout_DrawText((int)this, b, c); }
    inline int DrawGlyph(int b, int c) { return TextLayout_DrawGlyph((int)this, b, c); }
    inline int SetFont(int fontId) { return TextLayout_SetFont((int)this, fontId); }
    inline int SetSpacing(int pixels) { return TextLayout_SetSpacing((int)this, pixels); }
    inline int SetLineHeight(int height) { return TextLayout_SetLineHeight((int)this, height); }
};

#endif // TEXT_LAYOUT_ENGINE_H
"""
}

# Revert symbol names in symbols.txt & classified_symbols.json
SYMBOL_MAP = {
    '0x0232517c': 'Palette_InitBounds',
    '0x0232519c': 'Palette_StepAnimation',
    '0x023251c4': 'Palette_ResetState',
    '0x023251e4': 'Palette_GetActiveColor',
    '0x02329628': 'TextLayout_DrawText',
    '0x02329634': 'TextLayout_DrawGlyph',
    '0x02329640': 'TextLayout_SetFont',
    '0x02329650': 'TextLayout_SetSpacing',
    '0x0232965c': 'TextLayout_SetLineHeight',
}

syms_file = r'config\arm9\symbols.txt'
classified_file = r'config\arm9\classified_symbols.json'

print("Setting up formal C++ Class headers and 100% byte-matched source files...\n")

for fpath, text in CPP_CLASS_FILES.items():
    with open(fpath, 'w') as f: f.write(text)

os.makedirs('include', exist_ok=True)
for hpath, text in HEADERS.items():
    with open(hpath, 'w') as f: f.write(text)
    print(f"Created C++ header: {hpath}")

with open(syms_file, 'r') as f: lines = f.readlines()
new_lines = []
for line in lines:
    for addr, sname in SYMBOL_MAP.items():
        if f"addr={addr}" in line:
            line = re.sub(r'name=\S+', f'name={sname}', line)
    new_lines.append(line)
with open(syms_file, 'w') as f: f.writelines(new_lines)

with open(classified_file, 'r') as f: classified_data = json.load(f)
for s in classified_data:
    for addr, sname in SYMBOL_MAP.items():
        if s['addr'] == addr: s['name'] = sname
with open(classified_file, 'w') as f: json.dump(classified_data, f, indent=2)

subprocess.run([sys.executable, 'configure.py'], check=True)
print("\nRe-ran configure.py successfully!")
