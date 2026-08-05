//cpp
// decomp: module=unk_autoload_0 addr=0x02329994 name=FUN_02329994

// Returns the address of G_023bd604 when FUN_0232996c reports non-zero, else
// null. The pool word is the address itself, not its contents.

#pragma thumb on
extern "C" {
extern int FUN_0232996c(void);
extern int G_023bd604[];
void *FUN_02329994(void)
{
    if (FUN_0232996c() == 0) return 0;
    return G_023bd604;
}
}
