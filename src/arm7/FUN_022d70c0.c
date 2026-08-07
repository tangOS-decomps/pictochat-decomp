// decomp: module=arm7 addr=0x022d70c0 name=FUN_022d70c0
// flags: -O4,s -noThumb
//
// Stores a 0..3 mode selector into the halfword at +0x336 of the global
// context; rejects anything larger with error code 5.

typedef struct Ctx70c0 {
    char pad[0x336];
    unsigned short f336;
} Ctx70c0;

extern Ctx70c0 *G_0380fff4;

int FUN_022d70c0(unsigned int mode)
{
    if (mode > 3) {
        return 5;
    }
    G_0380fff4->f336 = (unsigned short)mode;
    return 0;
}
