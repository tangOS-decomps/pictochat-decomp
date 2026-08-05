// decomp: module=arm7 addr=0x022d8500 name=FUN_022d8500
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb4 (Ghidra's cache says 0xb0 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=29  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d8500 --addr 0x022d8500 --size 0xb4 --module arm7 --version 2.0/sp1


void FUN_022d8500(int param_1,ushort *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  *param_2 = 0;
  param_2[1] = 0;
  uVar2 = FUN_022d8d6c(param_1 + 1);
  iVar1 = DAT_022d85b0;
  for (uVar5 = 0; uVar5 < uVar2; uVar5 = uVar5 + 1) {
    uVar3 = FUN_022d8d6c(param_1 + 2 + uVar5);
    uVar4 = (uVar3 & 0x7f) - 1;
    if ((uVar4 < 0x78) && (uVar4 = (uint)*(ushort *)(iVar1 + uVar4 * 2), uVar4 != 0xff)) {
      param_2[1] = param_2[1] | (ushort)(1 << (uVar4 & 0xff));
      if ((uVar3 & 0x80) != 0) {
        *param_2 = *param_2 | (ushort)(1 << (uVar4 & 0xff));
      }
    }
    else {
      param_2[1] = param_2[1] | 0x8000;
      if ((uVar3 & 0x80) != 0) {
        *param_2 = *param_2 | 0x8000;
      }
    }
  }
  return;
}

