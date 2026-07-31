//cpp
extern "C" {
// decomp: module=arm7 addr=0x022d1878 name=FUN_022d1878
int FUN_022d1878(int a) {
    int v = a >> 2;
    if ((a & 2) == 0) v += 0x19;
    return v & 0xff;
}

}
