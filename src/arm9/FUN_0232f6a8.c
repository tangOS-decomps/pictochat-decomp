// decomp: module=unk_autoload_0 addr=0x0232f6a8 name=FUN_0232f6a8

// Reads up to `len` bytes of table entry `i` (0x10-byte entries hanging off
// +0x84 of G_023bf010), starting at byte offset `off`, into `buf`. Reads in
// chunks of at most the size at +0x90 through the file context at +0x34.
// Returns bytes read, -1 on bad index / seek failure, or a negative read error.

extern int G_023bf010[];
extern int FUN_02338a3c(void *ctx, int a, int b);
extern int FUN_02338a54(void *ctx, char *buf, int len);

int FUN_0232f6a8(unsigned int i, char *buf, int len, unsigned int off)
{
    char *base;
    unsigned int *ent;
    int chunk;
    char *g;
    int total;
    int n;
    g = (char *)G_023bf010[0];
    base = *(char **)(g + 0x84);
    if (i >= *(unsigned int *)(base + 8)) return -1;
    ent = (unsigned int *)(base + 0xc + i * 0x10);
    chunk = *(int *)(g + 0x90);
    if (chunk == 0) chunk = len;
    for (total = 0; total < len; ) {
        n = len - total;
        if (n > chunk) n = chunk;
        if ((unsigned int)n > ent[1] - off) n = ent[1] - off;
        if (n == 0) break;
        if (FUN_02338a3c(g + 0x34, ent[0] + off, 0) == 0) return -1;
        n = FUN_02338a54(g + 0x34, buf, n);
        if (n < 0) return n;
        total += n;
        off += n;
        buf += n;
    }
    return total;
}
