// decomp: module=arm7 addr=0x022d81e8 name=FUN_022d81e8
// flags: -O4,s -noThumb
// NOTE: verify with --size 0x1f8, not the nominal 0x1f0 - the stated size
// excludes this function's own trailing 2-word literal pool.
//
// Drains the wireless hardware statistics counters at 0x048081b0 into the
// 32-bit software totals kept at +0x548 .. +0x5ec of the ARM7 state block.
// Each hardware register packs two saturating 8-bit counters, the low byte
// and the high byte, and reading it clears it; the two halves feed unrelated
// totals, which is why the destinations are scattered rather than paired.
// Leaf function - no prologue.

typedef struct Stats {          /* ARM7 state block + 0x548 */
    int w548;
    int w54c;
    int w550;
    int w554;
    int w558;
    int w55c;
    int w560;
    int w564;
    int w568;
    int w56c;
    int w570;
    int w574;
    int w578;
    int w57c;
    int w580;
    int w584;
    int w588;
    int w58c;
    int w590;
    int w594;
    int w598;
    int w59c;
    int w5a0;
    int w5a4;
    int w5a8;
    int w5ac;
    int w5b0;
    int w5b4;
    int w5b8;
    int w5bc;
    int w5c0;
    int w5c4;
    int w5c8;
    int w5cc;
    int w5d0;
    int w5d4;
    int w5d8;
    int w5dc;
    int w5e0;
    int w5e4;
    int w5e8;
    int w5ec;
} Stats;

void FUN_022d81e8(void)
{
    Stats *s = (Stats *)(*(unsigned char **)0x0380fff4 + 0x548);
    int v;

    v = *(volatile unsigned short *)0x048081b0;
    s->w58c += v & 0xff;

    v = *(volatile unsigned short *)0x048081b2;
    s->w588 += v >> 8;
    s->w598 += v & 0xff;

    v = *(volatile unsigned short *)0x048081b4;
    s->w594 += v >> 8;
    s->w590 += v & 0xff;

    v = *(volatile unsigned short *)0x048081b6;
    s->w59c += v >> 8;
    s->w574 += v & 0xff;

    v = *(volatile unsigned short *)0x048081b8;
    s->w584 += v & 0xff;

    v = *(volatile unsigned short *)0x048081ba;
    s->w55c += v & 0xff;

    v = *(volatile unsigned short *)0x048081bc;
    s->w56c += v >> 8;
    s->w580 += v & 0xff;

    v = *(volatile unsigned short *)0x048081be;
    s->w578 += v & 0xff;
    s->w57c += v >> 8;

    v = *(volatile unsigned short *)0x048081c0;
    s->w548 += v & 0xff;

    v = *(volatile unsigned short *)0x048081d0;
    s->w5b4 += v >> 8;

    v = *(volatile unsigned short *)0x048081d2;
    s->w5b8 += v & 0xff;
    s->w5bc += v >> 8;

    v = *(volatile unsigned short *)0x048081d4;
    s->w5c0 += v & 0xff;
    s->w5c4 += v >> 8;

    v = *(volatile unsigned short *)0x048081d6;
    s->w5c8 += v & 0xff;
    s->w5cc += v >> 8;

    v = *(volatile unsigned short *)0x048081d8;
    s->w5d0 += v & 0xff;
    s->w5d4 += v >> 8;

    v = *(volatile unsigned short *)0x048081da;
    s->w5d8 += v & 0xff;
    s->w5dc += v >> 8;

    v = *(volatile unsigned short *)0x048081dc;
    s->w5e0 += v & 0xff;
    s->w5e4 += v >> 8;

    v = *(volatile unsigned short *)0x048081de;
    s->w5e8 += v & 0xff;
    s->w5ec += v >> 8;
}
