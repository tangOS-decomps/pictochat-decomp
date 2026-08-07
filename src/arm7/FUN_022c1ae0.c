// decomp: module=arm7 addr=0x022c1ae0 name=FUN_022c1ae0
// flags: -O4,s -noThumb
// NOTE: verify with --size 0xa4, not the nominal 0x98 - the stated size
// excludes this function's own trailing 3-word literal pool.

// Sets the ARM7 "media mode" state stored at +0x34c of the ARM7 state
// block, running the necessary enter/leave hooks. A no-op if the requested
// mode already matches the current one. Leaving mode 0x40 tears it down via
// FUN_022c6600; entering mode 0 starts a driver via FUN_00dd3550; entering
// mode 0x10 clears a hardware register and (re)inits via FUN_022c1a40;
// entering mode 0x40 optionally flushes a pending write (state +0x350 == 2)
// then logs a fixed-size event via FUN_00dd4218.

typedef struct Ctx {
    unsigned char pad[8];      /* base+0x344 .. base+0x34b */
    unsigned short mode;       /* +0x34c */
    unsigned char pad2[2];
    unsigned short flag;       /* +0x350 */
} Ctx;

extern void FUN_022c6600(void *p);
extern void FUN_022c1a40(void);
extern void FUN_00dd3550(void);
extern void FUN_00dd35d8(void);
extern void FUN_00dd373c(void);
extern void FUN_00dd4218(int a, void *b);

void FUN_022c1ae0(unsigned int mode)
{
    unsigned char *base = *(unsigned char **)0x0380fff4;
    Ctx *ctx = (Ctx *)(base + 0x344);

    if (ctx->mode != mode) {
        if (ctx->mode == 0x40) {
            FUN_022c6600(base + 0x634);
        }
        switch (mode) {
        case 0:
            FUN_00dd3550();
            break;
        case 0x10:
            *(volatile unsigned short *)0x04808040 = 0;
            FUN_022c1a40();
            FUN_00dd35d8();
            break;
        case 0x40:
            if (ctx->flag == 2) {
                FUN_00dd373c();
            }
            FUN_00dd4218(0x64, (void *)0x0230bd4c);
            break;
        }
        ctx->mode = (unsigned short)mode;
    }
}
