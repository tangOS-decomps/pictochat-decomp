// decomp: module=unk_autoload_0 addr=0x023210c8 name=FUN_023210c8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xd0 (Ghidra's cache says 0xc6 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=38
// verify:  python tools/match.py --c <file> --func FUN_023210c8 --addr 0x023210c8 --size 0xd0 --module unk_autoload_0 --version 2.0/sp1


void FUN_023210c8(int param_1,int param_2,int param_3,short param_4,int param_5)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_3c;
  int local_24;
  int local_20;
  uint local_1c;
  ushort local_18;
  
  if (*(short *)(*(int *)(param_1 + 0x24) + 0x10) == 0) {
    local_3c = DAT_02321194;
  }
  else {
    local_3c = DAT_02321190;
  }
  iVar4 = FUN_0232102c(*(undefined4 *)(param_1 + 0x10));
  sVar1 = *(short *)(param_1 + 8);
  sVar2 = *(short *)(param_1 + 10);
  FUN_02321798(*(undefined4 *)(param_1 + 0x10),&local_20,&local_24);
  sVar3 = 0;
  for (iVar5 = 0; iVar5 < (int)(uint)*(ushort *)(param_1 + 0x1a); iVar5 = iVar5 + 1) {
    for (iVar6 = 0; iVar6 < (int)(uint)*(ushort *)(param_1 + 0x18); iVar6 = iVar6 + 1) {
      local_1c = param_5 << 10 | param_3 + sVar2 + iVar5 * local_24 & 0xffU |
                 *(uint *)(param_1 + 0x10) | (param_2 + sVar1 + iVar6 * local_20 & 0x1ffU) << 0x10;
      local_18 = param_4 << 10 |
                 *(short *)(param_1 + 0x14) +
                 (short)((int)(iVar4 + ((uint)(iVar4 >> 1) >> 0x1e)) >> 2) * sVar3 |
                 *(short *)(param_1 + 0x16) << 0xc;
      FUN_02320fa0(local_3c,&local_1c,0);
      sVar3 = sVar3 + 1;
    }
  }
  return;
}

