// decomp: module=unk_autoload_0 addr=0x02337930 name=FUN_02337930
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x26, thumb
// triage: noise=10 statements=15
// verify:  python tools/match.py --c <file> --func FUN_02337930 --addr 0x02337930 --size 0x26 --module unk_autoload_0 --version 2.0/sp1


void FUN_02337930(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_02337ad0(1);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 4) = param_1;
    *(undefined4 *)(iVar1 + 8) = param_2;
    *(undefined4 *)(iVar1 + 0xc) = param_3;
    *(undefined4 *)(iVar1 + 0x10) = param_4;
    *(undefined4 *)(iVar1 + 0x14) = param_5;
    FUN_02337b2c();
  }
  return;
}

