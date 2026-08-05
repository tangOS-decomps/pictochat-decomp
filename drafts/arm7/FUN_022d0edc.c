// decomp: module=arm7 addr=0x022d0edc name=FUN_022d0edc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb0 (Ghidra's cache says 0xac - it excludes this function's trailing literal pool), arm
// triage: noise=10 statements=41
// verify:  python tools/match.py --c <file> --func FUN_022d0edc --addr 0x022d0edc --size 0xb0 --module arm7 --version 2.0/sp1


void FUN_022d0edc(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  undefined4 in_r3;
  short *psVar4;
  undefined1 auStack_210 [512];
  undefined4 local_10;
  
  puVar3 = auStack_210;
  psVar4 = *(short **)(DAT_022d0f88 + 0x550);
  local_10 = in_r3;
  if (*psVar4 == 2) {
    FUN_022d08bc(auStack_210);
    sVar1 = *(short *)(puVar3 + 4);
    if (sVar1 == 0) {
      *psVar4 = 1;
      thunk_EXT_FUN_03802630();
      *psVar4 = 0;
      puVar2 = (undefined2 *)func_0x037d14bc();
      *puVar2 = 2;
      puVar2[1] = 0;
      func_0x037d1464();
    }
    else {
      puVar2 = (undefined2 *)func_0x037d14bc();
      *puVar2 = 2;
      puVar2[1] = 1;
      puVar2[2] = 0x301;
      puVar2[3] = sVar1;
      func_0x037d1464();
    }
  }
  else {
    puVar2 = (undefined2 *)func_0x037d14bc();
    *puVar2 = 2;
    puVar2[1] = 3;
    func_0x037d1464();
  }
  return;
}

