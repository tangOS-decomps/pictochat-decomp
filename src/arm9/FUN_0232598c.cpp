//cpp
// decomp: module=unk_autoload_0 addr=0x0232598c name=FUN_0232598c
// verify: python tools/match.py --c src/arm9/FUN_0232598c.cpp --func FUN_0232598c --addr 0x0232598c --size 0xc8 --module unk_autoload_0 --version 2.0/sp1

extern "C" {
typedef unsigned short u16;
typedef unsigned int u32;

void *FUN_02321c60(void);
u16 FUN_0232de60(void *, u32);
u16 FUN_0232df14(void *, u32);
int FUN_02325960(void *);
void FUN_0232dc5c(void *, void *, int, int, u32, int);

void FUN_0232598c(void *arg, u32 value)
{
    char *p = (char *)arg;
    u16 advance = FUN_0232de60(FUN_02321c60(), value);
    u16 width = FUN_0232df14(FUN_02321c60(), value);
    u16 page = *(u16 *)(p + 0x56a);
    char *record = p + page * 0x104;

    if (advance + *(u16 *)(record + 0x158) <= 0xe1 || FUN_02325960(p) != 0) {
        u16 count = *(u16 *)(record + 0x156);
        *(u16 *)(record + 0x156) = count + 1;
        *(u16 *)(record + 0x56 + count * 2) = value;

        page = *(u16 *)(p + 0x56a);
        record = p + page * 0x104;
        FUN_0232dc5c(FUN_02321c60(), p + 0x14,
                     *(u16 *)(record + 0x158) + 0x18 - width,
                     *(u16 *)(p + 0x56c) + page * 0x10, value, 1);
        *(u16 *)(record + 0x158) += advance + 1;
    }
}
}
