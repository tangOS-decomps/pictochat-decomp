// decomp: module=arm7 addr=0x022d1320 name=FUN_022d1320
// flags: -O4,s -noThumb

// "Shut the network down" request.  Only legal from state 7; anything else is
// answered with 9/3.  Every still-connected peer in the 0x182 bitmap is
// disconnected (retried up to twice while the attempt keeps reporting the
// transient codes 7 or 0xc), its slot bit cleared under the 0x37cb520 lock and
// its last-seen stamp zeroed, then the disconnect is notified.  Afterwards the
// radio is stopped and the block reset back to state 2 before the final 9/0
// completion goes out.

extern void *FUN_037d14bc(void);     // allocate notification
extern void FUN_037d1464(void *msg); // post notification
extern void MI_CpuCopy8(const void *src, void *dst, unsigned int size);
// The lock hands back a token in r0 that the unlock takes straight back: the
// ROM never touches r0 between the two calls, which is why every temporary in
// the slot-clearing block is coloured one register higher.
extern int FUN_037cb520(void);          // enter slot-table critical section
extern void FUN_037cb534(int token);    // leave slot-table critical section
extern void *FUN_022d0008(void *work, const void *mac, int reason);
extern void *FUN_022cfda4(void *work, int mode);
extern void *FUN_022d08d4(void *work);
extern void FUN_022d2ad8(int what, unsigned short slot, const void *mac);
extern void FUN_022d14e4(int code, unsigned short status);
extern void FUN_022ce784(void);
extern void FUN_037cb820(void *dst, int fill, unsigned int size);

typedef struct Mac {
    unsigned char b[6];
} Mac;

typedef struct Res {
    char pad0[4];
    unsigned short status; /* 0x04 */
} Res;

typedef struct Msg {
    unsigned short kind; /* 0x00 */
    unsigned short code; /* 0x02 */
} Msg;

typedef struct Base {
    unsigned short state;          /* 0x000 */
    char pad002[0x84];
    unsigned short linked;         /* 0x086 */
    char pad088[0x3a];
    unsigned short fc2;            /* 0x0c2 */
    char pad0c4[0x32];
    unsigned short ff6;            /* 0x0f6 */
    char pad0f8[0x30];
    Mac macs[15];                  /* 0x128 */
    unsigned short slots;          /* 0x182 */
    char pad184[0x12];
    unsigned short f196;           /* 0x196 */
    int f198;                      /* 0x198 */
    char f19c[0x50];               /* 0x19c */
    char pad1ec[0x54c];
    unsigned long long seen[0x10]; /* 0x738 */
} Base;

extern Base *G_023190dc[];

void FUN_022d1320(void)
{
    unsigned char mac[8];
    char work[0x200];
    // Declaration order picks the callee-saved colouring: i -> r8, n -> sb,
    // b -> sl, which is what the ROM uses.
    int i;
    int n;
    Base *b = G_023190dc[0x154];
    Msg *m;
    Res *r;
    unsigned short st;
    int token;

    if (b->state != 7) {
        m = (Msg *)FUN_037d14bc();
        m->kind = 9;
        m->code = 3;
        FUN_037d1464(m);
        return;
    }

    b->ff6 = 0;

    for (i = 1; i < 0x10; i++) {
        if (b->slots & (1 << i)) {
            MI_CpuCopy8(b->macs[i - 1].b, mac, 6);

            n = 0;
            while (n < 2) {
                r = (Res *)FUN_022d0008(work, mac, 3);
                if (r->status == 0) {
                    break;
                }
                if (r->status != 7 && r->status != 0xc) {
                    break;
                }
                n = n + 1;
            }

            token = FUN_037cb520();
            if (b->slots & (1 << i)) {
                b->slots = b->slots & ~(1 << i);
                b->linked = b->linked & ~(1 << i);
                b->seen[i] = 0;
                FUN_037cb534(token);
                FUN_022d2ad8(1, (unsigned short)i, mac);
            } else {
                FUN_037cb534(token);
            }
        }
    }

    r = (Res *)FUN_022cfda4(work, 1);
    st = r->status;
    if (st != 0) {
        FUN_022d14e4(0, st);
        return;
    }

    b->fc2 = 0;
    b->state = 3;

    r = (Res *)FUN_022d08d4(work);
    st = r->status;
    if (st != 0) {
        FUN_022d14e4(0x302, st);
        return;
    }

    b->state = 2;
    b->f198 = 0;
    b->f196 = 0;
    FUN_037cb820(b->f19c, 0, 0x50);
    FUN_022ce784();

    m = (Msg *)FUN_037d14bc();
    m->kind = 9;
    m->code = 0;
    FUN_037d1464(m);
}
