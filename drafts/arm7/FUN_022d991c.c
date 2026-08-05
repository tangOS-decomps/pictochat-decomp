// decomp: module=arm7 addr=0x022d991c name=FUN_022d991c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa8 (Ghidra's cache says 0xa4 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=33
// verify:  python tools/match.py --c <file> --func FUN_022d991c --addr 0x022d991c --size 0xa8 --module arm7 --version 2.0/sp1


uint FUN_022d991c(ushort *param_1)

{
  short *psVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  piVar2 = DAT_022d99c0;
  if ((*param_1 & 1) == 0) {
    iVar4 = *DAT_022d99c0;
    if (1 < *(ushort *)(iVar4 + 0x52c)) {
      uVar5 = 0;
      psVar1 = *(short **)(iVar4 + 0x31c);
      for (uVar3 = 1; uVar3 < *(ushort *)(iVar4 + 0x322); uVar3 = uVar3 + 1) {
        if (psVar1[0xe] != 0) {
          iVar4 = FUN_022d84b0((undefined4 *)(psVar1 + 0x10),(undefined4 *)param_1);
          if (iVar4 != 0) {
            return uVar3;
          }
          iVar4 = *piVar2;
          uVar5 = uVar5 + 1;
          if (*(ushort *)(iVar4 + 0x52c) <= uVar5) break;
        }
        psVar1 = psVar1 + 0xe;
      }
    }
    uVar3 = 0xff;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

