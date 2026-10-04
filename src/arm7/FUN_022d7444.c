// decomp: module=arm7 addr=0x022d7444 name=FUN_022d7444
// flags: -O4,s -noThumb
// size: 0xd4 - the nominal 0xcc excludes the two trailing pool words.
//
// Sets the two antenna/diversity bits of the flag word at +0x33a: bit 4 is
// `mode`, and bit 5 is `sel` in mode 0 or cleared in mode 1 (which is only
// accepted while the link mode word at +0x32e is 1, else 0xb). Arguments
// above 1 are rejected with 5. The RF switch register 0x04808290 is then
// loaded with bit 3 ^ bit 5 of the result.

typedef unsigned short u16;

typedef struct Flags33a {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 10;
} Flags33a;

#define FLAGS (*(Flags33a *)(*(char **)0x0380fff4 + 0x33a))

int FUN_022d7444(unsigned int mode, unsigned int sel)
{
    if (mode > 1 || sel > 1) {
        return 5;
    }
    switch (mode) {
    case 0:
        FLAGS.b5 = (u16)sel;
        break;
    case 1:
        if (*(u16 *)(*(char **)0x0380fff4 + 0x32e) != 1) {
            return 0xb;
        }
        FLAGS.b5 = 0;
        break;
    }
    FLAGS.b4 = (u16)mode;
    *(volatile u16 *)0x04808290 = FLAGS.b5 ^ FLAGS.b3;
    return 0;
}
