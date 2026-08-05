// decomp: module=arm7 addr=0x022de130 name=FUN_022de130
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x168 (Ghidra's cache says 0x154 - it excludes this function's trailing literal pool), arm
// triage: noise=11 statements=44
// verify:  python tools/match.py --c <file> --func FUN_022de130 --addr 0x022de130 --size 0x168 --module arm7 --version 2.0/sp1


void FUN_022de130(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  ushort *puVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  
  if ((*(ushort *)(param_2 + 0x24) & 0x4000) == 0) {
    if (*(ushort *)(param_2 + 0xc) == DAT_022de288) {
      FUN_022d8c98(param_1,param_2 + 0x18,*(ushort *)(param_2 + 0x16) + 0x24);
    }
    else {
      FUN_022d8cb8(param_1,param_2 + 0x18,*(undefined4 *)(param_2 + 0x3c),
                   *(undefined2 *)(param_2 + 0x16),param_4);
    }
  }
  else {
    if (*(short *)(*DAT_022de284 + 0x350) == 3) {
      FUN_022d81e8();
    }
    if (*(ushort *)(param_2 + 0xc) == DAT_022de288) {
      FUN_022d8cfc(param_1,param_2 + 0x18,param_2 + 0x3c,*(undefined2 *)(param_2 + 0x16));
    }
    else {
      FUN_022d8cfc(param_1,param_2 + 0x18,*(undefined4 *)(param_2 + 0x3c),
                   *(undefined2 *)(param_2 + 0x16));
    }
    puVar2 = DAT_022de28c;
    piVar1 = DAT_022de284;
    *(ushort *)(param_1 + 0x24) = *DAT_022de28c + *DAT_022de28c * 0x100;
    *(ushort *)(param_1 + 0x26) = *puVar2 & 0xff | *(short *)(*piVar1 + 0x336) << 0xe;
    if ((*(ushort *)(*piVar1 + 0x690) & 8) != 0) {
      puVar4 = (undefined2 *)(param_1 + (uint)*(ushort *)(param_2 + 0x22) + 5 & 0xfffffffe);
      *puVar4 = 0;
      puVar4[1] = 0;
    }
  }
  uVar3 = DAT_022de294;
  if ((*(ushort *)(*DAT_022de284 + 0x690) & 4) != 0) {
    puVar4 = (undefined2 *)(param_1 + (uint)*(ushort *)(param_2 + 0x22) + 0xb & 0xfffffffc);
    *puVar4 = (short)DAT_022de290;
    puVar4[1] = (short)uVar3;
  }
  return;
}

