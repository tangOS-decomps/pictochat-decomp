// decomp: module=unk_autoload_0 addr=0x02331d1c name=FUN_02331d1c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68 (Ghidra's cache says 0x56 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=30
// verify:  python tools/match.py --c <file> --func FUN_02331d1c --addr 0x02331d1c --size 0x68 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331d1c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar6 = FUN_02331ca8();
  *DAT_02331d74 = 0;
  uVar3 = *(uint *)(param_1 + 0xc);
  uVar5 = uVar3 - (uint)uVar6;
  iVar4 = (*(int *)(param_1 + 0x10) - (int)((ulonglong)uVar6 >> 0x20)) - (uint)(uVar3 < (uint)uVar6)
  ;
  FUN_02330784(1,DAT_02331d78,0,uVar3,param_4);
  puVar1 = DAT_02331d80;
  if (iVar4 < 0) {
    uVar2 = (ushort)DAT_02331d7c;
  }
  else if (iVar4 < (int)(uint)(uVar5 < 0x10000)) {
    uVar2 = ~(ushort)uVar5;
  }
  else {
    uVar2 = 0;
  }
  *DAT_02331d80 = uVar2;
  puVar1[1] = 0xc1;
  FUN_023307d4(0x10);
  return;
}

