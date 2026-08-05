// decomp: module=unk_autoload_0 addr=0x02322df0 name=FUN_02322df0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c, thumb
// triage: noise=1 statements=16
// verify:  python tools/match.py --c <file> --func FUN_02322df0 --addr 0x02322df0 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_02322df0(undefined1 *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  *param_1 = 10;
  for (uVar1 = 1; uVar1 < 6; uVar1 = uVar1 + 1) {
    param_1[uVar1] = 0;
  }
  if (0x10 < param_2) {
    param_2 = 0x10;
  }
  for (iVar2 = 0; iVar2 < param_2; iVar2 = iVar2 + 1) {
    param_1[iVar2 + 6] = 0x1c;
  }
  return;
}

