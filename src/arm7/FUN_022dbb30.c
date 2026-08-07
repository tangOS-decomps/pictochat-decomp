// decomp: module=arm7 addr=0x022dbb30 name=FUN_022dbb30
// flags: -O4,s -noThumb

// Clears the "busy" bit of the state block's +0x428 control halfword, hands the
// pending request word at +0x424 to FUN_037c5de8 together with the +0x200
// context, and if the +0x208 counter is still non-zero raises event (2, 0xb).

extern void FUN_037c5de8(void *ctx, int req);
extern void FUN_037c5628(int a, int b);

typedef struct Ctl {
    int req;
    unsigned short flags;
} Ctl;

void FUN_022dbb30(void)
{
    char *base = *(char **)0x0380fff4;
    Ctl *ctl = (Ctl *)(base + 0x424);
    char *ctx = base + 0x17c;

    ctl->flags &= ~1;
    FUN_037c5de8(ctx + 0x84, ctl->req);
    if (*(unsigned short *)(ctx + 0x8c) != 0) {
        FUN_037c5628(2, 0xb);
    }
}
