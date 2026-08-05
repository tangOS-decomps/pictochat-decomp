//cpp
// decomp: module=unk_autoload_0 addr=0x0232e188 name=FUN_0232e188

#pragma thumb on
extern "C" {
int FUN_0232e188(unsigned short *o, char *t) {
    if (t == 0) return ((int *)o)[1];
    return *(int *)(t + o[5]);
}
}
