//cpp
// decomp: module=unk_autoload_0 addr=0x0232a4c8 name=FUN_0232a4c8

// One step of the linear congruential generator whose state is at +0x4c of
// G_023bd698: state = 0x5eedf715 * state + 0x1b0cb173.

#pragma thumb on
extern "C" {
extern int G_023bd698[];
void FUN_0232a4c8(void)
{
    G_023bd698[0x13] = 0x5eedf715 * G_023bd698[0x13] + 0x1b0cb173;
}
}
