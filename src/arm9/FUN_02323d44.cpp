//cpp
// decomp: module=unk_autoload_0 addr=0x02323d44 name=FUN_02323d44
// verify: python tools/match.py --c src/arm9/FUN_02323d44.cpp --func FUN_02323d44 --addr 0x02323d44 --size 0x9c --module unk_autoload_0 --version 2.0/sp1
// flags: -O4,s

extern "C" {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct State_0238ef0c {
    int unused0;
    int x;
    int y;
    char pad0c[0x2c];
    u16 *position;
};

extern State_0238ef0c G_0238ef0c;

struct Output_02323d44 {
    short v0;
    short v1;
    short v2;
    short v3;
    short v4;
    short v5;
    short v6;
    short v7;
};

void FUN_02323d44(Output_02323d44 *out)
{
    int state = (int)&G_0238ef0c;
#define S (*(State_0238ef0c *)state)

    out->v0 = S.x + (u8)S.position[0];
    out->v1 = S.y + ((u32)S.position[0] << 16 >> 24);
    out->v2 = S.x + ((u8)S.position[0] + (u8)S.position[1]);
    out->v3 = S.y + ((u32)S.position[0] << 16 >> 24);
    out->v4 = S.x + (u8)S.position[0];
    out->v5 = S.y + (((u32)S.position[0] << 16 >> 24)
           + ((u32)S.position[1] << 16 >> 24));
    out->v6 = S.x + ((u8)S.position[0] + (u8)S.position[1]);
    out->v7 = S.y + (((u32)S.position[0] << 16 >> 24)
           + ((u32)S.position[1] << 16 >> 24));
#undef S
}
}
