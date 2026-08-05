// decomp: module=unk_autoload_0 addr=0x0232e0d8 name=FUN_0232e0d8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2a, thumb
// triage: noise=0 statements=20  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232e0d8 --addr 0x0232e0d8 --size 0x2a --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e0d8(int *param_1,char *param_2)

{
  char *pcVar1;
  ushort uVar2;
  
  if (*param_1 == 0) {
    FUN_0232e090(param_1,param_2);
    return;
  }
  uVar2 = *(ushort *)((int)param_1 + 10);
  pcVar1 = param_2 + uVar2;
  pcVar1[0] = '\0';
  pcVar1[1] = '\0';
  pcVar1[2] = '\0';
  pcVar1[3] = '\0';
  *(int *)(param_2 + uVar2 + 4) = *param_1;
  *(char **)(*param_1 + (uint)*(ushort *)((int)param_1 + 10)) = param_2;
  *param_1 = (int)param_2;
  *(short *)(param_1 + 2) = (short)param_1[2] + 1;
  return;
}

