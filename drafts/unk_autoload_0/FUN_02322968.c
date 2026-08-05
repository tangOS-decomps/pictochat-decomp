// decomp: module=unk_autoload_0 addr=0x02322968 name=FUN_02322968
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x210 (Ghidra's cache says 0x1f4 - it excludes this function's trailing literal pool), thumb
// triage: noise=12 statements=96
// verify:  python tools/match.py --c <file> --func FUN_02322968 --addr 0x02322968 --size 0x210 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322968(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  uVar2 = (int)(*DAT_02322b5c & 0x8000) >> 0xf;
  if ((((*DAT_02322b60 & 0x200) == 0x200 ^ uVar2) & ~uVar2) == 0) {
    *DAT_02322b60 = DAT_02322b64 & *DAT_02322b60;
  }
  else {
    *DAT_02322b60 = *DAT_02322b60 | 0x100;
  }
  if (uVar2 == 0) {
    *DAT_02322b60 = DAT_02322b68 & *DAT_02322b60;
  }
  else {
    *DAT_02322b60 = *DAT_02322b60 | 0x200;
  }
  puVar1 = DAT_02322b60;
  if ((((*DAT_02322b60 & 2) == 2) || ((*DAT_02322b60 & 0x1000) == 0x1000)) ||
     ((int)(*DAT_02322b5c & 0x8000) >> 0xf == 0)) {
    piVar4 = FUN_0232254c();
    if ((*piVar4 << 0x16 < 0) && (piVar4 = FUN_0232254c(), -1 < *piVar4 << 0x1b)) {
      if ((int)(*DAT_02322b5c & 0x8000) >> 0xf == 0) {
        piVar4 = FUN_0232254c();
        if (*piVar4 << 0x15 < 0) {
          FUN_0232d3c4();
        }
      }
      else {
        FUN_02339374(2,0);
      }
    }
  }
  else {
    *DAT_02322b60 = *DAT_02322b60 | 0x40;
    if ((code *)puVar1[2] != (code *)0x0) {
      (*(code *)puVar1[2])();
    }
    FUN_0232d488();
    FUN_023305e8(1,1);
    FUN_02336334();
    *DAT_02322b6c = DAT_02322b70 & *DAT_02322b6c;
    FUN_023305e8(1,1);
    iVar3 = FUN_023327dc();
    if (iVar3 == 0) {
      if ((*DAT_02322b60 & 1) == 1) {
        uVar2 = 2;
      }
      else {
        uVar2 = 0;
      }
      FUN_023394e4(uVar2 | 4,0,0);
    }
    else {
      if ((*DAT_02322b60 & 1) == 1) {
        uVar2 = 2;
      }
      else {
        uVar2 = 0;
      }
      FUN_023394e4(uVar2 | 0x14,0,0);
      FUN_023327b0();
    }
    FUN_023305e8(1,1);
    FUN_023305e8(1,1);
    FUN_02336368();
    *DAT_02322b6c = *DAT_02322b6c | 0x10000;
  }
  if ((*DAT_02322b60 & 0x40) != 0x40) {
    iVar3 = FUN_0232d3fc();
    if ((iVar3 == 0) && (((*DAT_02322b74 & 1) == 0 || (iVar3 = FUN_023327b0(), iVar3 == 0)))) {
      if (((*DAT_02322b60 & 0x100) == 0x100) && ((code *)DAT_02322b60[4] != (code *)0x0)) {
        (*(code *)DAT_02322b60[4])();
      }
      return;
    }
    if ((code *)DAT_02322b60[2] != (code *)0x0) {
      (*(code *)DAT_02322b60[2])();
    }
    FUN_02332274();
    return;
  }
  FUN_0232d3fc();
  FUN_0232d488();
  iVar3 = FUN_0232d3fc();
  if ((iVar3 != 0) || (((*DAT_02322b74 & 1) != 0 && (iVar3 = FUN_023327b0(), iVar3 != 0)))) {
    FUN_023393e0();
  }
  if ((code *)DAT_02322b60[3] != (code *)0x0) {
    (*(code *)DAT_02322b60[3])();
  }
  *DAT_02322b60 = *DAT_02322b60 & 0xffffffbf;
  return;
}

