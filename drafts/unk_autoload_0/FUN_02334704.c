// decomp: module=unk_autoload_0 addr=0x02334704 name=FUN_02334704
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x6a - it excludes this function's trailing literal pool), thumb
// triage: noise=8 statements=23
// verify:  python tools/match.py --c <file> --func FUN_02334704 --addr 0x02334704 --size 0x80 --module unk_autoload_0 --version 2.0/sp1


undefined8 FUN_02334704(int param_1,uint param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined4 local_10;
  
  iVar1 = DAT_02334774;
  uVar3 = CONCAT44(param_2,param_1);
  uVar2 = DAT_02334770 & param_2;
  *param_3 = 0;
  if (((int)uVar2 < iVar1) && (uVar2 != 0 || param_1 != 0)) {
    if ((int)uVar2 < 0x100000) {
      uVar3 = FUN_0233538c(param_1,param_2,0,DAT_02334778,param_4);
      uVar2 = DAT_02334770 & (uint)((ulonglong)uVar3 >> 0x20);
      *param_3 = -0x36;
    }
    iVar1 = DAT_0233477c;
    local_10 = (undefined4)uVar3;
    *param_3 = *param_3 + (((int)uVar2 >> 0x14) - DAT_0233477c);
    return CONCAT44((uint)((ulonglong)uVar3 >> 0x20) & DAT_02334780 | iVar1 << 0x14,local_10);
  }
  return CONCAT44(param_2,param_1);
}

