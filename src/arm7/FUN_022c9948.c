// decomp: module=arm7 addr=0x022c9948 name=FUN_022c9948
// flags: -O4,s
//
// Builds a transfer descriptor from a request block: the request's kind picks
// how the payload handle is resolved (table lookup, packed index pair, or one
// of two fixed forms), and only if that succeeds are the remaining request
// fields copied across.  A sub-index of 0xff means "no sub-index" and turns the
// caller's flag word into all-ones.
// Verify with size 0xdc, not 0xd2 - the stated size stops inside the epilogue.

#pragma thumb on

typedef struct Info9948 {
    unsigned char kind;
    char pad1[1];
    unsigned short f2;
    unsigned short f4;
    unsigned char f6;
    unsigned char f7;
    unsigned char f8;
    unsigned char f9;
    unsigned char sub;
    unsigned char fb;
} Info9948;

typedef struct Node9948 {
    char pad0[0x38];
    unsigned int count;
} Node9948;

typedef struct Slot9948 {
    Node9948 *node;
    char pad4[4];
} Slot9948;

typedef struct Tbl9948 {
    char pad0[0x18];
    Slot9948 slots[1];
} Tbl9948;

typedef struct Desc9948 {
    char pad0[5];
    unsigned char f5;
    char pad6[2];
    unsigned char f8;
    unsigned char f9;
    unsigned char fa;
} Desc9948;

extern unsigned int FUN_022c9918(Node9948 *node, unsigned int index);
extern int FUN_022c8150(Desc9948 *desc, unsigned int handle, unsigned int body,
                        int flags);
extern int FUN_022c8178(Desc9948 *desc, unsigned int index, int flags);
extern int FUN_022c81a8(Desc9948 *desc, int flags);
extern void FUN_022c8238(Desc9948 *desc, unsigned char v);
extern void FUN_022c8254(Desc9948 *desc, unsigned char v);
extern void FUN_022c8268(Desc9948 *desc, unsigned char v);
extern void FUN_022c826c(Desc9948 *desc, unsigned char v);

int FUN_022c9948(Desc9948 *desc, int a1, int a2, int a3, Tbl9948 *tbl,
                 Info9948 *info) {
    unsigned int handle;
    unsigned int index;
    unsigned int slot;
    int ok;
    Node9948 *node;
    int flags = a3;
    unsigned char sub = info->sub;

    if (sub == 0xff) {
        flags = -1;
        sub = 0;
    }

    switch (info->kind) {
    case 1:
    case 4:
        if (info->kind == 1) {
            // Reading f2 before the table lookup is load-bearing: it reserves
            // r1 for `index` so the lookup's temporaries land in r0/r2.
            index = info->f2;
            slot = info->f4;
            node = tbl->slots[slot].node;
            if (node == 0) {
                handle = 0;
            } else if (index >= node->count) {
                handle = 0;
            } else {
                handle = FUN_022c9918(node, index);
            }
        } else {
            handle = ((unsigned int)info->f4 << 16) | info->f2;
        }
        if (handle != 0) {
            ok = FUN_022c8150(desc, handle, handle + 0xc, flags);
        } else {
            ok = 0;
        }
        break;
    case 2:
        ok = FUN_022c8178(desc, info->f2, flags);
        break;
    case 3:
        ok = FUN_022c81a8(desc, flags);
        break;
    default:
        ok = 0;
        break;
    }

    if (ok == 0) {
        return 0;
    }

    desc->f8 = (unsigned char)a1;
    desc->f5 = info->f6;
    desc->f9 = (unsigned char)a2;
    FUN_022c8238(desc, info->f7);
    FUN_022c8254(desc, info->f8);
    FUN_022c8268(desc, info->f9);
    FUN_022c826c(desc, sub);
    desc->fa = info->fb - 0x40;
    return 1;
}
