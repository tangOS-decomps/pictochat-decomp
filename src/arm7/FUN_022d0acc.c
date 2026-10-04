// decomp: module=arm7 addr=0x022d0acc name=FUN_022d0acc
// flags: -O4,s -noThumb
//
// Wireless disconnect / reset handler (ARM7 side). With interrupts off it
// consumes the pending-reset flag (+0xc), dropping a connected parent/child
// state (10/9) back to its idle counterpart (8/7), and clears the session
// fields. Every peer still set in the connected-AID mask (+0x182) is reported
// through FUN_022d2ad8 before the peer table at +0x128 is wiped. It then
// queries the hardware mode and, depending on it, resets the MAC, power and
// listening state, ending in state 2 and posting a "reset done" message.
// Any failing step reports through FUN_022d0eac and returns.
//
// Phrasing that the bytes depend on:
//  - every call takes the work buffer through the pointer local `w`; passing
//    `work` directly makes mwcc hoist sp+0x10 into a register in the retry
//    loop and swaps the argument order of the broadcast call;
//  - `state == 7 || state == 8` (not a subtraction) gives the add-0xfff9 test;
//  - the retry result is a switch, so the err == 0 arm stays out of line.

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

typedef struct Resp {
    u16 f0;
    u16 f2;
    u16 err;    /* +0x4 */
    u16 val;    /* +0x6 */
} Resp;

typedef struct ConnMgrD0acc {
    char pad[0x550];
    u8 *st;
} ConnMgrD0acc;

extern ConnMgrD0acc G_023190dc;

extern int FUN_037cb520(void);
extern void FUN_037cb534(int token);
extern void FUN_037cb820(void *dst, int fill, u32 size);
extern void FUN_037cb8b4(const void *src, void *dst, u32 len);
extern u16 *FUN_037d14bc(void);
extern void FUN_037d1464(void);
extern void FUN_022d3bd4(void);
extern void FUN_022ce658(void);
extern void FUN_022ce784(void);
extern void FUN_022d5870(u16 mask);
extern void FUN_022d2ad8(int what, u16 slot, const void *mac);
extern Resp *FUN_022d0960(void *work);
extern Resp *FUN_022d08a8(void *work);
extern Resp *FUN_022d0008(void *work, const void *mac, int reason);
extern Resp *FUN_022cfda4(void *work, int mode);
extern Resp *FUN_022d08d4(void *work);
extern Resp *FUN_022d05c0(void *work, u16 arg);
extern Resp *FUN_022d0974(void *work, int a, int b, int c, int d);
extern void FUN_022d0eac(u16 code, u16 err);

void FUN_022d0acc(void)
{
    u8 work[0x200];
    u8 mac[6];
    u8 bcast[6];
    void *w;
    int reinit;
    int irq;
    int isParent;
    int i;
    u8 *st;
    u32 aids;
    int try;
    Resp *res;
    int type;
    u16 mode;
    u16 *msg;

    st = G_023190dc.st;
    w = work;
    reinit = 0;
    irq = FUN_037cb520();
    if (U32(st, 0xc) == 1) {
        U32(st, 0xc) = 0;
        reinit = 1;
        FUN_022d3bd4();
        FUN_022ce658();
        if (U16(st, 0) == 10)
            U16(st, 0) = 8;
        else if (U16(st, 0) == 9)
            U16(st, 0) = 7;
    }
    if (U16(st, 0) == 7 || U16(st, 0) == 8) {
        isParent = U16(st, 0) == 7;
        aids = U16(st, 0x182);
    } else {
        aids = 0;
    }
    U16(st, 0x182) = 0;
    U16(st, 0x86) = 0;
    U32(st, 0x14) = 0;
    U32(st, 0x10) = 0;
    U32(st, 0x1c) = 0;
    U16(st, 0xc2) = 0;
    FUN_037cb534(irq);

    if (reinit)
        FUN_022d5870(0xffff);
    if (isParent)
        U16(st, 0xf6) = 0;
    if (aids != 0) {
        for (i = 0; i < 16; i++) {
            if (aids & (1 << i))
                FUN_022d2ad8(isParent, (u16)i, i == 0 ? st + 0x18a : st + 0x128 + (i - 1) * 6);
        }
    }
    FUN_037cb820(st + 0x128, 0, 0x5a);

    res = FUN_022d0960(w);
    if (res->err != 0) {
        FUN_022d0eac(0x308, res->err);
        return;
    }
    type = res->val;
    res = FUN_022d08a8(w);
    if (res->err != 0) {
        FUN_022d0eac(0x284, res->err);
        return;
    }
    mode = res->val;

    switch (type) {
    case 0x30:
    case 0x40:
        if (mode == 2 || mode == 3) {
            FUN_037cb8b4(st + 0x18a, mac, 6);
            for (try = 0; try < 2; try++) {
                u16 err = FUN_022d0008(w, mac, 3)->err;
                switch (err) {
                case 0:
                    U16(st, 0) = 3;
                    goto reset;
                case 7:
                case 12:
                    break;
                default:
                    goto reset;
                }
            }
        } else if (mode == 1) {
            FUN_037cb820(bcast, 0xff, 6);
            if (FUN_022d0008(w, bcast, 3)->err == 0)
                U16(st, 0) = 3;
        }
    case 0x20:
    reset:
        res = FUN_022cfda4(w, 1);
        if (res->err != 0) {
            FUN_022d0eac(0, res->err);
            return;
        }
    case 0:
        res = FUN_022d08d4(w);
        if (res->err != 0) {
            FUN_022d0eac(0x302, res->err);
            return;
        }
    case 0x10:
        if (U16(st, 0x1ee) == 0) {
            res = FUN_022d05c0(w, 1);
            if (res->err != 0) {
                FUN_022d0eac(0x20e, res->err);
                return;
            }
            U16(st, 0x1ee) = 1;
        }
        U16(st, 0) = 2;
        U32(st, 0x198) = 0;
        FUN_022ce784();
        break;
    case 0x11:
    case 0x12:
        if (mode == 0) {
            res = FUN_022d0974(w, 0, 0, 0x14, 1);
            if (res->err != 0) {
                FUN_022d0eac(0x309, res->err);
                return;
            }
        }
        res = FUN_022d08d4(w);
        if (res->err != 0) {
            FUN_022d0eac(0x302, res->err);
            return;
        }
        U16(st, 0) = 2;
        break;
    default:
        FUN_022d0eac(0x308, 0);
        return;
    }

    msg = FUN_037d14bc();
    msg[0] = 1;
    msg[1] = 0;
    FUN_037d1464();
}
