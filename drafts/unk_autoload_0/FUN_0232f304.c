// decomp: module=unk_autoload_0 addr=0x0232f304 name=FUN_0232f304
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x94 (Ghidra's cache says 0x8c - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=42
// verify:  python tools/match.py --c <file> --func FUN_0232f304 --addr 0x0232f304 --size 0x94 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232f304(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 in_r3;
  bool bVar4;
  
  piVar1 = DAT_0232f390;
  if (*DAT_0232f390 != 0) {
    bVar4 = DAT_0232f390[0xb] < 0;
    if (bVar4) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1 << (DAT_0232f390[0xb] & 0xffU);
    }
    FUN_02337784(DAT_0232f390[9],DAT_0232f390[10],iVar3,0,in_r3);
    if (!bVar4) {
      uVar2 = FUN_02337cac();
      FUN_02337b54(1);
      FUN_02337c68(uVar2);
      uVar2 = DAT_0232f394;
      do {
        iVar3 = FUN_023312a0(uVar2,0,0);
      } while (iVar3 != 0);
    }
    if (piVar1[10] != 0) {
      FUN_0232e868(piVar1[10]);
    }
    if (piVar1[8] != 0) {
      FUN_0232e830();
    }
    if (!bVar4) {
      FUN_0232e8a4(piVar1[0xb]);
    }
    if (piVar1[1] == 1) {
      FUN_023378c4(0,0,0,0);
    }
    *piVar1 = 0;
  }
  return;
}

