// decomp: module=unk_autoload_0 addr=0x0232ce20 name=FUN_0232ce20

// Validates a requested transfer window against the live controller state
// (busy flags, alignment, negotiated limits) and, when it passes, builds the
// 0x40-byte opcode-0xe request block and hands it to the sender.

typedef unsigned short u16;

struct Ctl {
    char pad00[0xc];
    int busy;       /* 0x0c */
    char pad10[0x8c];
    u16 f9c;        /* 0x9c */
    char pad9e[0x28];
    u16 fc6;        /* 0xc6 */
    char padc8[0xc0];
    u16 f188;       /* 0x188 */
};

struct Owner {
    char pad00[4];
    struct Ctl *ctl;   /* 0x04 */
};

struct Pkt {
    u16 kind;       /* 0x00 */
    u16 pad02;
    int f04;        /* 0x04 */
    int f08;        /* 0x08 */
    int f0c;        /* 0x0c */
    int f10;        /* 0x10 */
    char f14[0x1c]; /* 0x14 */
    char f30[0x10]; /* 0x30 */
};

extern struct Owner *FUN_0232c4d0(void);
extern int FUN_0232c520(int, int, int);
extern void FUN_023314cc(void *, int);
extern int FUN_0232c998(void);
extern int FUN_0232c954(void);
extern void FUN_0232c3bc(int, int);
extern void FUN_02337440(int data, void *dst, int size);
extern void FUN_02337454(const void *src, void *dst, int size);
extern int FUN_0232c484(void *, int);

int FUN_0232ce20(int a, int b, int c, int d, volatile u16 e, const void *f)
{
    struct Pkt pkt;
    struct Ctl *ctl;
    int r;
    u16 ee;

    ctl = FUN_0232c4d0()->ctl;
    r = FUN_0232c520(2, 7, 8);
    if (r == 0) {
        FUN_023314cc(&ctl->f188, 2);
        FUN_023314cc(&ctl->fc6, 2);
        if (ctl->f188 != 0 && ctl->fc6 != 1)
            return 3;
        FUN_023314cc(&ctl->busy, 4);
        if (ctl->busy == 1)
            return 3;
        if ((c & 0x3f) != 0)
            return 6;
        ee = e;
        if ((ee & 0x1f) != 0)
            return 6;
        FUN_023314cc(&ctl->f9c, 2);
        if (ctl->f9c == 0) {
            if (c < FUN_0232c998())
                return 6;
            if (ee < FUN_0232c954())
                return 6;
        }
        FUN_0232c3bc(0xe, a);
        FUN_02337440(0, &pkt, 0x40);
        pkt.kind = 0xe;
        pkt.f04 = b;
        pkt.f08 = (int)((unsigned int)c >> 1);
        pkt.f0c = d;
        pkt.f10 = e;
        FUN_02337440(0, pkt.f14, 0x1c);
        FUN_02337454(f, pkt.f30, 0x10);
        r = FUN_0232c484(&pkt, 0x40);
        if (r == 0)
            r = 2;
    }
    return r;
}
