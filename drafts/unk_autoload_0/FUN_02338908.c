// decomp: module=unk_autoload_0 addr=0x02338908 name=FUN_02338908
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54, thumb
// triage: noise=3 statements=21
// verify:  python tools/match.py --c <file> --func FUN_02338908 --addr 0x02338908 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


void FUN_02338908(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(param_1 + 8);
  uVar1 = FUN_02332080();
  if ((*(uint *)(param_1 + 0xc) & 0x40) == 0) {
    do {
      FUN_02330f38(param_1 + 0x18);
    } while ((*(uint *)(param_1 + 0xc) & 0x40) == 0);
  }
  FUN_02332094(uVar1);
  uVar1 = FUN_02338510(param_1,*(uint *)(param_1 + 0xc) >> 8 & 0xff);
  FUN_0233846c(param_1,uVar1);
  iVar2 = FUN_0233879c(uVar3,1);
  if (iVar2 != 0) {
    FUN_023388b4();
  }
  return;
}

