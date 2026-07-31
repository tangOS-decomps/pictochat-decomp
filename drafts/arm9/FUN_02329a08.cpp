// decomp: module=unk_autoload_0 addr=0x02329a08 name=FUN_02329a08
// Another instance of Ghidra's cached size stopping mid-jump-table (see
// FUN_02329270's comment) - cached size was 0x2a, true size 0x32. Note
// this one does NOT extend all the way to the next function's first byte
// (0x34) - the 2 bytes in between are inter-function alignment padding
// that doesn't belong to this function's own symbol span (confirmed: this
// function's own isolated compile is a zero-mismatch match at 0x32, and
// stays wrong at 0x34 no matter what). Don't assume "true size = next
// function's address" without checking.
int FUN_02329a08(void *p)
{
    unsigned char v;
    if (p == 0) goto def;
    v = *((unsigned char *)p + 0xa);
    switch (v) {
        case 0: return 0;
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
    }
def:
    return 5;
}
