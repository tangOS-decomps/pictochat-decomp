// decomp: module=arm7 addr=0x022c3a88 name=FUN_022c3a88
// flags: -O4,s -noThumb
// size: 0x120 - the nominal 0xf8 excludes the ten trailing pool words.
//
// Resets the wireless RX ring: clears the 0x50-byte RX bookkeeping block at
// +0x4dc, picks the RX buffer start for the MAC variant at +0x350 (0x794 /
// 0x10c4 / 0xbfc / 0x794 bytes into wifi RAM; any other variant leaves it
// unset, as in the ROM), programs the RX begin/end/read/write registers at
// 0x04808050.., records the ring size at +0x344+0x9a and invalidates the
// receive-side state registers with 0xffff.

typedef unsigned short u16;
typedef unsigned int u32;
typedef volatile unsigned short vu16;

extern void FUN_022c6fc8(int value, void *dst, u32 size);

#define ST (*(char **)0x0380fff4)

void FUN_022c3a88(void)
{
    char *st = ST;
    u16 *w = (u16 *)(st + 0x344);
    u16 *rx = (u16 *)(st + 0x4dc);
    u32 sz;

    FUN_022c6fc8(0, rx, 0x50);
    *(vu16 *)0x04808030 = 0x8000;

    switch (*(u16 *)(ST + 0x350)) {
    case 0:
        sz = 0x794;
        break;
    case 1:
        sz = 0x10c4;
        break;
    case 2:
        sz = 0xbfc;
        break;
    case 3:
        sz = 0x794;
        break;
    }

    *(vu16 *)0x04808050 = sz + 0x04804000;
    *(vu16 *)0x04808056 = sz >> 1;
    *(vu16 *)0x04808052 = 0x5f60;
    *(vu16 *)0x0480805a = sz >> 1;
    rx[2] = sz >> 1;
    rx[0] = 0xffff;
    w[0x4d] = 0x5f60 - 0x4000 - sz;
    *(vu16 *)0x04808062 = 0x5f60 - 2;
    *(vu16 *)0x04808030 = 0x8001;
    *(vu16 *)0x0480824c = 0xffff;
    *(vu16 *)0x0480824e = 0xffff;
    *(vu16 *)0x04805f70 = 0xffff;
    *(vu16 *)0x04805f72 = 0xffff;
    *(vu16 *)0x04805f7e = 0xffff;
    *(vu16 *)0x04805f76 = 0xffff;
}
