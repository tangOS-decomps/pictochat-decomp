// decomp: module=arm7 addr=0x022d8984 name=FUN_022d8984
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=16  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d8984 --addr 0x022d8984 --size 0x54 --module arm7 --version 2.0/sp1


void FUN_022d8984(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *DAT_022d89d4;
  iVar1 = func_0x037cabb0();
  if (iVar1 == 0) {
    *(ushort *)(iVar2 + 0x33e) = *(ushort *)(iVar2 + 0x33e) | 0x40;
  }
  else {
    func_0x037cabc0(iVar2 + 0x608);
    func_0x037cabc0(iVar2 + 0x634);
    func_0x037cabc0(iVar2 + 0x660);
  }
  return;
}

