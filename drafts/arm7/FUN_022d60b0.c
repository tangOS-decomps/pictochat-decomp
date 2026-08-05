// decomp: module=arm7 addr=0x022d60b0 name=FUN_022d60b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa8 (Ghidra's cache says 0xa4 - it excludes this function's trailing literal pool), arm
// triage: noise=10 statements=37
// verify:  python tools/match.py --c <file> --func FUN_022d60b0 --addr 0x022d60b0 --size 0xa8 --module arm7 --version 2.0/sp1


void FUN_022d60b0(void)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 in_r3;
  short *psVar3;
  undefined2 local_10;
  undefined2 local_e;
  undefined4 local_c;
  
  psVar3 = *(short **)(DAT_022d6154 + 0x550);
  local_c = in_r3;
  if (*psVar3 == 1) {
    iVar2 = FUN_022d6158(&local_e,&local_10);
    if (iVar2 == 0) {
      puVar1 = (undefined2 *)func_0x037d14bc();
      *puVar1 = 5;
      puVar1[1] = 1;
      puVar1[2] = local_e;
      puVar1[3] = local_10;
      func_0x037d1464();
    }
    else {
      *psVar3 = 2;
      puVar1 = (undefined2 *)func_0x037d14bc();
      *puVar1 = 5;
      puVar1[1] = 0;
      func_0x037d1464();
    }
  }
  else {
    puVar1 = (undefined2 *)func_0x037d14bc();
    *puVar1 = 5;
    puVar1[1] = 3;
    func_0x037d1464();
  }
  return;
}

