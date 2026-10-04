// decomp: module=arm7 addr=0x022d87fc name=FUN_022d87fc
// flags: -O4,s -noThumb

// Baseband/RF init from the firmware config: copies the 16 baseband register
// values (config records 0x44..0x62) to their I/O addresses from the offset
// table, programs the RF control register at 0x04808184 from the RF header
// at ctx+0x5f8, then loads the RF register entries starting at record 0xce:
// type 3 chips get one byte per entry tagged with its index, other chips get
// `bits` rounded up to whole bytes per entry, written through FUN_022d865c.

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct RfInfo {
    u16 type;       /* +0x0 */
    u16 bits;       /* +0x2 */
    u16 count;      /* +0x4 */
    u16 pad6;
    u8 f8[4];       /* +0x8 */
    u32 fc;         /* +0xc */
} RfInfo;

typedef struct Ctx {
    char pad0[0x5f8];
    RfInfo rf;      /* +0x5f8 */
} Ctx;

#define G_0380fff4 (*(Ctx **)0x0380fff4)

extern u16 G_02316418[16];

extern void FUN_022e2e4c(int index, int n, void *dst);
extern void FUN_022d865c(u32 val);

void FUN_022d87fc(void)
{
    u32 rf;
    u32 val;
    u32 i;
    int index;
    u32 n;
    int bytes;
    u32 hi;
    RfInfo *info;

    info = &G_0380fff4->rf;
    val = 0;
    for (i = 0; i < 16; i++) {
        FUN_022e2e4c(i * 2 + 0x44, 2, &val);
        *(u16 *)(G_02316418[i] + 0x04808000) = val;
    }

    hi = (u32)info->bits >> 7;
    rf = hi << 8;
    rf = (info->bits & 0x7f) | (hi << 8);
    *(u16 *)0x04808184 = rf;

    index = 0xce;
    bytes = ((info->bits & 0x7f) + 7) / 8;
    n = info->count;
    if (info->type == 3) {
        FUN_022e2e4c(n + 0xce, 1, info->f8);
        for (i = 0; i < n; i++, index++) {
            rf = 0;
            FUN_022e2e4c(index, 1, &rf);
            rf |= (i << 8) + 0x50000;
            FUN_022d865c(rf);
        }
    } else {
        rf = 0;
        while (n != 0) {
            FUN_022e2e4c(index, bytes, &rf);
            FUN_022d865c(rf);
            n--;
            index += bytes;
            if (info->type == 2 && (rf >> 18) == 9)
                info->fc = rf & ~0x7c00;
        }
    }
}
