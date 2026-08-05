// decomp: module=unk_autoload_0 addr=0x023243e4 name=FUN_023243e4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x54 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=19
// verify:  python tools/match.py --c <file> --func FUN_023243e4 --addr 0x023243e4 --size 0x64 --module unk_autoload_0 --version 2.0/sp1


void FUN_023243e4(void)

{
  int *piVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 in_r3;
  
  piVar1 = DAT_02324438;
  *DAT_02324438 = 0;
  *DAT_0232443c = *DAT_0232443c & DAT_02324440 | 0x900;
  uVar3 = FUN_02322894(*piVar1,8);
  uVar2 = FUN_02322884(*DAT_02324438);
  FUN_02336428(DAT_02324444,1,8,uVar2,uVar3,in_r3);
  FUN_023279bc();
  FUN_023292e4();
  FUN_02328ce4();
  FUN_023272c8();
  FUN_02326c9c();
  return;
}

