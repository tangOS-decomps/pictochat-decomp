// decomp: module=unk_autoload_0 addr=0x0232cc64 name=FUN_0232cc64
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x82, thumb
// triage: noise=20 statements=44
// verify:  python tools/match.py --c <file> --func FUN_0232cc64 --addr 0x0232cc64 --size 0x82 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232cc64(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined2 local_20;
  undefined2 local_1e;
  int local_1c;
  undefined2 local_18;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  iVar1 = FUN_0232c520(3,2,3,5);
  if (iVar1 == 0) {
    if (param_2 == (int *)0x0) {
      return 6;
    }
    if (*param_2 == 0) {
      return 6;
    }
    if ((*(ushort *)(param_2 + 1) == 0) || (0xe < *(ushort *)(param_2 + 1))) {
      return 6;
    }
    FUN_0232c3bc(10,param_1);
    local_20 = 10;
    local_1e = (undefined2)param_2[1];
    local_1c = *param_2;
    local_18 = *(undefined2 *)((int)param_2 + 6);
    local_16 = (undefined1)param_2[2];
    local_15 = *(undefined1 *)((int)param_2 + 9);
    local_14 = *(undefined1 *)((int)param_2 + 10);
    local_13 = *(undefined1 *)((int)param_2 + 0xb);
    local_12 = (undefined1)param_2[3];
    local_11 = *(undefined1 *)((int)param_2 + 0xd);
    iVar1 = FUN_0232c484(&local_20,0x10);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
  }
  return iVar1;
}

