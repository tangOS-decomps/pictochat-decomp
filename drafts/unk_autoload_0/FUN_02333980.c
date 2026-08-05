// decomp: module=unk_autoload_0 addr=0x02333980 name=FUN_02333980
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb6, thumb
// triage: noise=5 statements=55
// verify:  python tools/match.py --c <file> --func FUN_02333980 --addr 0x02333980 --size 0xb6 --module unk_autoload_0 --version 2.0/sp1


void FUN_02333980(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  
  if (-1 < param_2) {
    if (param_2 < (int)(uint)*(byte *)(param_1 + 4)) {
      pcVar2 = (char *)(param_1 + 5 + param_2);
      uVar3 = 0;
      iVar5 = (*pcVar2 + -0x30) * 0x1000000 >> 0x18;
      if (iVar5 == 5) {
        pcVar4 = (char *)(param_1 + 5 + (uint)*(byte *)(param_1 + 4));
        do {
          pcVar4 = pcVar4 + -1;
          if (pcVar4 <= pcVar2) break;
        } while (*pcVar4 == '0');
        if (pcVar4 == pcVar2) {
          uVar3 = (int)pcVar2[-1] & 1;
        }
        else {
          uVar3 = 1;
        }
      }
      else if (5 < iVar5) {
        uVar3 = 1;
      }
      for (; param_2 != 0; param_2 = param_2 + -1) {
        pcVar2 = pcVar2 + -1;
        iVar5 = (*pcVar2 + -0x30 + uVar3) * 0x1000000;
        iVar1 = iVar5 >> 0x18;
        uVar3 = (uint)(9 < iVar1);
        if ((uVar3 == 0) && (iVar1 != 0)) {
          *pcVar2 = (char)((uint)iVar5 >> 0x18) + '0';
          break;
        }
      }
      if (uVar3 != 0) {
        *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
        *(undefined1 *)(param_1 + 4) = 1;
        *(undefined1 *)(param_1 + 5) = 0x31;
        return;
      }
      if (param_2 == 0) goto LAB_02333988;
      *(char *)(param_1 + 4) = (char)param_2;
    }
    return;
  }
LAB_02333988:
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined1 *)(param_1 + 4) = 1;
  *(undefined1 *)(param_1 + 5) = 0x30;
  return;
}

