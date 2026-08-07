// decomp: module=arm7 addr=0x022c97cc name=FUN_022c97cc
// flags: -O4,s

// Four-way visibility/teardown command on the widget `p`: clear the "shown"
// bit (0x04) of the flag byte at +0, set it, set it and repaint the child list
// with no colour override (-1), or set it, repaint with 0x7f and then release
// every child.
// NOTE: verify with --size 0x5a, not funcs.json's 0x52 - the boundary lands
// inside the last BL.

#pragma thumb on

extern void FUN_022c8d88(void *obj, int arg, int value);
extern void FUN_022c8dcc(int p);

void FUN_022c97cc(unsigned char *p, int arg, int cmd)
{
    switch (cmd) {
    case 0:
        p[0] &= ~4;
        break;
    case 1:
        p[0] |= 4;
        break;
    case 2:
        p[0] |= 4;
        FUN_022c8d88(p, arg, -1);
        break;
    case 3:
        p[0] |= 4;
        FUN_022c8d88(p, arg, 0x7f);
        FUN_022c8dcc((int)p);
        break;
    }
}
