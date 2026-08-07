// decomp: module=arm7 addr=0x022d77ec name=FUN_022d77ec
// flags: -O4,s -noThumb
// NOTE: verify with --size 0x150, not the nominal 0x134 - the stated size
// excludes this function's own trailing 7-word literal pool.
//
// One-shot configuration of the wireless MAC from the flash calibration data:
// pulls the 6-byte station address (record 0x36) and the enabled-channel mask
// (record 0x3c) out of the config block, then walks the whole register-setter
// table putting every tunable back to its power-on default. Finishes by
// seeding the random/backoff state from three reads of 0x04808044 and marking
// the state block as configured.

extern void FUN_022e2e4c(int record, int len, void *out);
extern void FUN_022d6e98(void *addr);
extern void FUN_022d6ef8(int v);
extern void FUN_022d6f2c(unsigned short channels);
extern void FUN_022d6f6c(int v);
extern void FUN_022d6fec(int v);
extern void FUN_022d7020(int v);
extern void FUN_022d70c0(int v);
extern void FUN_022d70e4(void *p);
extern void FUN_022d771c(int v);
extern void FUN_022d7144(int v);
extern void FUN_022d717c(int v);
extern void FUN_022d71b4(int v);
extern void FUN_022d71ec(int a, int b);
extern void FUN_022d729c(void *p);
extern void FUN_022d72cc(int v);
extern void FUN_022d7374(int v);
extern void FUN_022d7bc8(void *p);
extern void FUN_022d7398(int a, int b);
extern void FUN_022d7e6c(int v);
extern void FUN_022d7444(int a, int b);
extern void FUN_022d73dc(int v);
extern void FUN_022d7518(int v);
extern void FUN_022d7558(int v);
extern void FUN_022d8d88(int seed, int extra);

void FUN_022d77ec(void)
{
    unsigned short channels;
    unsigned char addr[6];
    unsigned short lo;
    unsigned short hi;
    unsigned short rest;

    FUN_022e2e4c(0x36, 6, addr);
    FUN_022e2e4c(0x3c, 2, &channels);

    FUN_022d6e98(addr);
    FUN_022d6ef8(7);
    FUN_022d6f2c((unsigned short)(channels & 0x7ffe));
    FUN_022d6f6c(2);
    FUN_022d6fec(0);
    FUN_022d7020(0);
    FUN_022d70c0(0);
    FUN_022d70e4((void *)0x02316438);
    FUN_022d771c(0x1f4);
    FUN_022d7144(0);
    FUN_022d717c(0);
    FUN_022d71b4(0x10);
    FUN_022d71ec(0xffff, 0);
    FUN_022d729c((void *)0x023163d8);
    FUN_022d72cc(1);
    FUN_022d7374(0);
    FUN_022d7bc8((void *)0x023163d4);
    FUN_022d7398(0, 0x1f);
    FUN_022d7e6c(5);
    FUN_022d7444(0, 0);
    FUN_022d73dc(0);
    FUN_022d7518(0);
    FUN_022d7558(0);

    lo = *(volatile unsigned short *)0x04808044;
    hi = *(volatile unsigned short *)0x04808044;
    rest = *(volatile unsigned short *)0x04808044;
    FUN_022d8d88(lo + (hi << 8), rest);

    *(unsigned short *)(*(unsigned char **)0x0380fff4 + 0x358) = 1;
}
