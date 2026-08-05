// decomp: module=unk_autoload_0 addr=0x023244f4 name=FUN_023244f4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xac (Ghidra's cache says 0x9c - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=27
// verify:  python tools/match.py --c <file> --func FUN_023244f4 --addr 0x023244f4 --size 0xac --module unk_autoload_0 --version 2.0/sp1


bool FUN_023244f4(void)

{
  int *piVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 in_r3;
  
  if (*DAT_02324590 < 0x10) {
    *DAT_02324590 = *DAT_02324590 + 1;
  }
  piVar1 = DAT_02324590;
  if (*DAT_02324590 < 8) {
    *DAT_02324594 = *DAT_02324594 & DAT_02324598 | 0x1700;
    uVar2 = FUN_02322884(*piVar1);
    uVar3 = FUN_02322894(*DAT_02324590,8);
    FUN_02336428(DAT_0232459c,0x16,1,uVar3,uVar2,in_r3);
  }
  else {
    *DAT_02324594 = *DAT_02324594 & DAT_02324598 | 0x900;
    uVar2 = FUN_02322884(*piVar1 + -8);
    uVar3 = FUN_02322894(*DAT_02324590 + -8,8);
    FUN_02336428(DAT_0232459c,1,8,uVar3,uVar2,in_r3);
  }
  FUN_0232647c();
  FUN_02327e80();
  FUN_02326c9c();
  return *DAT_02324590 == 0x10;
}

