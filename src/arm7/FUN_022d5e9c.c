// decomp: module=arm7 addr=0x022d5e9c name=FUN_022d5e9c
// flags: -O4,s -noThumb
//
// (Re)initialises the work area published by FUN_022d5e4c: tears down a live
// session if one is still flagged at +0x0c, resets the counters/parameter block
// and mirrors the timing triple at +0x58..+0x5c into the shadow copy at
// +0x7c0, clears the 0x50-byte scratch at +0x19c, reloads the default timing
// parameters, marks all 0x20 context entries free, and finally publishes the
// "ready" state in the first halfword.  Bit 1 of the caller's flag word
// suppresses the trailing notification.
// Verify with size 0x1ac, not 0x1a0 - the stated size excludes this function's
// own three trailing pool words.

typedef struct Ent5e9c {
    unsigned int state;
    char pad4[0xc];
} Ent5e9c;

typedef struct Ctx5e9c {
    char pad0[0xd0];
    Ent5e9c ents[0x20];
} Ctx5e9c;

typedef struct Mgr5e9c {
    char pad0[0x54c];
    Ctx5e9c *ctx;
    void *work;
} Mgr5e9c;

extern Mgr5e9c G_023190dc;

extern int FUN_037cb520(void);
extern void FUN_037cb534(int token);
extern void FUN_037cb820(void *dst, int fill, int len);
extern void FUN_037cb774(int a, void *p, int len);
extern void FUN_037ca02c(void *p);
extern void FUN_022d3bd4(void);
extern void FUN_022ce658(void);
extern void FUN_022ce784(void);
extern void FUN_022d5870(int mask);
extern void FUN_022cfcd8(void);
extern void FUN_022d3bc0(void);
extern void FUN_022d0f8c(int arg);

void FUN_022d5e9c(int flags) {
    // Declaration order is load-bearing: it is what colours ctx/torndown/token
    // into r4/r5/r6 and leaves r7 for the work pointer.
    Ctx5e9c *ctx;
    int torndown = 0;
    int token;
    char *w;
    int i;

    w = (char *)G_023190dc.work;
    ctx = G_023190dc.ctx;
    token = FUN_037cb520();

    if (*(int *)(w + 0xc) == 1) {
        *(int *)(w + 0xc) = 0;
        torndown = 1;
        FUN_022d3bd4();
        FUN_022ce658();
    }

    *(unsigned short *)(w + 0x182) = 0;
    *(unsigned short *)(w + 0x86) = 0;
    *(int *)(w + 0x14) = 0;
    *(int *)(w + 0x10) = 0;
    *(int *)(w + 0x1c) = 0;
    *(unsigned short *)(w + 0xce) = 0;
    *(unsigned short *)(w + 0xc2) = 0;
    *(unsigned short *)(w + 0x58) = 1;
    *(unsigned short *)(w + 0x5a) = 1;
    *(unsigned short *)(w + 0x5c) = 6;
    *(unsigned short *)(w + 0x98) = 0;
    *(unsigned short *)(w + 0x92) = 0;
    *(unsigned short *)(w + 0x94) = 0;
    *(unsigned short *)(w + 0x9a) = 0;
    *(unsigned short *)(w + 0x9c) = 0;
    *(unsigned short *)(w + 0x7c0) = *(unsigned short *)(w + 0x58);
    *(unsigned short *)(w + 0x7c2) = *(unsigned short *)(w + 0x5a);
    *(unsigned short *)(w + 0x7c4) = *(unsigned short *)(w + 0x5c);
    *(unsigned short *)(w + 0x7ca) = *(unsigned short *)(w + 0x98);
    *(unsigned short *)(w + 0x7c6) = *(unsigned short *)(w + 0x92);
    *(unsigned short *)(w + 0x7c8) = *(unsigned short *)(w + 0x94);
    *(unsigned short *)(w + 0x7cc) = *(unsigned short *)(w + 0x9a);
    *(int *)(w + 0x198) = 0;
    *(unsigned short *)(w + 0x196) = 0;
    FUN_037cb820(w + 0x19c, 0, 0x50);
    FUN_022ce784();

    *(unsigned short *)(w + 0x40) = 0x104;
    *(unsigned short *)(w + 0x42) = 0xf0;
    *(unsigned short *)(w + 0x44) = 0x3e8;
    *(unsigned short *)(w + 0x46) = 0;
    *(int *)(w + 0x48) = 0x20b;
    *(int *)(w + 0x4c) = 0;
    *(int *)(w + 0x50) = 0;
    *(int *)(w + 0x54) = 0;
    *(unsigned short *)(w + 0xc6) = 0;
    *(unsigned short *)(w + 0x1ee) = 1;
    *(int *)(w + 0xc8) = flags;
    FUN_037cb534(token);

    if (torndown != 0) {
        FUN_022d5870(0xffff);
    }

    for (i = 0; i < 0x20; i++) {
        ctx->ents[i].state = 0x8000;
    }

    FUN_037cb774(1, w + 0x1f8, 0x100);
    FUN_022cfcd8();
    FUN_037ca02c(w + 0x71c);
    FUN_022d3bc0();

    if ((flags & 2) == 0) {
        FUN_022d0f8c(0xf);
    }

    *(unsigned short *)w = 1;
}
