// decomp: module=arm7 addr=0x022d531c name=FUN_022d531c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xf0 (Ghidra's cache says 0xe4 - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=42
// verify:  python tools/match.py --c <file> --func FUN_022d531c --addr 0x022d531c --size 0xf0 --module arm7 --version 2.0/sp1


void FUN_022d531c(ushort param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  ushort uVar6;
  int iVar7;
  bool bVar8;
  undefined1 auStack_218 [512];
  
  iVar7 = *(int *)(DAT_022d5400 + 0x550);
  func_0x037cb520();
  func_0x037cb534();
  param_1 = param_1 & *(ushort *)(iVar7 + 0x182);
  uVar1 = *(ushort *)(iVar7 + 0x3a);
  uVar2 = *DAT_022d5404;
  uVar6 = *(ushort *)(iVar7 + 0x6a);
  iVar4 = thunk_EXT_FUN_037fef94(param_1);
  if ((int)(uint)*(ushort *)(iVar7 + 0x72) < (int)((uVar1 + 0xc) * iVar4 + 0x29 & 0xffffffe0)) {
    func_0x037c9c2c(2);
    FUN_022cfa90();
  }
  else {
    bVar8 = *(short *)(iVar7 + 0x62) != 1;
    sVar3 = 1;
    if (bVar8) {
      sVar3 = *(short *)(iVar7 + 100);
    }
    if (bVar8 && sVar3 != 1) {
      uVar6 = uVar6 & 0x7fff;
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_022d5c68(*(undefined2 *)(iVar7 + 0x6e),*(undefined2 *)(iVar7 + 0x6c),param_1,
                           *(undefined2 *)(iVar7 + 0x40));
      uVar6 = uVar6 | 0x8000;
    }
    FUN_022d0350(auStack_218,DAT_022d5408,0,0,param_1,uVar5,uVar2,0,uVar6,0);
  }
  return;
}

