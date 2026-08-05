// decomp: module=unk_autoload_0 addr=0x02339084 name=FUN_02339084
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x28 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=17  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02339084 --addr 0x02339084 --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_02339084(void)

{
  int *piVar1;
  short *psVar2;
  int iVar3;
  
  psVar2 = DAT_023390b4;
  piVar1 = DAT_023390b0;
  iVar3 = *(int *)(DAT_023390ac + 0x2c);
  while (iVar3 != 0) {
    iVar3 = FUN_023320d8();
    if ((iVar3 == 0x80) || (*psVar2 == 0)) {
      FUN_02338390();
    }
    iVar3 = *piVar1;
  }
  return;
}

