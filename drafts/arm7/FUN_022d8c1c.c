// decomp: module=arm7 addr=0x022d8c1c name=FUN_022d8c1c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7c (Ghidra's cache says 0x74 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=19
// verify:  python tools/match.py --c <file> --func FUN_022d8c1c --addr 0x022d8c1c --size 0x7c --module arm7 --version 2.0/sp1


void FUN_022d8c1c(int param_1,int param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_3 + 1U & 0xfffffffe;
  if (DAT_022d8c90 < param_2 + uVar1) {
    iVar2 = uVar1 - (DAT_022d8c90 - param_2);
    uVar1 = DAT_022d8c90 - param_2;
  }
  else {
    iVar2 = 0;
  }
  func_0x037cb78c(param_2,param_1,uVar1,DAT_022d8c90,param_4);
  if (iVar2 != 0) {
    func_0x037cb78c((param_2 + uVar1) - (uint)*(ushort *)(*DAT_022d8c94 + 0x3de),param_1 + uVar1,
                    iVar2,param_2 + uVar1,param_4);
  }
  return;
}

