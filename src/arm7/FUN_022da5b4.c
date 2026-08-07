// decomp: module=arm7 addr=0x022da5b4 name=FUN_022da5b4
// flags: -O4,s -noThumb

// (Re)opens slot `idx` of the 0x1c-byte connection table at +0x31c: bumps the
// open counter at +0x52c when the slot was idle, wipes the first 0x1a bytes,
// drops the slot's bit from the mask at +0x534, copies the caller's descriptor
// into +0x04 of the slot, raises the slot's bit in the mask at +0x530 and
// primes the timeout fields before signalling reason 0x20.
//
// Signature notes (declared to reproduce THIS call site's codegen):
//  - FUN_037cb774 is called (0, slot, 0x1a) - fill value first, then dst/len.
//  - FUN_022d9d68 / FUN_022d9c60 take the slot index as `unsigned short`,
//    which is what produces the lsl #16 / lsr #16 zero-extend pairs.
// NOTE: verify with --size 0xe4, not funcs.json's 0xdc - the stated size
// excludes this function's own trailing pool words.

extern void FUN_037cb774(int fill, void *dst, int len);
extern void FUN_022d9d68(unsigned short slot, unsigned int val);
extern void FUN_022d811c(unsigned short *dst, unsigned short *src);
extern void FUN_022d9c60(unsigned short slot, int reason);

typedef struct Slot5b4 {
    unsigned short state;  /* +0x00 */
    unsigned short pad02;
    unsigned short desc[6]; /* +0x04 */
    unsigned short f10;    /* +0x10 */
    unsigned short pad12;
    unsigned short f14;    /* +0x14 */
    unsigned short pad16;
    unsigned short f18;    /* +0x18 */
    unsigned short f1a;    /* +0x1a */
} Slot5b4;

typedef struct Blk5b4 {
    char pad000[0x31c];
    Slot5b4 *slots;      /* +0x31c */
    char pad320[0x86];
    unsigned short f3a6; /* +0x3a6 */
    char pad3a8[0x184];
    unsigned short f52c; /* +0x52c */
    unsigned short pad52e;
    unsigned short f530; /* +0x530 */
    unsigned short pad532;
    unsigned short f534; /* +0x534 */
} Blk5b4;

extern Blk5b4 *G_0380fff4;

void FUN_022da5b4(int idx, unsigned short *desc)
{
    Blk5b4 *b = G_0380fff4;
    Slot5b4 *s = &b->slots[idx];

    if (s->state == 0) {
        b->f52c = b->f52c + 1;
    }
    FUN_037cb774(0, s, 0x1a);

    G_0380fff4->f534 &= ~(1 << idx);
    FUN_022d9d68(idx, 0);

    G_0380fff4->f530 |= 1 << idx;
    FUN_022d811c(s->desc, desc);

    s->f14 = 0xffff;
    s->f10 = G_0380fff4->f3a6;
    s->f18 = s->f1a;
    FUN_022d9c60(idx, 0x20);
}
