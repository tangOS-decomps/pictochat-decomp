// decomp: module=unk_autoload_0 addr=0x02330bcc name=FUN_02330bcc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c, thumb
// triage: noise=1 statements=17
// verify:  python tools/match.py --c <file> --func FUN_02330bcc --addr 0x02330bcc --size 0x1c --module unk_autoload_0 --version 2.0/sp1


int FUN_02330bcc(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x10);
    *param_1 = iVar1;
    if (iVar1 == 0) {
      param_1[1] = 0;
    }
    else {
      *(undefined4 *)(iVar1 + 0x14) = 0;
    }
  }
  return iVar2;
}

