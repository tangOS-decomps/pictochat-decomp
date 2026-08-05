// decomp: module=arm7 addr=0x022d867c name=FUN_022d867c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x70, arm
// triage: noise=5 statements=24
// verify:  python tools/match.py --c <file> --func FUN_022d867c --addr 0x022d867c --size 0x70 --module arm7 --version 2.0/sp1


void FUN_022d867c(void)

{
  undefined4 in_r3;
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint local_20;
  undefined4 local_1c;
  
  uVar3 = 0;
  local_20 = 0;
  uVar2 = 0;
  iVar1 = 100;
  local_1c = in_r3;
  do {
    FUN_022e2e4c(iVar1,1,&local_20);
    if (uVar2 == 1) {
      local_20 = local_20 & 0x80;
    }
    uVar3 = FUN_022d8e04(local_20 & 0xff,uVar3);
    uVar2 = uVar2 + 1;
    iVar1 = iVar1 + 1;
  } while (uVar2 < 0x69);
  return;
}

