//cpp
// decomp: module=unk_autoload_0 addr=0x0233999c name=FUN_0233999c
// verify: python tools/match.py --c src/arm9/FUN_0233999c.cpp --func FUN_0233999c --addr 0x0233999c --size 0x24 --module unk_autoload_0 --version 2.0/sp1

// Records the request verdict at G_023c35a0+0x24 and runs the recovery path
// when it came back zero.

#pragma thumb on
extern "C" {
extern int FUN_02339948(int, int, void *, int);
extern void FUN_02339e48(void);
extern void FUN_02339e54(void);
extern int G_023c35a0[];
int FUN_0233999c(int a, int b)
{
    int rc = FUN_02339948(a, b, (void *)FUN_02339e48, 0);

    G_023c35a0[9] = rc;
    if (rc == 0) FUN_02339e54();
    return G_023c35a0[9];
}
}
