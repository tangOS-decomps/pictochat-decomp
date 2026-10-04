//cpp
// decomp: module=unk_autoload_0 addr=0x0232598c name=FUN_0232598c
// NONMATCHING: instruction stream is exact; the only difference is a callee-saved rotation (ROM: advance r4, page r6, ch r7; C: ch r4, advance r7) that survived declaration order, local copies of both args, types, pragmas, every 2.0/* build and decomp-permuter (div=8). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm 2.0/sp1 (see notes/matching-style.md).
// Counts as decompiled, not matched.

extern "C" {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 chars[0x80];
    u16 count;
    u16 x;
} Line; // 0x104

typedef struct {
    u8 head[0x14];
    u8 canvas[0x42];
    Line lines[5];
    u16 page;
    u16 baseY;
} Text;

void *FUN_02321c60(void);
int FUN_0232de60(void *, int);
int FUN_0232df14(void *, int);
int FUN_02325960(Text *);
void FUN_0232dc5c(void *, void *, int, int, int, int);

void FUN_0232598c(Text *text, int ch)
{
    int advance = (u16)FUN_0232de60(FUN_02321c60(), ch);
    u16 width = FUN_0232df14(FUN_02321c60(), ch);

    if (advance + text->lines[text->page].x <= 0xe1 || FUN_02325960(text) != 0) {
        text->lines[text->page].chars[text->lines[text->page].count++] = ch;
        FUN_0232dc5c(FUN_02321c60(), text->canvas,
                     text->lines[text->page].x + 0x18 - width,
                     text->baseY + text->page * 0x10, ch, 1);
        text->lines[text->page].x += advance + 1;
    }
}
}
