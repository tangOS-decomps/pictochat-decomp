//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232df40 name=FUN_0232df40
// Sibling of FUN_0232dd18: a packed 16-bit value (signed 12-bit `val` in
// bits 0-11, 2-bit `mode` in bits 12-13, passed by value as the first
// param) drives a mode dispatch against `val2`: mode 1 subtracts
// round-to-zero half of (val2+1), mode 2 subtracts val2 directly, anything
// else passes val through unchanged. The other two formal params are
// unused by this logic but are part of the real call signature.
struct Packed {
    signed short val : 12;
    unsigned short mode : 2;
};

int FUN_0232df40(struct Packed p, int val2, int unused2, int unused3)
{
    struct Packed *pp = &p;
    int val = pp->val;
    int mode = pp->mode;
    switch (mode) {
        case 1: return val - (val2 + 1) / 2;
        case 2: return val - val2;
        default: return val;
    }
}

}
