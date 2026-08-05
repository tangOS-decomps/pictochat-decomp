// decomp: module=unk_autoload_0 addr=0x02338f74 name=FUN_02338f74
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb0 (Ghidra's cache says 0xa6 - it excludes this function's trailing literal pool), thumb
// triage: noise=10 statements=44
// verify:  python tools/match.py --c <file> --func FUN_02338f74 --addr 0x02338f74 --size 0xb0 --module unk_autoload_0 --version 2.0/sp1


void FUN_02338f74(ushort *param_1,ushort *param_2,undefined4 param_3,undefined4 param_4)

{
  ushort extraout_var;
  ushort extraout_var_00;
  int extraout_r1;
  int extraout_r1_00;
  uint uVar1;
  
  if (*(short *)(DAT_0233901c + 0x34) == 0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    return;
  }
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  if (param_2[2] == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    return;
  }
  uVar1 = *DAT_02339020;
  FUN_02335dec(DAT_02339020[2],(int)DAT_02339020[2] >> 0x1f,(uint)*param_2 * 4 - uVar1,
               -(uint)((uint)*param_2 * 4 < uVar1) - ((int)uVar1 >> 0x1f),param_4);
  *param_1 = extraout_var >> 6 | (ushort)(extraout_r1 << 10);
  if ((short)*param_1 < 0) {
    *param_1 = 0;
  }
  else if (0xff < (short)*param_1) {
    *param_1 = 0xff;
  }
  uVar1 = DAT_02339020[3];
  FUN_02335dec(DAT_02339020[5],(int)DAT_02339020[5] >> 0x1f,(uint)param_2[1] * 4 - uVar1,
               -(uint)((uint)param_2[1] * 4 < uVar1) - ((int)uVar1 >> 0x1f),param_4);
  param_1[1] = extraout_var_00 >> 6 | (ushort)(extraout_r1_00 << 10);
  if ((short)param_1[1] < 0) {
    param_1[1] = 0;
    return;
  }
  if (0xbf < (short)param_1[1]) {
    param_1[1] = 0xbf;
  }
  return;
}

