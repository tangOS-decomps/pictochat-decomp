// decomp: module=arm7 addr=0x022df124 name=FUN_022df124
// flags: -O4,s -noThumb
// NOTE: verify with --size 0x94, not the nominal 0x88 - the stated size
// excludes this function's own trailing 3-word literal pool.

// Advances one entry (index 1) of an array of connection-slot records kept
// at +0x400 of the ARM7 state block. Bumps the slot's retry counter; if the
// slot isn't idle (state != 0) it just clears its child record's +4 field
// and leaves. If idle, it marks the slot busy (state = 1), zeroes the
// child's +0/+4 fields, stashes a fresh handle from FUN_022d85b4 into the
// child's +8 field, then packs the child pointer's low bits into a
// hardware "buffer ready" register at 0x048080a8.

typedef struct ChildEntry {
    unsigned short f0;   /* +0x00 */
    unsigned char pad0[2];
    unsigned short f4;   /* +0x04 */
    unsigned char pad1[2];
    unsigned short f8;   /* +0x08 */
} ChildEntry;

typedef struct Entry {
    unsigned short state;     /* +0x00 */
    unsigned short counter;   /* +0x02 */
    unsigned char pad[4];     /* +0x04 */
    ChildEntry *child;        /* +0x08 */
} Entry;

extern unsigned short FUN_022d85b4(void);

void FUN_022df124(void)
{
    unsigned char *base = *(unsigned char **)0x0380fff4;
    unsigned char *tmp = base + 0x54;
    Entry *ctx = (Entry *)(tmp + 0x400);
    unsigned char *arr400 = base + 0x400;

    ctx->counter++;

    if (*(unsigned short *)(arr400 + 0x54) != 0) {
        ctx->child->f4 = 0;
    } else {
        ctx->state = 1;
        ctx->child->f0 = 0;
        ctx->child->f4 = 0;
        ctx->child->f8 = FUN_022d85b4();
        {
            unsigned short v = (unsigned short)(((unsigned int)ctx->child & 0x3fff) >> 1);
            *(volatile unsigned short *)0x048080a8 = v | 0x8000;
        }
    }
}
