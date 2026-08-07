// decomp: module=arm7 addr=0x022c83dc name=FUN_022c83dc
// flags: -O4,s
// THUMB (the nominal size 0x70 is a multiple of 4, but this really is Thumb).
// NOTE: verify with --size 0x78, not the nominal 0x70 - the stated size
// excludes this function's own trailing 2-word literal pool.
#pragma thumb on

// Tears down every wifi port slot named by the caller's 16-bit port bitmask.
// A slot is skipped when its bit is set in the "busy" word G_03805814[1].
// For each surviving slot: run the pending completion callback (+0x48) with
// its cookie (+0x4c), release the port through FUN_022c77a0, clear the +0x22
// state byte, unhook the slot via FUN_022c83d0, and finally strip the 0xf8
// and 0x01 flag bits at +0x03 - the ROM does those two as separate
// read-modify-writes, so they are two statements here, not one &= ~0xf9.

typedef struct Port {
    unsigned char pad0[3];
    unsigned char flags;        /* +0x03 */
    unsigned char pad1[0x1e];
    unsigned char state;        /* +0x22 */
    unsigned char pad2[0x25];
    void *callback;             /* +0x48 */
    void *cookie;               /* +0x4c */
    unsigned char pad3[4];      /* stride 0x54 */
} Port;

extern Port G_0380583c[];
extern unsigned int G_03805814[];

// Signature inferred from register liveness at the bl (r0=slot, r1=0,
// r2=+0x4c cookie, r3=+0x48 callback).  This disagrees with the placeholder
// void FUN_022c4438(void) currently sitting in src/FUN_022c4438.c.
extern void FUN_022c4438(Port *p, int arg, void *cookie, void *callback);
extern void FUN_022c77a0(int slot, int arg);
extern void FUN_022c83d0(Port *p);

void FUN_022c83dc(unsigned int mask)
{
    Port *p;
    int i;

    for (i = 0; i < 16 && mask != 0; i++, mask >>= 1) {
        if (mask & 1) {
            p = &G_0380583c[i];

            if (!(G_03805814[1] & (1u << i))) {
                if (p->callback != 0) {
                    FUN_022c4438(p, 0, p->cookie, p->callback);
                }
                FUN_022c77a0(i, 0);
                p->state = 0;
                FUN_022c83d0(p);
                p->flags &= ~0xf8;
                p->flags &= ~1;
            }
        }
    }
}
