// decomp: module=arm7 addr=0x022d3ad4 name=FUN_022d3ad4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68, arm
// triage: noise=5 statements=25
// verify:  python tools/match.py --c <file> --func FUN_022d3ad4 --addr 0x022d3ad4 --size 0x68 --module arm7 --version 2.0/sp1


void FUN_022d3ad4(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  undefined1 auStack_208 [512];
  
  puVar2 = auStack_208;
  FUN_022d0918(auStack_208);
  sVar1 = *(short *)(puVar2 + 4);
  if (sVar1 == 0) {
    puVar3 = (undefined2 *)func_0x037d14bc();
    *puVar3 = 0x1f;
    puVar3[1] = 0;
    func_0x037d1464();
  }
  else {
    puVar3 = (undefined2 *)func_0x037d14bc();
    *puVar3 = 0x1f;
    puVar3[1] = 1;
    puVar3[2] = 0x305;
    puVar3[3] = sVar1;
    func_0x037d1464();
  }
  return;
}

