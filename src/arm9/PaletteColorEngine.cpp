// ==========================================================
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
