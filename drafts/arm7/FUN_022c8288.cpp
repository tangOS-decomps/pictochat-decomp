// decomp: module=arm7 addr=0x022c8288 name=FUN_022c8288
struct S {
    char pad[3];
    unsigned char flag : 1;
};
int FUN_022c8288(struct S *p) {
    return p->flag;
}
