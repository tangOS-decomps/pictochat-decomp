//cpp
// decomp: module=unk_autoload_0 addr=0x02339794 name=FUN_02339794

// Reads bit 0 of POWCNT2 (0x04000304) as a 0/1 flag.

#pragma thumb on
extern "C" {
int FUN_02339794(void)
{
    return (*(volatile unsigned short *)0x04000304 & 1) != 0;
}
}
