// decomp: module=arm7 addr=0x022c0f00 name=FUN_022c0f00
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x78 (Ghidra's cache says 0x6c - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=30
// verify:  python tools/match.py --c <file> --func FUN_022c0f00 --addr 0x022c0f00 --size 0x78 --module arm7 --version 2.0/sp1


uint FUN_022c0f00(int param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar4 = *DAT_022c0f6c;
  FUN_022c48a4(DAT_022c0f70);
  uVar3 = DAT_022c0f74;
  param_1 = param_1 * 2;
  uVar5 = (uint)*(ushort *)(iVar4 + param_1);
  if (uVar5 != DAT_022c0f74) {
    iVar6 = iVar4 + 0xbc;
    *(undefined2 *)(iVar6 + uVar5 * 8 + 2) = 0;
    uVar1 = *(ushort *)(iVar6 + uVar5 * 8);
    uVar2 = (undefined2)uVar3;
    if (uVar1 == uVar3) {
      *(undefined2 *)(iVar4 + param_1) = uVar2;
      *(undefined2 *)(iVar4 + param_1 + 8) = uVar2;
    }
    else {
      *(ushort *)(iVar4 + param_1) = uVar1;
      *(undefined2 *)(iVar6 + uVar5 * 8) = uVar2;
    }
  }
  FUN_022c486c();
  return uVar5;
}

