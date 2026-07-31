//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232df74 name=FUN_0232df74
// Byte-identical sibling of FUN_0232df40 (packed value/mode dispatch) -
// same struct shape, same logic, compiles to the exact same instructions.
struct Packed {
    signed short val : 12;
    unsigned short mode : 2;
};

int FUN_0232df74(struct Packed p, int val2, int unused2, int unused3)
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
