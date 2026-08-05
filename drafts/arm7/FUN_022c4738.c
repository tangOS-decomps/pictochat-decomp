// decomp: module=arm7 addr=0x022c4738 name=FUN_022c4738
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x9c (Ghidra's cache says 0x90 - it excludes this function's trailing literal pool), arm
// triage: noise=8 statements=39
// verify:  python tools/match.py --c <file> --func FUN_022c4738 --addr 0x022c4738 --size 0x9c --module arm7 --version 2.0/sp1


void FUN_022c4738(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar3 = DAT_022c47d0;
  puVar2 = DAT_022c47cc;
  iVar1 = DAT_022c47c8;
  iVar4 = 0;
  do {
    if ((param_1 & 1) != 0) {
      if ((iVar4 < 8) || (0xb < iVar4)) {
        if ((iVar4 < 3) || (6 < iVar4)) {
          puVar5 = puVar2;
          if (iVar4 != 0) {
            *(undefined4 *)(iVar1 + iVar4 * 4) = param_2;
            puVar5 = (undefined4 *)0x0;
          }
        }
        else {
          puVar5 = (undefined4 *)((iVar4 + 1) * 0xc + iVar3);
        }
      }
      else {
        puVar5 = (undefined4 *)((iVar4 + -8) * 0xc + iVar3);
      }
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = param_2;
        puVar5[1] = 1;
        puVar5[2] = 0;
      }
    }
    iVar4 = iVar4 + 1;
    param_1 = param_1 >> 1;
  } while (iVar4 < 0x19);
  return;
}

