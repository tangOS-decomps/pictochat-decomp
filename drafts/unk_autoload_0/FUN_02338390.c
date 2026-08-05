// decomp: module=unk_autoload_0 addr=0x02338390 name=FUN_02338390
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xbc (Ghidra's cache says 0xae - it excludes this function's trailing literal pool), thumb
// triage: noise=15 statements=61
// verify:  python tools/match.py --c <file> --func FUN_02338390 --addr 0x02338390 --size 0xbc --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_02338390(void)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint in_r3;
  code *pcVar5;
  uint uVar6;
  
  iVar2 = DAT_02338444;
  puVar1 = DAT_02338440;
  uVar6 = in_r3;
  while( true ) {
    if ((*puVar1 & 0x4000) == 0) {
      FUN_02332080();
      uVar3 = _DAT_04100000;
      if ((*puVar1 & 0x100) == 0) {
        uVar6 = _DAT_04100000;
        FUN_02332094();
        iVar4 = 0;
        in_r3 = uVar3;
      }
      else {
        FUN_02332094();
        iVar4 = -4;
      }
    }
    else {
      *puVar1 = *puVar1 | 0xc000;
      iVar4 = -3;
    }
    if (iVar4 == -4) break;
    if ((iVar4 != -3) && (uVar3 = in_r3 & 0x1f, uVar3 != 0)) {
      pcVar5 = *(code **)(iVar2 + uVar3 * 4);
      if (pcVar5 == (code *)0x0) {
        if (-1 < (int)(in_r3 << 0x1a)) {
          in_r3 = in_r3 | 0x20;
          uVar6 = in_r3;
          if ((*puVar1 & 0x4000) == 0) {
            FUN_02332080();
            if ((*puVar1 & 2) == 0) {
              *DAT_02338448 = in_r3;
              FUN_02332094();
            }
            else {
              FUN_02332094();
            }
          }
          else {
            *puVar1 = *puVar1 | 0xc000;
          }
        }
      }
      else {
        (*pcVar5)(uVar3,in_r3 >> 6,(in_r3 & 0x3f) >> 5,pcVar5,uVar6);
      }
    }
  }
  return;
}

