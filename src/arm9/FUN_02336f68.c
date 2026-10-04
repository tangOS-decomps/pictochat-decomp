// decomp: module=unk_autoload_0 addr=0x02336f68 name=FUN_02336f68

// GX_SetBankForOBJ: releases the previous OBJ VRAM banks back to LCDC, records
// the new OBJ bank set and programs the VRAMCNT registers (A/B/E/F/G) for OBJ
// use, then re-applies the LCDC bank mapping.

typedef struct GXState {
    unsigned short lcdc;
    unsigned short bg;
    unsigned short obj;
} GXState;

extern GXState G_023c1914;
extern void FUN_02336d70(int);

#define VRAMCNT_A (*(volatile unsigned char *)0x04000240)
#define VRAMCNT_B (*(volatile unsigned char *)0x04000241)
#define VRAMCNT_E (*(volatile unsigned char *)0x04000244)
#define VRAMCNT_F (*(volatile unsigned char *)0x04000245)
#define VRAMCNT_G (*(volatile unsigned char *)0x04000246)

void FUN_02336f68(int obj)
{
    G_023c1914.lcdc = (unsigned short)(~obj & (G_023c1914.lcdc | G_023c1914.obj));
    G_023c1914.obj = (unsigned short)obj;

    switch (obj) {
    case 0x03:
        VRAMCNT_B = 0x8a;
    case 0x01:
        VRAMCNT_A = 0x82;
        break;
    case 0x02:
        VRAMCNT_B = 0x82;
        break;
    case 0x70:
        VRAMCNT_G = 0x9a;
    case 0x30:
        VRAMCNT_F = 0x92;
    case 0x10:
        VRAMCNT_E = 0x82;
        break;
    case 0x50:
        VRAMCNT_G = 0x92;
        VRAMCNT_E = 0x82;
        break;
    case 0x60:
        VRAMCNT_G = 0x8a;
    case 0x20:
        VRAMCNT_F = 0x82;
        break;
    case 0x40:
        VRAMCNT_G = 0x82;
        break;
    case 0:
        break;
    default:
        break;
    }

    FUN_02336d70(G_023c1914.lcdc);
}
