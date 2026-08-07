// decomp: module=arm7 addr=0x022c9798 name=FUN_022c9798
// flags: -O4,s

// Claims the first free slot in the 0x20-entry table of 0x40-byte records at
// G_03805fbc (the same table FUN_022c8dec indexes), marks it in use and
// returns its index, or -1 when every slot is taken.

#pragma thumb on

typedef struct Slot {
    unsigned char used : 1;
    char pad[0x3f];
} Slot;

extern Slot G_03805fbc[];

int FUN_022c9798(void)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        if (!G_03805fbc[i].used) {
            G_03805fbc[i].used = 1;
            return i;
        }
    }
    return -1;
}
