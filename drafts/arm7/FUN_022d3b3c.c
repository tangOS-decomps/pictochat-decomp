// decomp: module=arm7 addr=0x022d3b3c name=FUN_022d3b3c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x84, arm
// triage: noise=9 statements=29
// verify:  python tools/match.py --c <file> --func FUN_022d3b3c --addr 0x022d3b3c --size 0x84 --module arm7 --version 2.0/sp1


void FUN_022d3b3c(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  undefined4 in_r3;
  undefined1 auStack_210 [512];
  undefined4 local_10;
  
  puVar2 = auStack_210;
  local_10 = in_r3;
  FUN_022d0948(auStack_210);
  sVar1 = *(short *)(puVar2 + 4);
  if (sVar1 == 0) {
    puVar3 = (undefined2 *)func_0x037d14bc();
    *puVar3 = 0x20;
    puVar3[1] = 0;
    func_0x037cb78c(puVar2 + 8,puVar3 + 4,0xb4);
    func_0x037d1464(puVar3);
  }
  else {
    puVar3 = (undefined2 *)func_0x037d14bc();
    *puVar3 = 0x20;
    puVar3[1] = 1;
    puVar3[2] = 0x307;
    puVar3[3] = sVar1;
    func_0x037d1464();
  }
  return;
}

