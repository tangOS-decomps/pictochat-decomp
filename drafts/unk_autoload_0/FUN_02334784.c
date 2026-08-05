// decomp: module=unk_autoload_0 addr=0x02334784 name=FUN_02334784
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x178 (Ghidra's cache says 0x146 - it excludes this function's trailing literal pool), thumb
// triage: noise=9 statements=57
// verify:  python tools/match.py --c <file> --func FUN_02334784 --addr 0x02334784 --size 0x178 --module unk_autoload_0 --version 2.0/sp1


undefined8 FUN_02334784(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined8 uVar4;
  undefined4 local_10;
  
  uVar4 = CONCAT44(param_2,param_1);
  iVar1 = FUN_02334f98(param_1,param_2,param_3,param_4,param_4);
  if (2 < iVar1) {
    cVar3 = '\x01';
    FUN_02335b58(0,0,param_1,param_2);
    if (cVar3 == '\0') {
      iVar1 = (int)(DAT_023348cc & param_2) >> 0x14;
      if (iVar1 == 0) {
        if ((DAT_023348d0 & param_2) == 0 && param_1 == 0) {
          return CONCAT44(param_2,param_1);
        }
        uVar4 = FUN_0233538c(param_1,param_2,0,DAT_023348d4);
        iVar1 = ((int)(DAT_023348cc & (uint)((ulonglong)uVar4 >> 0x20)) >> 0x14) + -0x36;
        if (param_3 < DAT_023348d8) {
          uVar4 = FUN_0233538c(DAT_023348dc,DAT_023348e0);
          return uVar4;
        }
      }
      uVar2 = (uint)((ulonglong)uVar4 >> 0x20);
      local_10 = (undefined4)uVar4;
      if (iVar1 == DAT_023348e4) {
        uVar4 = FUN_02334fe8(local_10,uVar2,local_10,uVar2);
        return uVar4;
      }
      iVar1 = iVar1 + param_3;
      if (DAT_023348e4 + -1 < iVar1) {
        uVar4 = FUN_023346cc(DAT_023348e8,DAT_023348ec,local_10,uVar2);
        uVar4 = FUN_0233538c(DAT_023348e8,DAT_023348ec,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
        return uVar4;
      }
      if (0 < iVar1) {
        return CONCAT44(DAT_023348f0 & uVar2 | iVar1 * 0x100000,local_10);
      }
      if (iVar1 < -0x35) {
        if (DAT_023348f4 < param_3) {
          uVar4 = FUN_023346cc(DAT_023348e8,DAT_023348ec,local_10,uVar2);
          uVar4 = FUN_0233538c(DAT_023348e8,DAT_023348ec,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20))
          ;
          return uVar4;
        }
        uVar4 = FUN_023346cc(DAT_023348dc,DAT_023348e0,local_10,uVar2);
        uVar4 = FUN_0233538c(DAT_023348dc,DAT_023348e0,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
        return uVar4;
      }
      uVar4 = FUN_0233538c(0,DAT_023348f8,local_10);
      return uVar4;
    }
  }
  return CONCAT44(param_2,param_1);
}

