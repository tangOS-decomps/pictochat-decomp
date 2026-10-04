// decomp: module=unk_autoload_0 addr=0x023300a0 name=FUN_023300a0
typedef struct Obj_00a0 {
    unsigned char pad[0x118];
    int active : 1;
    unsigned char pad2[0x170 - 0x11c];
    void (*fn)(struct Obj_00a0 *o);
} Obj_00a0;

extern char G_023c0750[];
extern char G_023bf050[];
extern void FUN_023300ec(Obj_00a0 *o);
extern void FUN_02330108(void *list, Obj_00a0 *o);
extern void FUN_02330004(Obj_00a0 *o);

void FUN_023300a0(Obj_00a0 *o) {
    if (o->active) {
        FUN_023300ec(o);
        o->fn(o);
        FUN_02330108(G_023c0750, o);
        if (*(char **)(G_023bf050 + 4) != 0) {
            FUN_02330108(*(char **)(G_023bf050 + 4) + 0x10e0, o);
        }
        FUN_02330004(o);
    }
}
