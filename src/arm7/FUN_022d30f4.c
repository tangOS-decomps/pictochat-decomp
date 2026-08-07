// decomp: module=arm7 addr=0x022d30f4 name=FUN_022d30f4
// flags: -O4,s -noThumb

// Tears the session down from state 9/0xa into 7/8.  Anything else is rejected
// straight away with indication (0x10, 3).  The teardown runs the two shutdown
// helpers under the 0x037cb520/0x037cb534 critical section, then builds two
// frames in a 0x200-byte stack scratch buffer; either one reporting a non-zero
// status at +4 aborts with an error code instead of the (0x10, 0) success
// indication.
//
// Signature notes (declared to reproduce THIS call site's codegen):
//  - FUN_037d1464 takes the indication block returned by FUN_037d14bc; the
//    pointer is still live in r0 at the bl.
//  - FUN_022d3210 takes the failing status as its second argument; that is
//    what loads it into r1 rather than reusing r0 at the compare.
// NOTE: verify with --size 0x11c, not funcs.json's 0x110 - the stated size
// excludes this function's own trailing pool words.

extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(unsigned short *ind);
extern int FUN_037cb520(void);
extern void FUN_037cb534(int state);
extern void FUN_022d3bd4(void);
extern void FUN_022ce658(void);
extern unsigned short *FUN_022d073c(unsigned short *buf, unsigned short a);
extern unsigned short *FUN_022d03e8(unsigned short *buf, unsigned short a);
extern void FUN_022d3210(unsigned short code, unsigned short status);
extern void FUN_022d5870(unsigned short mask);

typedef struct Blk30f4 {
    unsigned short state; /* +0x00 */
    unsigned short pad02[5];
    int f0c; /* +0x0c */
    char pad10[0x7a];
    unsigned short f8a; /* +0x8a */
} Blk30f4;

extern Blk30f4 *G_023190dc[];

void FUN_022d30f4(void)
{
    unsigned short buf[0x100];
    int notify = 0;
    int lock;
    Blk30f4 *b;
    unsigned short *ind;
    unsigned short st;
    unsigned short status;

    b = G_023190dc[0x154];
    if (b->state != 9 && b->state != 0xa) {
        ind = FUN_037d14bc();
        ind[0] = 0x10;
        ind[1] = 3;
        FUN_037d1464(ind);
        return;
    }

    lock = FUN_037cb520();
    if (b->f0c == 1) {
        notify = 1;
    }
    b->f0c = 0;
    FUN_022d3bd4();
    FUN_022ce658();

    st = b->state;
    if (st == 0xa) {
        b->state = 8;
    } else if (st == 9) {
        b->state = 7;
    }
    FUN_037cb534(lock);

    status = FUN_022d073c(buf, 0)[2];
    if (status != 0) {
        FUN_022d3210(0x216, status);
        return;
    }

    status = FUN_022d03e8(buf, 7)[2];
    if (status != 0) {
        FUN_022d3210(0x104, status);
        return;
    }

    b->f8a = 0;
    if (notify != 0) {
        FUN_022d5870(0xffff);
    }

    ind = FUN_037d14bc();
    ind[0] = 0x10;
    ind[1] = 0;
    FUN_037d1464(ind);
}
