//cpp
// decomp: module=unk_autoload_0 addr=0x02337e38 name=FUN_02337e38
// verify: python tools/match.py --c src/arm9/FUN_02337e38.cpp --func FUN_02337e38 --addr 0x02337e38 --size 0x1c --module unk_autoload_0 --version 2.0/sp1

// Blanks all eight 12-byte slots of the table at G_023c3440.

#pragma thumb on
extern "C" {
typedef struct Slot {
    int a;
    int b;
    char c;
} Slot;
extern Slot G_023c3440[];
void FUN_02337e38(void)
{
    int i;
    for (i = 0; i < 8; i++) {
        G_023c3440[i].a = 0;
        G_023c3440[i].b = 0;
        G_023c3440[i].c = 0;
    }
}
}
