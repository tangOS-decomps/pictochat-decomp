//cpp
// decomp: module=unk_autoload_0 addr=0x0232be80 name=FUN_0232be80
extern "C" {
typedef struct Pkt_be80 {
    unsigned short type;
    unsigned short len;
    unsigned char id;
    unsigned char pad5;
    unsigned short dst;
    unsigned char pad8[4];
    unsigned char arg;
    unsigned char padd[7];
} Pkt_be80;

extern char G_023bd814[];
extern unsigned char FUN_0232a4e8(void);
extern void func_02337584(void *src, void *dst, int size);
extern void FUN_0232c100(int a, void *b, int c, int d, void (*cb)(void));
extern void FUN_0232bf8c(void);

void FUN_0232be80(unsigned char arg) {
    Pkt_be80 p;
    p.type = 3;
    p.len = 0x14;
    p.id = FUN_0232a4e8();
    p.dst = 0xffff;
    p.arg = arg;
    func_02337584(&p, *(void **)(G_023bd814 + 0xc), 0x14);
    FUN_0232c100(0xd, *(void **)(G_023bd814 + 0xc), 0x14, 1, FUN_0232bf8c);
}
}
