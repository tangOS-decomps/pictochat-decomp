// decomp: module=unk_autoload_0 addr=0x02338df8 name=FUN_02338df8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x17c (Ghidra's cache says 0x16e - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=66
// verify:  python tools/match.py --c <file> --func FUN_02338df8 --addr 0x02338df8 --size 0x17c --module unk_autoload_0 --version 2.0/sp1


undefined4
FUN_02338df8(undefined2 *param_1,uint param_2,uint param_3,uint param_4,ushort param_5,
            ushort param_6,ushort param_7,ushort param_8,ushort param_9)

{
  ushort *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  if ((((0xfff < param_2) || (0xfff < param_3)) || (0xfff < param_6)) || (0xfff < param_7)) {
    return 1;
  }
  if (((0xff < param_4) || (0xff < param_8)) || ((0xbf < param_5 || (0xbf < param_9)))) {
    return 1;
  }
  if (((param_4 == param_8) || (param_5 == param_9)) ||
     ((param_2 == param_6 || (param_3 == param_7)))) {
    return 1;
  }
  uVar4 = FUN_02332080();
  puVar1 = DAT_02338f68;
  *DAT_02338f68 = 0;
  *(uint *)(puVar1 + 8) = (param_2 - param_6) * 0x100;
  *(uint *)(puVar1 + 0xc) = param_4 - param_8;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  do {
  } while (((uint)*puVar1 & (uint)puVar1 >> 0xb) != 0);
  iVar5 = *DAT_02338f6c;
  *puVar1 = 0;
  DAT_02338f6c[-4] = (param_3 - param_7) * 0x100;
  piVar2 = DAT_02338f6c;
  DAT_02338f6c[-2] = (uint)param_5 - (uint)param_9;
  piVar2[-1] = 0;
  iVar3 = DAT_02338f70;
  if ((iVar5 < (int)((uint)DAT_02338f6c >> 0xb)) && (DAT_02338f70 <= iVar5)) {
    param_1[2] = (short)iVar5;
    iVar5 = ((param_2 + param_6) * 0x100 - (int)(short)param_1[2] * (param_4 + param_8)) * 0x200;
    iVar6 = iVar5 >> 0x10;
    if ((0x7fff < iVar6) || (iVar6 < iVar3)) {
      FUN_02332094(uVar4);
      return 1;
    }
    *param_1 = (short)((uint)iVar5 >> 0x10);
    do {
    } while (((uint)*DAT_02338f68 & (uint)DAT_02338f68 >> 0xb) != 0);
    iVar5 = *DAT_02338f6c;
    FUN_02332094(uVar4);
    iVar3 = DAT_02338f70;
    if ((iVar5 < 0x8000) && (DAT_02338f70 <= iVar5)) {
      param_1[3] = (short)iVar5;
      iVar5 = ((param_3 + param_7) * 0x100 -
              (int)(short)param_1[3] * ((uint)param_5 + (uint)param_9)) * 0x200;
      iVar6 = iVar5 >> 0x10;
      if ((iVar6 < 0x8000) && (iVar3 <= iVar6)) {
        param_1[1] = (short)((uint)iVar5 >> 0x10);
        return 0;
      }
      return 1;
    }
    return 1;
  }
  FUN_02332094(uVar4);
  return 1;
}

