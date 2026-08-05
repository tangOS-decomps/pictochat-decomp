// decomp: module=arm7 addr=0x022c2f08 name=FUN_022c2f08
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68 (Ghidra's cache says 0x60 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=19
// verify:  python tools/match.py --c <file> --func FUN_022c2f08 --addr 0x022c2f08 --size 0x68 --module arm7 --version 2.0/sp1


void FUN_022c2f08(void)

{
  short sVar1;
  short *psVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = FUN_022c48a4(0x1000000);
  psVar2 = DAT_022c2f68;
  sVar1 = *DAT_022c2f68;
  DAT_022c2f68[0x1a] = 0x1000;
  iVar4 = 100;
  while ((iVar4 != 0 && (sVar1 == *psVar2))) {
    iVar4 = iVar4 + -1;
  }
  *DAT_022c2f6c = 0;
  FUN_022c29d4();
  FUN_022c486c(uVar3);
  return;
}

