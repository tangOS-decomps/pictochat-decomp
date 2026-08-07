//cpp
// NONMATCHING: PR validator reports 3 differing words at its authoritative merge target (div=3). Logic retained as a draft; not byte-exact there.
// Counts as decompiled, not matched.
// decomp: module=unk_autoload_0 addr=0x0232d108 name=FUN_0232d108
// Candidate reconstructed from the Thumb veneer at 0x0232d108.

#pragma thumb on
extern "C" {
extern void FUN_0233831c(int, int, int);

void FUN_0232d108(int value) {
    FUN_0233831c(2, value, 0);
}
}
