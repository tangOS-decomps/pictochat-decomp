// decomp: module=unk_autoload_0 addr=0x02324448 name=FUN_02324448
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xac (Ghidra's cache says 0x9c - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=27
// verify:  python tools/match.py --c <file> --func FUN_02324448 --addr 0x02324448 --size 0xac --module unk_autoload_0 --version 2.0/sp1


bool FUN_02324448(void)

{
  int *piVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 in_r3;
  
  if (*DAT_023244e4 < 0x10) {
    *DAT_023244e4 = *DAT_023244e4 + 1;
  }
  piVar1 = DAT_023244e4;
  if (*DAT_023244e4 < 8) {
    *DAT_023244e8 = *DAT_023244e8 & DAT_023244ec | 0x900;
    uVar3 = FUN_02322894(*piVar1,8);
    uVar2 = FUN_02322884(*DAT_023244e4);
    FUN_02336428(DAT_023244f0,1,8,uVar2,uVar3,in_r3);
  }
  else {
    *DAT_023244e8 = *DAT_023244e8 & DAT_023244ec | 0x1700;
    uVar3 = FUN_02322894(*piVar1 + -8,8);
    uVar2 = FUN_02322884(*DAT_023244e4 + -8);
    FUN_02336428(DAT_023244f0,0x16,1,uVar2,uVar3);
  }
  FUN_02326470();
  FUN_02327e80();
  FUN_02326c9c();
  return *DAT_023244e4 == 0x10;
}

