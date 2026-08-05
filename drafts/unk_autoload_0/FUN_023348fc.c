// decomp: module=unk_autoload_0 addr=0x023348fc name=FUN_023348fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4a, thumb
// triage: noise=2 statements=25
// verify:  python tools/match.py --c <file> --func FUN_023348fc --addr 0x023348fc --size 0x4a --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023348fc(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = param_1 + 5;
  pcVar3 = (char *)(iVar2 + param_2);
  if (5 < *(byte *)(iVar2 + param_2)) {
    return 1;
  }
  if (*(byte *)(iVar2 + param_2) < 5) {
    return 0xffffffff;
  }
  do {
    pcVar3 = pcVar3 + 1;
    if ((char *)(iVar2 + (uint)*(byte *)(param_1 + 4)) <= pcVar3) {
      uVar1 = 1;
      if ((*(byte *)(param_1 + param_2 + 4) & 1) == 0) {
        uVar1 = 0xffffffff;
      }
      return uVar1;
    }
  } while (*pcVar3 == '\0');
  return 1;
}

