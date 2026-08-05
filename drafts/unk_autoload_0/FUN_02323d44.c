// decomp: module=unk_autoload_0 addr=0x02323d44 name=FUN_02323d44
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x9c (Ghidra's cache says 0x96 - it excludes this function's trailing literal pool), thumb
// triage: noise=8 statements=18
// verify:  python tools/match.py --c <file> --func FUN_02323d44 --addr 0x02323d44 --size 0x9c --module unk_autoload_0 --version 2.0/sp1


void FUN_02323d44(short *param_1)

{
  int iVar1;
  
  iVar1 = DAT_02323ddc;
  *param_1 = (short)*(undefined4 *)(DAT_02323ddc + 4) + (**(ushort **)(DAT_02323ddc + 0x38) & 0xff);
  param_1[1] = (short)*(undefined4 *)(iVar1 + 8) + (**(ushort **)(iVar1 + 0x38) >> 8);
  param_1[2] = (short)*(undefined4 *)(iVar1 + 4) +
               (**(ushort **)(iVar1 + 0x38) & 0xff) + ((*(ushort **)(iVar1 + 0x38))[1] & 0xff);
  param_1[3] = (short)*(undefined4 *)(iVar1 + 8) + (**(ushort **)(iVar1 + 0x38) >> 8);
  param_1[4] = (short)*(undefined4 *)(iVar1 + 4) + (**(ushort **)(iVar1 + 0x38) & 0xff);
  param_1[5] = (short)*(undefined4 *)(iVar1 + 8) +
               (**(ushort **)(iVar1 + 0x38) >> 8) + ((*(ushort **)(iVar1 + 0x38))[1] >> 8);
  param_1[6] = (short)*(undefined4 *)(iVar1 + 4) +
               (**(ushort **)(iVar1 + 0x38) & 0xff) + ((*(ushort **)(iVar1 + 0x38))[1] & 0xff);
  param_1[7] = (short)*(undefined4 *)(iVar1 + 8) +
               (**(ushort **)(iVar1 + 0x38) >> 8) + ((*(ushort **)(iVar1 + 0x38))[1] >> 8);
  return;
}

