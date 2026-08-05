// decomp: module=unk_autoload_0 addr=0x023388b4 name=FUN_023388b4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54, thumb
// triage: noise=3 statements=28
// verify:  python tools/match.py --c <file> --func FUN_023388b4 --addr 0x023388b4 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


void FUN_023388b4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = *(undefined4 *)(param_1 + 8);
  while( true ) {
    if (param_1 == 0) {
      return;
    }
    uVar1 = FUN_02332080();
    uVar3 = *(uint *)(param_1 + 0xc);
    *(uint *)(param_1 + 0xc) = uVar3 | 0x40;
    if ((uVar3 & 4) != 0) {
      FUN_02330f6c(param_1 + 0x18);
      param_1 = 0;
    }
    FUN_02332094(uVar1);
    if (param_1 == 0) break;
    iVar2 = FUN_02338510(param_1,*(uint *)(param_1 + 0xc) >> 8 & 0xff);
    if (iVar2 == 0x100) {
      return;
    }
    param_1 = FUN_0233879c(uVar4,1);
  }
  return;
}

