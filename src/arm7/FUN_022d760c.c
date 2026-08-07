// decomp: module=arm7 addr=0x022d760c name=FUN_022d760c
// flags: -O4,s -noThumb
// size: 0x110 - 0x10c of code plus the trailing pool word for 0x0380fff4.

// Loads a new key/SSID-style byte string of `len` bytes into the 32-byte buffer
// at +0x20 of the +0x344 sub-block, zero-filling the tail. Rejects lengths over
// 32 with error 5. While the sub-block is live (state 0x40 and +0x32e == 1) the
// stored length must not change (error 6), and if the mirror offset at +0x92 is
// set the new bytes are also copied through to +0x26+offset of the descriptor
// hanging off +0x4ac of the state block. Bytes go through the
// FUN_022d8d6c/FUN_022d8d40 accessor pair rather than plain loads and stores.

extern unsigned char FUN_022d8d6c(unsigned char *p);
extern void FUN_022d8d40(unsigned char *p, unsigned char v);

typedef struct Blk {
    char pad00[8];
    unsigned short state;  /* +0x08 */
    char pad0a[0x14];
    unsigned short len;    /* +0x1e */
    unsigned char buf[32]; /* +0x20 */
    char pad40[0x52];
    unsigned short off;    /* +0x92 */
} Blk;

int FUN_022d760c(unsigned int len, unsigned char *src)
{
    Blk *b;
    unsigned int i;
    int mirror;
    unsigned char *out;

    b = (Blk *)(*(char **)0x0380fff4 + 0x344);
    mirror = 0;

    if (len > 0x20) return 5;

    if (b->state == 0x40 &&
        *(unsigned short *)(*(char **)0x0380fff4 + 0x32e) == 1) {
        if (b->len != len) return 6;
        if (b->off != 0) mirror = 1;
    }

    for (i = 0; i < len; i++) {
        FUN_022d8d40(b->buf + i, FUN_022d8d6c(src));
        src++;
    }
    for (; i < 0x20; i++) {
        FUN_022d8d40(b->buf + i, 0);
    }

    b->len = len;

    if (mirror != 0) {
        out = *(unsigned char **)(*(char **)0x0380fff4 + 0x4ac) + 0x26 + b->off;
        for (i = 0; i < len; i++) {
            FUN_022d8d40(out + i, FUN_022d8d6c(b->buf + i));
        }
    }
    return 0;
}
