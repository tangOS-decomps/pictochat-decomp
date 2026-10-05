// decomp: module=unk_autoload_0 addr=0x0232e640 name=FUN_0232e640
extern void func_02337440(int v, void *dst, int size);

typedef struct Hdr_e640 { unsigned int flags : 8; unsigned int rest : 24; } Hdr_e640;

unsigned int FUN_0232e640(unsigned int *h, unsigned int size, unsigned int align) {
    unsigned int cur = h[0];
    unsigned int p = (align - 1 + cur) & ~(align - 1);
    unsigned int end = size + p;
    unsigned int n;
    if (end > h[1]) {
        return 0;
    }
    n = end - cur;
    if ((unsigned short)((Hdr_e640 *)h)[-1].flags & 1) {
        func_02337440(0, (void *)cur, n);
    }
    h[0] = end;
    return p;
}
