// decomp: module=unk_autoload_0 addr=0x0232b6d8 name=FUN_0232b6d8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x6c - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=25
// verify:  python tools/match.py --c <file> --func FUN_0232b6d8 --addr 0x0232b6d8 --size 0x74 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b6d8(byte *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  
  iVar3 = 0;
  if (param_1[2] != 0) {
    iVar2 = 0;
    iVar1 = 0;
    uVar4 = FUN_02335dec(param_2,0,DAT_0232b744,0);
    do {
      if (*(short *)(*(int *)(param_1 + 4) + iVar2) == 1) {
        FUN_02331ef0(*(int *)(param_1 + 8) + iVar1);
        FUN_02331ea8(*(int *)(param_1 + 8) + iVar1,(int)(uVar4 >> 6),(int)((uVar4 >> 6) >> 0x20),
                     DAT_0232b748,*(int *)(param_1 + 4) + iVar2);
        FUN_02331ff8(*(int *)(param_1 + 8) + iVar1,*param_1 + 0x80);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xe0;
      iVar1 = iVar1 + 0x2c;
    } while (iVar3 < (int)(uint)param_1[2]);
  }
  return;
}

