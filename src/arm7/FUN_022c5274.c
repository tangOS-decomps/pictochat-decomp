// decomp: module=arm7 addr=0x022c5274 name=FUN_022c5274
// flags: -O4,s -noThumb
typedef struct Sched5274 {
    char pad[0x48];
    int f48;
    char pad2[0x5c - 0x4c];
    void *f5c;
} Sched5274;

typedef struct SchedRoot {
    Sched5274 *cur;
} SchedRoot;

typedef struct Sys03804f68 {
    char pad[8];
    SchedRoot *f8;
} Sys03804f68;

extern Sys03804f68 G_03804f68;

extern int FUN_022c6d40(void);
extern void FUN_022c4c84(void *a, Sched5274 *b);
extern void FUN_022c4e28(void);
extern void FUN_022c6d54(int state);

void FUN_022c5274(void *arg) {
    int state = FUN_022c6d40();
    Sched5274 *cur = G_03804f68.f8->cur;
    if (arg != 0) {
        cur->f5c = arg;
        FUN_022c4c84(arg, cur);
    }
    cur->f48 = 0;
    FUN_022c4e28();
    FUN_022c6d54(state);
}
