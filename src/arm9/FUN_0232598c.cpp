//cpp
// decomp: module=unk_autoload_0 addr=0x0232598c name=FUN_0232598c
// NONMATCHING: direct field expressions reproduce the full 0xc8-byte function and instruction shapes, but mwcc colors the value/advance/page temporaries differently and schedules two call arguments differently. (div=17). Logic verified correct vs ROM; not byte-exact.

extern "C" {
typedef unsigned short u16;
typedef unsigned int u32;

void *FUN_02321c60(void);
u32 FUN_0232de60(void *, u32);
u32 FUN_0232df14(void *, u32);
int FUN_02325960(void *);
void FUN_0232dc5c(void *, void *, int, int, u32, int);

void FUN_0232598c(void *arg, int value)
{
    u16 advance;
    u16 width;
    char *p;

    p = (char *)arg;
    advance = FUN_0232de60(FUN_02321c60(), value);
    width = FUN_0232df14(FUN_02321c60(), value);

    if (advance + *(u16 *)(p + *(u16 *)(p + 0x56a) * 0x104 + 0x158) <= 0xe1 ||
        FUN_02325960(p) != 0) {
        u16 *count_base = (u16 *)(p + 0x156);
        u16 page = *(u16 *)(p + 0x56a);
        u16 count = *(u16 *)((char *)count_base + page * 0x104);
        *(u16 *)((char *)count_base + page * 0x104) = count + 1;
        *(u16 *)(p + *(u16 *)(p + 0x56a) * 0x104 + 0x56 + count * 2) = value;

        u16 draw_page = *(u16 *)(p + 0x56a);
        char *draw_record = p + draw_page * 0x104;
        FUN_0232dc5c(FUN_02321c60(), p + 0x14,
                     *(u16 *)(draw_record + 0x158) + 0x18 - width,
                     *(u16 *)(p + 0x56c) + draw_page * 0x10, value, 1);
        *(u16 *)(p + *(u16 *)(p + 0x56a) * 0x104 + 0x158) += advance + 1;
    }
}
}
