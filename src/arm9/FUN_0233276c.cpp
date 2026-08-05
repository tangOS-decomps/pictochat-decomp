//cpp
// decomp: module=unk_autoload_0 addr=0x0233276c name=FUN_0233276c

// True when the halfword at 0x02fffc30 is not 0xffff. The sentinel comes from a
// pool word, not an immediate.

#pragma thumb on
extern "C" {
int FUN_0233276c(void)
{
    if (*(unsigned short *)0x02fffc30 != 0xffff) return 1;
    return 0;
}
}
