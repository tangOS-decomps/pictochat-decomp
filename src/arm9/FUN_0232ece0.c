// decomp: module=unk_autoload_0 addr=0x0232ece0 name=FUN_0232ece0
extern void FUN_02330584(void *p);
extern void FUN_02330590(void *p, int v, int c);

void FUN_0232ece0(unsigned char *p) {
    p[0x2e] = 0;
    p[0x2d] = 0;
    p[0x2f] = 0;
    *(unsigned short *)(p + 0x34) = 0;
    *(unsigned short *)(p + 0x3e) = 0;
    p[0x40] = 0x7f;
    p[0x41] = 0x7f;
    FUN_02330584(p + 0x1c);
    FUN_02330590(p + 0x1c, 0x7f00, 1);
}
