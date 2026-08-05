//cpp
// decomp: module=unk_autoload_0 addr=0x02339024 name=FUN_02339024

#pragma thumb on
extern "C" {
extern char G_023c3528[];
void FUN_02339024(int mask) {
    while (*(volatile unsigned short *)(G_023c3528 + 0x3a) & mask) ;
}
}
