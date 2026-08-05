// decomp: module=unk_autoload_0 addr=0x02330728 name=FUN_02330728
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x54 - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=35
// verify:  python tools/match.py --c <file> --func FUN_02330728 --addr 0x02330728 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


void FUN_02330728(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = DAT_02330780;
  iVar2 = 0;
  puVar3 = DAT_0233077c;
  do {
    if ((param_1 & 1) != 0) {
      puVar4 = (undefined4 *)0x0;
      if ((iVar2 < 8) || (0xb < iVar2)) {
        if ((iVar2 < 3) || (6 < iVar2)) {
          *puVar3 = param_2;
        }
        else {
          puVar4 = (undefined4 *)(iVar1 + (iVar2 + 1) * 0xc);
        }
      }
      else {
        puVar4 = (undefined4 *)(iVar1 + (iVar2 + -8) * 0xc);
      }
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = param_2;
        puVar4[2] = 0;
        puVar4[1] = 1;
      }
    }
    iVar2 = iVar2 + 1;
    param_1 = param_1 >> 1;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 0x16);
  return;
}

