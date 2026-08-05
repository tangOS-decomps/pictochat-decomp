// decomp: module=unk_autoload_0 addr=0x02329668 name=FUN_02329668
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x70 (Ghidra's cache says 0x62 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=25
// verify:  python tools/match.py --c <file> --func FUN_02329668 --addr 0x02329668 --size 0x70 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329668(undefined4 param_1,short param_2,int param_3,int param_4)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  
  iVar3 = FUN_02321d04(param_4);
  iVar4 = FUN_023346a8(iVar3,DAT_023296cc);
  FUN_02334610(param_1,iVar3);
  if (param_3 != 0) {
    iVar3 = FUN_023346a8(param_1,DAT_023296cc);
    if (iVar3 != 0) {
      FUN_02334610(iVar3,param_3);
    }
    FUN_0233465c(param_1,iVar4 + 2);
  }
  psVar5 = (short *)FUN_023346a8(param_1,DAT_023296d0);
  uVar2 = DAT_023296d0;
  sVar1 = (short)DAT_023296d4;
  for (; psVar5 != (short *)0x0; psVar5 = (short *)FUN_023346a8(psVar5 + 1,uVar2)) {
    *psVar5 = param_2 + sVar1;
  }
  return;
}

