// decomp: module=arm7 addr=0x022d6c8c name=FUN_022d6c8c
// flags: -noThumb -O4,s

struct S_022d6c8c {
    int f0;
    int f4;
    unsigned short f8;
    unsigned short fa;
};

void FUN_022d6c8c(struct S_022d6c8c *s, unsigned short val) {
    s->f0 = -1;
    s->f4 = -1;
    s->f8 = 0;
    s->fa = val;
}
