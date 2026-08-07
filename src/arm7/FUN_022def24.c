// decomp: module=arm7 addr=0x022def24 name=FUN_022def24
// flags: -O4,s -noThumb

// Reprograms the three channel slots (FUN_022df00c) from the mode half-word at
// +0x350 of the global context.  Mode 1 additionally tears down a pending
// entry in the sub-block at +0x42c and hands its +0x90 payload to
// FUN_037c5998; modes 2 and 3 share one arm, everything else falls to the
// all-zero default.  The trailing FUN_037c5998 argument re-reads the global
// pointer rather than reusing the cached copy.

typedef struct Chan {
    char pad0[0x3c];
    unsigned short pending;
    unsigned short count;
    char pad1[0x90 - 0x40];
    void *payload;
} Chan;

extern void FUN_022df00c(int slot, int on);
extern void FUN_037c5998(void *dst, void *payload);

extern int G_0380fff4;

void FUN_022def24(void)
{
    char *ctx = (char *)G_0380fff4;
    Chan *ch = (Chan *)(ctx + 0x42c);

    switch (*(unsigned short *)(ctx + 0x350)) {
    case 1:
        FUN_022df00c(0, 1);
        FUN_022df00c(1, 0);
        FUN_022df00c(2, 1);
        if (ch->pending != 0) {
            ch->pending = 0;
            ch->count--;
            FUN_037c5998((char *)G_0380fff4 + 0x188, ch->payload);
        }
        break;
    case 2:
    case 3:
        FUN_022df00c(0, 1);
        FUN_022df00c(1, 0);
        FUN_022df00c(2, 0);
        break;
    default:
        FUN_022df00c(0, 0);
        FUN_022df00c(1, 0);
        FUN_022df00c(2, 0);
        break;
    }
}
