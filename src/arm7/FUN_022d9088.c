// decomp: module=arm7 addr=0x022d9088 name=FUN_022d9088
// flags: -O4,s -noThumb

// ORs `bits` into the halfword at +0x3f4 of the ARM7 state block while holding
// lock 0x01000000, then raises event (2, 0x15).

extern int FUN_037c9084(int lock);
extern void FUN_037c904c(int token);
extern void FUN_037c5628(int a, int b);

typedef struct Sub9088 {
    char pad[0xf4];
    unsigned short f4;
} Sub9088;

typedef struct Blk9088 {
    char pad[0x300];
    Sub9088 sub;
} Blk9088;

void FUN_022d9088(int bits)
{
    int token = FUN_037c9084(0x01000000);
    Blk9088 *b = *(Blk9088 **)0x0380fff4;

    b->sub.f4 |= bits;
    FUN_037c904c(token);
    FUN_037c5628(2, 0x15);
}
