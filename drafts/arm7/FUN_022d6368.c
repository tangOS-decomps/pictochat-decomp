// decomp: module=arm7 addr=0x022d6368 name=FUN_022d6368
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xac (Ghidra's cache says 0xa8 - it excludes this function's trailing literal pool), arm
// triage: noise=11 statements=37
// verify:  python tools/match.py --c <file> --func FUN_022d6368 --addr 0x022d6368 --size 0xac --module arm7 --version 2.0/sp1


void FUN_022d6368(void)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  undefined4 in_r3;
  short *psVar3;
  undefined1 auStack_210 [512];
  undefined4 local_10;
  
  puVar2 = auStack_210;
  psVar3 = *(short **)(DAT_022d6410 + 0x550);
  local_10 = in_r3;
  if (*psVar3 == 2) {
    FUN_022d08bc(auStack_210);
    if (*(short *)(puVar2 + 4) == 0) {
      *psVar3 = 1;
      puVar1 = (undefined2 *)func_0x037d14bc();
      *puVar1 = 6;
      puVar1[1] = 0;
      func_0x037d1464();
    }
    else {
      puVar1 = (undefined2 *)func_0x037d14bc();
      *puVar1 = 6;
      puVar1[1] = 1;
      puVar1[2] = 0x301;
      puVar1[3] = *(undefined2 *)(puVar2 + 4);
      func_0x037d1464();
    }
  }
  else {
    puVar1 = (undefined2 *)func_0x037d14bc();
    *puVar1 = 6;
    puVar1[1] = 3;
    func_0x037d1464();
  }
  return;
}

