// decomp: module=unk_autoload_0 addr=0x02334b20 name=FUN_02334b20
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60, thumb
// triage: noise=3 statements=32
// verify:  python tools/match.py --c <file> --func FUN_02334b20 --addr 0x02334b20 --size 0x60 --module unk_autoload_0 --version 2.0/sp1


void FUN_02334b20(undefined1 *param_1,char *param_2,undefined2 param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  *(undefined2 *)(param_1 + 2) = param_3;
  *param_1 = 0;
  iVar2 = 0;
  for (; (iVar2 < 0x20 && (*param_2 != '\0')); param_2 = param_2 + 1) {
    param_1[iVar2 + 5] = *param_2 + -0x30;
    iVar2 = iVar2 + 1;
  }
  param_1[4] = (char)iVar2;
  cVar1 = *param_2;
  if ((cVar1 != '\0') && ('\x04' < cVar1)) {
    if (cVar1 < '\x06') {
      pcVar3 = param_2 + 1;
      cVar1 = param_2[1];
      while (cVar1 != '\0') {
        if (cVar1 != '0') goto LAB_02334b78;
        pcVar3 = pcVar3 + 1;
        cVar1 = *pcVar3;
      }
      if ((param_1[iVar2 + 4] & 1) == 0) {
        return;
      }
    }
LAB_02334b78:
    FUN_02334948(param_1,param_1[4]);
  }
  return;
}

