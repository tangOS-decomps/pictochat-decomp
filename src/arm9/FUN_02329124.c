// decomp: module=unk_autoload_0 addr=0x02329124 name=FUN_02329124
extern int FUN_0232996c(int);

int FUN_02329124(int a) {
    int r = FUN_0232996c(a);
    switch (r) {
    case 0xc:
    case 0xd:
        return 1;
    case 0xe:
        return 2;
    default:
        return 0;
    }
}
