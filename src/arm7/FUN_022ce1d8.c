// decomp: module=arm7 addr=0x022ce1d8 name=FUN_022ce1d8
// flags: -O4,s -noThumb

typedef struct Rec {
    unsigned char pad0[0xe];
    unsigned short idx;     /* +0x0e */
    unsigned short pad1[2]; /* +0x10, +0x12 */
    unsigned short tbl[1];  /* +0x14 */
} Rec;

extern void FUN_A(void *, int, int);
extern void FUN_B(void *, Rec **, int);
extern unsigned short *FUN_C(void);
extern void FUN_D(void);
extern void FUN_E(void);
extern void FUN_F(void);

Rec *FUN_022ce1d8(int a)
{
    Rec *p;

    FUN_A((void *)0x023180dc, a, 1);
    FUN_B((void *)0x02318134, &p, 1);

    if (p->tbl[p->idx] == 0xe) {
        unsigned short *m = FUN_C();
        m[0] = 0x80;
        m[1] = 0x13;
        m[2] = 0x18;
        FUN_D();
        FUN_E();
        FUN_F();
    }

    return p;
}
