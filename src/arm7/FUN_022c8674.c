// decomp: module=arm7 addr=0x022c8674 name=FUN_022c8674
// flags: -O4,s

// Resets both slot tables: clears the "in use" bit of every 0x24-byte entry at
// G_03805d7c and stamps each with its own index, then clears the same bit on
// every 0x40-byte entry at G_03805fbc.

#pragma thumb on
#pragma opt_strength_reduction off

typedef unsigned char u8;

typedef struct SlotA {
    u8 flags;
    u8 index;
    char pad[0x22];
} SlotA;

typedef struct SlotB {
    u8 flags;
    char pad[0x3f];
} SlotB;

extern SlotA G_03805d7c[];
extern SlotB G_03805fbc[];

void FUN_022c8674(void)
{
    int i;

    for (i = 0; i < 0x10; i++) {
        G_03805d7c[i].flags &= ~1;
        G_03805d7c[i].index = (u8)i;
    }
    for (i = 0; i < 0x20; i++) {
        G_03805fbc[i].flags &= ~1;
    }
}
