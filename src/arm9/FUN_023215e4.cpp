// decomp: module=unk_autoload_0 addr=0x023215e4 name=FUN_023215e4
struct S {
    char pad[0x30];
    short flag;
    char pad2[2];
    void *ptr;
};
extern struct S G;
extern int G2;
extern int G3[];
int *FUN_023215e4(void) {
    G.flag = 0;
    G.ptr = &G2;
    return G3;
}
