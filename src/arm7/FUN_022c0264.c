// decomp: module=arm7 addr=0x022c0264 name=FUN_022c0264
// flags: -O4,s

// Walks the three 16-byte channel records that follow the 0xc-byte header of
// `set` and, for each one whose one-bit `flag` matches the caller's, hands the
// record's begin/end/context triple to the WRAM callback when the range is not
// empty.  The bl goes through the Thumb->ARM veneer parked at 0x022c029c
// (`bx pc / nop / ldr pc,[pc,#-4]`), whose real target is 0x0380f600.

#pragma thumb on

typedef struct Chan {
    int begin;
    int end;
    void *ctx;
    unsigned int flag : 1;
} Chan;

typedef struct ChanSet {
    char header[0xc];
    Chan ch[3];
} ChanSet;

extern void FUN_022c029c(int begin, int end, void *ctx);

void FUN_022c0264(ChanSet *set, unsigned int flag)
{
    int i;

    if (set == 0) return;

    for (i = 0; i < 3; i++) {
        Chan *c = &set->ch[i];
        if (c->flag == flag) {
            if (c->begin != c->end)
                FUN_022c029c(c->begin, c->end, c->ctx);
        }
    }
}
