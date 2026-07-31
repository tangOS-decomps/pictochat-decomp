//cpp
extern "C" {
// decomp: module=arm7 addr=0x022cfa7c name=FUN_022cfa7c
int FUN_022cfa7c(int a) {
    int v = a >> 2;
    if ((a & 2) == 0) v += 0x19;
    return v & 0xff;
}

}
