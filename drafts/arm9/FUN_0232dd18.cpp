// decomp: module=unk_autoload_0 addr=0x0232dd18 name=FUN_0232dd18
// A 2-bit `mode` field (bits 14-15 of the first param, a bitfield struct
// passed by value) selects behavior: mode 1 divides `val` by 2 (rounding
// toward zero), mode 2 passes `val` through unchanged, anything else
// returns 0. The other two formal params are unused by this logic but are
// part of the real call signature (the compiler spills all four incoming
// argument registers to the stack up front, matching the real binary).
struct Flags {
    unsigned short pad : 14;
    unsigned short mode : 2;
};

int FUN_0232dd18(struct Flags flags, int val, int unused2, int unused3)
{
    struct Flags *pf = &flags;
    int mode = pf->mode;
    if (mode == 1) {
        return (val + 1) / 2;
    }
    if (mode == 2) {
        return val;
    }
    return 0;
}
