// decomp: module=arm7 addr=0x022d1e04 name=FUN_022d1e04
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xd4 (Ghidra's cache says 0xc8 - it excludes this function's trailing literal pool), arm
// triage: noise=9 statements=41
// verify:  python tools/match.py --c <file> --func FUN_022d1e04 --addr 0x022d1e04 --size 0xd4 --module arm7 --version 2.0/sp1


void FUN_022d1e04(void)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 in_r3;
  short *psVar4;
  undefined1 auStack_210 [512];
  undefined4 local_10;
  
  puVar2 = auStack_210;
  psVar4 = *(short **)(DAT_022d1ecc + 0x550);
  local_10 = in_r3;
  if (*psVar4 == 5) {
    FUN_022d08d4(auStack_210);
    if (*(short *)(puVar2 + 4) == 0) {
      *psVar4 = 2;
      if (psVar4[0xf7] == 0) {
        iVar3 = FUN_022d05c0(auStack_210,1);
        if (*(short *)(iVar3 + 4) != 0) {
          FUN_022d1ed8(DAT_022d1ed4);
          return;
        }
        psVar4[0xf7] = 1;
      }
      puVar1 = (undefined2 *)func_0x037d14bc();
      *puVar1 = 0xb;
      puVar1[1] = 0;
      func_0x037d1464();
    }
    else {
      FUN_022d1ed8(DAT_022d1ed0);
    }
  }
  else {
    puVar1 = (undefined2 *)func_0x037d14bc();
    *puVar1 = 0xb;
    puVar1[1] = 3;
    func_0x037d1464();
  }
  return;
}

