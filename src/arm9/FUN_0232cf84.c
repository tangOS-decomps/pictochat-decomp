// decomp: module=unk_autoload_0 addr=0x0232cf84 name=FUN_0232cf84
// size: 0xcc - the nominal 0xc6 excludes the alignment pad and pool word.
//
// Sibling of FUN_0232ce20: validates a send request against the live
// controller state and, when it passes, hands opcode 0xf to the sender.
// While no transfer is active (+0x188) the "ready" word at +0x182 decides
// whether sending is allowed at all (7 if not). The buffer must be non-null,
// differ from the one in flight (+0x7c) and be 1..0x200 bytes (6 otherwise);
// it is flushed before FUN_0232c408 queues it. A zero result from the sender
// becomes 2.

typedef unsigned short u16;

struct Ctl {
    char pad00[0x7c];
    void *cur;      /* 0x7c */
    char pad80[6];
    u16 f86;        /* 0x86 */
    char pad88[0xfa];
    u16 ready;      /* 0x182 */
    char pad184[4];
    u16 busy;       /* 0x188 */
};

struct Owner {
    char pad00[4];
    struct Ctl *ctl;   /* 0x04 */
};

extern struct Owner *FUN_0232c4d0(void);
extern int FUN_0232c520(int, int, int);
extern void FUN_023314cc(void *, int);
extern void FUN_023314e8(void *, unsigned int);
extern int FUN_0232c408(int, int, void *, unsigned int, u16, u16, u16, int, int);

int FUN_0232cf84(int a, int b, void *buf, unsigned int len, u16 p, u16 q, u16 r)
{
    struct Ctl *ctl;
    int res;
    u16 ready = 1;

    ctl = FUN_0232c4d0()->ctl;
    res = FUN_0232c520(2, 9, 10);
    if (res == 0) {
        FUN_023314cc(&ctl->busy, 2);
        if (ctl->busy == 0) {
            FUN_023314cc(&ctl->ready, 2);
            ready = ctl->ready;
            FUN_023314cc(&ctl->f86, 2);
        }
        if (buf == 0)
            return 6;
        if (ready == 0)
            return 7;
        FUN_023314cc(&ctl->cur, 4);
        if (buf == ctl->cur)
            return 6;
        if (len > 0x200)
            return 6;
        if (len == 0)
            return 6;
        FUN_023314e8(buf, len);
        res = FUN_0232c408(0xf, 7, buf, len, p, q, r, a, b);
        if (res == 0)
            res = 2;
    }
    return res;
}
