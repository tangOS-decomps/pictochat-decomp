// decomp: module=arm7 addr=0x022d914c name=FUN_022d914c
// flags: -O4,s -noThumb

// Shutdown path for the ARM7 state block at *(0x0380fff4): sets the "stopping"
// bit, and if the subsystem at +0x34c is live, tears it down, cancels a pending
// request at +0x404, then spins polling until the channel reports 0xffff before
// posting the final notification.

typedef struct Sub {
    unsigned char pad0[4];
    unsigned short state;    /* +0x04 */
} Sub;

typedef struct St {
    unsigned char pad0[0x33e];
    unsigned short flags;    /* +0x33e */
    unsigned char pad1[0xc];
    unsigned short live;     /* +0x34c */
    unsigned char pad2[0xb6];
    unsigned short pending;  /* +0x404 */
    unsigned char pad3[0x1a];
    Sub *sub;                /* +0x420 */
} St;

extern void StopSubsystem(void);
extern void FUN_022dbb30(void);
extern void FUN_022d7d30(void);
extern unsigned int Poll(int chan);
extern void Notify(int chan, int what);

void FUN_022d914c(void)
{
    (*(St **)0x0380fff4)->flags |= 0x8000;

    if ((*(St **)0x0380fff4)->live != 0) {
        StopSubsystem();
        if ((*(St **)0x0380fff4)->pending != 0) {
            (*(St **)0x0380fff4)->pending = 0;
            (*(St **)0x0380fff4)->sub->state = 6;
            FUN_022dbb30();
        }
        FUN_022d7d30();
    }

    while (Poll(3) != 0xffff) {
        ;
    }

    Notify(3, 0x17);
}
