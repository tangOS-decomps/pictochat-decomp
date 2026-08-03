extern "C" {
// decomp: module=unk_autoload_0 addr=0x023215d0 name=FUN_023215d0
struct S {
    char pad[0x10];
    short flag;
    char pad2[2];
    void *ptr;
};
extern struct S G;
extern int G2;
void FUN_023215d0(void) {
    G.flag = 1;
    G.ptr = &G2;
}

}
