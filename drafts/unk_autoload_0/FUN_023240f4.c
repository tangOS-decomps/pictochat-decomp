// decomp: module=unk_autoload_0 addr=0x023240f4 name=FUN_023240f4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x52 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=18
// verify:  python tools/match.py --c <file> --func FUN_023240f4 --addr 0x023240f4 --size 0x58 --module unk_autoload_0 --version 2.0/sp1


void FUN_023240f4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = **(ushort **)(param_1 + 0x2c);
  uVar2 = (*(ushort **)(param_1 + 0x2c))[1];
  uVar4 = (uint)(uVar1 >> 8) * 2 + (uint)(uVar2 >> 8);
  iVar3 = FUN_0232310c(param_1,*(int *)(DAT_02324148 + 4) +
                               ((uVar1 & 0xff) * 2 + (uVar2 & 0xff)) / 2 + 3,
                       *(int *)(DAT_02324148 + 8) + uVar4 / 2 + -3,uVar4,param_4);
  if (iVar3 == 0) {
    iVar3 = **(int **)(param_1 + 8) + (uint)*(ushort *)(*(int **)(param_1 + 8) + 3) * 8;
  }
  *(int *)(param_1 + 0x2c) = iVar3;
  return;
}

