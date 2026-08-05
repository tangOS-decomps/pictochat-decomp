// decomp: module=unk_autoload_0 addr=0x0232ef38 name=FUN_0232ef38
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x3e - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=19
// verify:  python tools/match.py --c <file> --func FUN_0232ef38 --addr 0x0232ef38 --size 0x44 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ef38(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  *(undefined4 *)(param_1 + 0x44) = param_2;
  iVar1 = DAT_0232ef78;
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x50)) {
    do {
      uVar4 = (uint)*(byte *)(param_1 + iVar3 + 0x54);
      uVar2 = FUN_02337f4c(*(int *)(param_1 + 0x44) + *(int *)(iVar1 + uVar4 * 8 + 4));
      FUN_02337848(1 << uVar4,uVar2 & 0xff,(int)uVar2 >> 8);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x50));
  }
  return;
}

