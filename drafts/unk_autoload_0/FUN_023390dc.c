// decomp: module=unk_autoload_0 addr=0x023390dc name=FUN_023390dc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=26
// verify:  python tools/match.py --c <file> --func FUN_023390dc --addr 0x023390dc --size 0x5c --module unk_autoload_0 --version 2.0/sp1


void FUN_023390dc(void)

{
  short *psVar1;
  int iVar2;
  undefined4 uVar3;
  
  psVar1 = DAT_0233912c;
  if (*DAT_0233912c == 0) {
    *DAT_0233912c = 1;
    psVar1[0x16] = 0;
    psVar1[0x17] = 0;
    psVar1[0x18] = 0;
    psVar1[0x19] = 0;
    FUN_023381f8();
    iVar2 = FUN_023382f8(8,1);
    while (iVar2 == 0) {
      FUN_02332d10(100);
      iVar2 = FUN_023382f8(8,1);
    }
    FUN_023382ac(8,DAT_02339130);
    psVar1 = DAT_0233912c;
    uVar3 = *DAT_02339134;
    *(undefined4 *)(DAT_0233912c + 4) = uVar3;
    *(undefined4 *)(psVar1 + 2) = uVar3;
  }
  return;
}

