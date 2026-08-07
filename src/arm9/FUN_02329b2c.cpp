//cpp
// NONMATCHING: PR validator reports 2 differing words at its authoritative merge target (div=2). Logic retained as a draft; not byte-exact there.
// Counts as decompiled, not matched.
// decomp: module=unk_autoload_0 addr=0x02329b2c name=FUN_02329b2c
// Candidate reconstructed from the complete getter before the next Thumb entry.

#pragma thumb on
extern "C" {
extern unsigned char G_023bd60c[];

unsigned char FUN_02329b2c(void) {
    return G_023bd60c[2];
}
}
