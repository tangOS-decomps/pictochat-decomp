// decomp: module=unk_autoload_0 addr=0x0232b380 name=FUN_0232b380
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x60 - it excludes this function's trailing literal pool), thumb
// triage: noise=13 statements=31
// verify:  python tools/match.py --c <file> --func FUN_0232b380 --addr 0x0232b380 --size 0x64 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b380(undefined1 *param_1,undefined1 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[2] = (char)param_3;
  *(undefined4 *)(param_1 + 0xc) = 0;
  pcVar2 = (code *)*DAT_0232b3e0;
  if (pcVar2 != (code *)0x0) {
    iVar3 = param_3 * 0xe0;
    uVar1 = (*pcVar2)(iVar3,0x20,pcVar2,param_4,param_4);
    *(undefined4 *)(param_1 + 4) = uVar1;
    uVar1 = (*(code *)*DAT_0232b3e0)(param_3 * 0x2c,0x20);
    *(undefined4 *)(param_1 + 8) = uVar1;
    FUN_0233746c(0,*(undefined4 *)(param_1 + 4),iVar3);
    FUN_023314e8(*(undefined4 *)(param_1 + 4),iVar3);
    iVar3 = 0;
    if (0 < param_3) {
      iVar4 = 0;
      do {
        FUN_02331dd4((char *)(*(int *)(param_1 + 8) + iVar4));
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x2c;
      } while (iVar3 < param_3);
    }
  }
  return;
}

