// decomp: module=unk_autoload_0 addr=0x0232b220 name=FUN_0232b220
typedef struct Ent7b4 {
    unsigned short a;
    unsigned short hi;
    unsigned short lo;
} Ent7b4;
extern char G_023bd698[];
extern volatile Ent7b4 G_023bd7b4[];
/* The same table viewed from its hi and lo columns. */
extern volatile Ent7b4 G_023bd7b6[];
extern volatile Ent7b4 G_023bd7b8[];

int FUN_0232b220(void) {
    int i;
    int n = 1;
    unsigned int key = (G_023bd7b6[*(volatile unsigned short *)(G_023bd698 + 0xc)].a << 16) |
                       G_023bd7b8[*(volatile unsigned short *)(G_023bd698 + 0xc)].a;
    volatile Ent7b4 *e = G_023bd7b4;
    for (i = 0; i < 0x10; i++, e++) {
        if (((e->hi << 16) | e->lo) > key) {
            n++;
        }
    }
    return n;
}
