//cpp
// decomp: module=arm7 addr=0x022c8bf0 name=FUN_022c8bf0
typedef unsigned int u32;

struct ControlBlock {
    u32 unused;
    u32 base;
    u32 end;
    u32 words[4];
};

extern "C" ControlBlock G_0380581c;

extern "C" void FUN_022c8bf0(u32* src)
{
    u32* aligned = (u32*)((u32)src & ~3);

    G_0380581c.base = (u32)aligned;
    G_0380581c.end = (u32)(aligned + 4);
    G_0380581c.words[0] = aligned[0];
    G_0380581c.words[1] = aligned[1];
    G_0380581c.words[2] = aligned[2];
    G_0380581c.words[3] = aligned[3];
}
