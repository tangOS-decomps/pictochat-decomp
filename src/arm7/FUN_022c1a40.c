// decomp: module=arm7 addr=0x022c1a40 name=FUN_022c1a40
// flags: -O4,s -noThumb
// NOTE: verify with --size 0xa0, not the nominal 0x90 - the stated size
// excludes this function's own trailing 4-word literal pool.
//
// Full reset of the ARM7 wireless block: tears down the two message queues
// hanging off the state block (+0x608 and +0x634), drops back to media mode
// 0x20, clears the software state at +0x3e8 / +0x356, wipes the 0x0480800x
// control registers, optionally runs the mode-1 teardown hook, arms the two
// 0x048080ac match registers with 0xffff and restarts the driver.

typedef struct Ctx {
    unsigned char pad[8];
    unsigned short mode;    /* +0x34c */
    unsigned char pad2[2];
    unsigned short flag;    /* +0x350 */
    unsigned char pad3[4];
    unsigned short f12;     /* +0x356 */
    unsigned char pad4[0x90];
    unsigned short fa4;     /* +0x3e8 */
} Ctx;

extern void FUN_022c6600(void *q);
extern void FUN_022c1ae0(unsigned int mode);
extern void func_00ddaa18(void);
extern void func_00dda744(void);
extern void func_00dd25a0(void);

void FUN_022c1a40(void)
{
    unsigned char *base = *(unsigned char **)0x0380fff4;
    Ctx *ctx = (Ctx *)(base + 0x344);

    FUN_022c6600(base + 0x608);
    FUN_022c6600(*(unsigned char **)0x0380fff4 + 0x634);
    FUN_022c1ae0(0x20);

    ctx->fa4 = 0;
    ctx->f12 = 0;

    *(volatile unsigned short *)0x04808012 = 0;
    *(volatile unsigned short *)0x04808004 = 0;
    *(volatile unsigned short *)0x048080ea = 0;
    *(volatile unsigned short *)0x048080e8 = 0;
    *(volatile unsigned short *)0x04808008 = 0;
    *(volatile unsigned short *)0x0480800a = 0;

    if (ctx->flag == 1) {
        func_00ddaa18();
    }

    *(volatile unsigned short *)0x048080ac = 0xffff;
    *(volatile unsigned short *)0x048080b4 = 0xffff;

    func_00dda744();
    func_00dd25a0();
}
