// decomp: module=arm7 addr=0x022d254c name=FUN_022d254c
// flags: -O4,s -noThumb
// size: 0x58c - the nominal 0x584 stops at `bx lr` and excludes the two
// trailing pool words (0x023190dc and 0x00000302).

// "Disconnect peers" request.  `req->f4` is the bitmap of slots to drop,
// `req->f8` a tag echoed in the replies when `mode` is set.  From a child
// state (10/8) the parent link is disconnected and the network torn back down
// to state 2; from a parent state (9/7) every selected connected child is
// disconnected and its slot cleared under the 0x37cb520 lock.  Disconnect
// attempts are retried while they report 7 or 0xc.  The cleared-slot bitmap is
// written to `*out`; returns 1, or 0 on failure (after reporting it).
//
// Matching levers:
//  - `w`, a function-scope pointer to `work`: its web spans the whole
//    function, so the allocator rematerialises it (`add r0, sp, #0x20`) at
//    every call instead of giving it a register.  Passing `work` directly
//    lets the parent retry loop hoist it, which costs one instruction and
//    displaces the ROM's hoisted pmac/3 pair (r6/r4).
//  - The child slot test spells the bit as `(1 << i)` rather than `bit`;
//    that is what colours `mask` to r8 and the retry counters to sb.
//  - Both retry loops are `switch`es: an if-chain predicates the child
//    loop's `n++` (addeq/beq) where the ROM branches.
//  - `b` is loaded first: the ROM's prologue reads the 0x023190dc pool
//    word before `req->f4`.

typedef struct Mac {
    unsigned char b[6];
} Mac;

typedef struct Req {
    int f0;
    int f4;
    int f8;
} Req;

typedef struct Res {
    char pad0[4];
    unsigned short status; /* 0x04 */
} Res;

typedef struct Base {
    unsigned short state;          /* 0x000 */
    char pad002[0xa];
    int fc;                        /* 0x00c */
    int f10;                       /* 0x010 */
    int f14;                       /* 0x014 */
    char pad018[4];
    int f1c;                       /* 0x01c */
    char pad020[0x10];
    unsigned short f30;            /* 0x030 */
    unsigned short f32;            /* 0x032 */
    char pad034[0x52];
    unsigned short linked;         /* 0x086 */
    char pad088[0x3a];
    unsigned short fc2;            /* 0x0c2 */
    char pad0c4[0x64];
    Mac macs[15];                  /* 0x128 */
    unsigned short slots;          /* 0x182 */
    char pad184[4];
    unsigned short f188;           /* 0x188 */
    Mac parent;                    /* 0x18a */
    char pad190[6];
    unsigned short f196;           /* 0x196 */
    int f198;                      /* 0x198 */
    char f19c[0x50];               /* 0x19c */
    char pad1ec[0x54c];
    unsigned long long seen[0x10]; /* 0x738 */
} Base;

extern Base *G_023190dc[];

extern unsigned short *FUN_037d14bc(void); // allocate notification
extern void FUN_037d1464(void *msg);       // post notification
extern void MI_CpuCopy8(const void *src, void *dst, unsigned int size);
extern void FUN_037cb820(void *dst, int fill, unsigned int size);
extern int FUN_037cb520(void);
extern void FUN_037cb534(int token);
extern void *FUN_022d0008(void *work, const void *mac, int reason);
extern void *FUN_022cfda4(void *work, int mode);
extern void *FUN_022d08d4(void *work);
extern void FUN_022d2ad8(int mode, unsigned short id, const void *mac);
extern void FUN_022d2be0(unsigned short a, unsigned short b, unsigned short c, unsigned short d);
extern void FUN_022d2b9c(unsigned short a, unsigned short b, unsigned short c, unsigned short d);
extern void FUN_022d5870(unsigned short mask);
extern int FUN_022d3bd4(void);
extern void FUN_022ce658(void);
extern void FUN_022ce784(void);

int FUN_022d254c(Req *req, int mode, unsigned short *out)
{
    char work[0x200];
    Mac pmac;
    Mac mac;
    unsigned short *m;
    unsigned short done;
    int resume;
    int token;
    int n;
    void *w;
    unsigned short st;
    int i;
    unsigned short tag;
    Res *r;
    Base *b;
    unsigned short id;
    int bit;
    unsigned short mask;

    b = G_023190dc[0x154];
    w = work;
    mask = (unsigned short)req->f4;
    tag = (unsigned short)(mode ? req->f8 : 0);
    done = 0;
    resume = 0;

    st = b->state;
    if (st == 9 || st == 7) {
        if (b->fc == 1) {
            resume = 1;
        }
    } else if (st == 10 || st == 8) {
        token = FUN_037cb520();
        if (b->slots == 0) {
            FUN_037cb534(token);
            if (mode == 0) {
                m = FUN_037d14bc();
                m[0] = 0xd;
                m[1] = 3;
                m[2] = 0;
                m[3] = 0;
                m[4] = mask;
                m[5] = 0;
                FUN_037d1464(m);
            }
            return 0;
        }
        if (b->fc == 1) {
            b->fc = 0;
            resume = 1;
            FUN_022d3bd4();
            FUN_022ce658();
            if (b->state == 10) {
                b->state = 8;
            }
        }
        b->slots = 0;
        b->linked = 0;
        b->f14 = 0;
        b->f10 = 0;
        b->f1c = 0;
        FUN_037cb534(token);
    } else {
        if (mode == 0) {
            m = FUN_037d14bc();
            m[0] = 0xd;
            m[1] = 3;
            m[2] = done;
            m[3] = done;
            m[4] = mask;
            m[5] = done;
            FUN_037d1464(m);
        }
        return 0;
    }

    if (b->state == 10 || b->state == 8) {
        MI_CpuCopy8(&b->parent, &pmac, 6);
        n = 0;
        while (n < 2) {
            r = (Res *)FUN_022d0008(w, &pmac, 3);
            switch (r->status) {
            case 0:
            case 1:
                goto parent_gone;
            case 7:
            case 0xc:
                n++;
                continue;
            }
            if (mode) {
                FUN_022d2be0(5, r->status, mask, done);
            } else {
                FUN_022d2b9c(5, r->status, mask, done);
            }
            if (resume) {
                FUN_022d5870(1);
            }
            return 0;
        }
    parent_gone:
        b->fc2 = 0;
        b->state = 3;
        done = 1;

        r = (Res *)FUN_022cfda4(w, 1);
        if (r->status != 0) {
            if (mode) {
                FUN_022d2be0(0, r->status, mask, done);
            } else {
                FUN_022d2b9c(0, r->status, mask, done);
            }
            if (resume) {
                FUN_022d5870(1);
            }
            return 0;
        }

        r = (Res *)FUN_022d08d4(w);
        if (r->status != 0) {
            if (mode) {
                FUN_022d2be0(0x302, r->status, mask, done);
            } else {
                FUN_022d2b9c(0x302, r->status, mask, done);
            }
            if (resume) {
                FUN_022d5870(1);
            }
            return 0;
        }

        b->state = 2;
        b->f198 = 0;
        b->f196 = 0;
        FUN_037cb820(b->f19c, 0, 0x50);
        FUN_022ce784();

        if (mode == 1) {
            m = FUN_037d14bc();
            m[0] = 0xc;
            m[1] = 0;
            m[4] = 9;
            m[6] = tag;
            m[5] = b->f188;
            MI_CpuCopy8(&pmac, &m[8], 6);
            m[0xb] = b->f30;
            m[0xc] = b->f32;
            FUN_037d1464(m);
        } else {
            FUN_022d2ad8(0, 0, &pmac);
        }
        if (resume) {
            FUN_022d5870(1);
        }
    } else {
        for (i = 1; i < 0x10; i++) {
            bit = 1 << i;
            if (!((b->slots & mask) & (1 << i))) {
                continue;
            }
            id = i;
            MI_CpuCopy8(&b->macs[i - 1], &mac, 6);
            n = 0;
            while (n < 2) {
                r = (Res *)FUN_022d0008(w, &mac, 3);
                switch (r->status) {
                case 0:
                    goto gone;
                case 7:
                case 0xc:
                    n++;
                    continue;
                }
                if (mode) {
                    FUN_022d2be0(5, r->status, mask, done);
                } else {
                    FUN_022d2b9c(5, r->status, mask, done);
                }
                if (resume) {
                    FUN_022d5870(1);
                }
                return 0;
            }

        gone:
            token = FUN_037cb520();
            if (b->slots & bit) {
                done = (unsigned short)(done | (1 << id));
                b->slots = b->slots & ~bit;
                b->linked = b->linked & ~bit;
                b->seen[id] = 0;
                FUN_037cb820(&b->macs[i - 1], 0, 6);
                FUN_037cb534(token);
                if (mode == 1) {
                    m = FUN_037d14bc();
                    m[0] = 8;
                    m[1] = 0;
                    m[4] = 9;
                    m[9] = tag;
                    m[8] = id;
                    MI_CpuCopy8(&mac, &m[5], 6);
                    m[0x16] = b->f30;
                    m[0x17] = b->f32;
                    FUN_037d1464(m);
                } else {
                    FUN_022d2ad8(1, (unsigned short)i, &mac);
                }
                if (resume) {
                    FUN_022d5870((unsigned short)bit);
                }
            } else {
                FUN_037cb534(token);
            }
        }
    }

    if (out) {
        *out = done;
    }
    return 1;
}
