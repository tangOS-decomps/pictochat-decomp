// decomp: module=arm7 addr=0x022d7c08 name=FUN_022d7c08
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x74 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=17  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d7c08 --addr 0x022d7c08 --size 0x80 --module arm7 --version 2.0/sp1


void FUN_022d7c08(void)

{
  int iVar1;
  int iVar2;
  int local_8 [2];
  
  local_8[0] = DAT_022d7c7c;
  FUN_022e2e4c(0x58,2,local_8);
  local_8[0] = local_8[0] + 0x202;
  iVar2 = FUN_022d85b4();
  iVar1 = local_8[0];
  if ((iVar2 == 0x14) && (iVar1 = local_8[0] + -0x6161, (*DAT_022d7c80 & 2) != 0)) {
    iVar1 = local_8[0] + -0xc1c1;
  }
  local_8[0] = iVar1;
  *DAT_022d7c84 = (short)local_8[0];
  return;
}

