// decomp: module=arm7 addr=0x022c2fd0 name=FUN_022c2fd0
// flags: -O4,s -noThumb

// Per-frame hook: runs the two optional sub-updates whose enable flags live in
// the +0x300 section of the ARM7 state block (a plain counter at +0x3e8 and a
// single bit inside the flag word at +0x33a).

extern void FUN_00ddadb4(void);
extern void FUN_00dd7770(void);

typedef struct {
    unsigned short head : 6;
    unsigned short enabled : 1;
    unsigned short tail : 9;
} Flags022c2fd0;

void FUN_022c2fd0(void)
{
    if (*(unsigned short *)(*(unsigned char **)0x0380fff4 + 0x3e8) != 0) {
        FUN_00ddadb4();
    }
    if (((Flags022c2fd0 *)(*(unsigned char **)0x0380fff4 + 0x33a))->enabled) {
        FUN_00dd7770();
    }
}
