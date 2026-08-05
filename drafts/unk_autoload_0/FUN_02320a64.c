// decomp: module=unk_autoload_0 addr=0x02320a64 name=FUN_02320a64
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x52 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=22
// verify:  python tools/match.py --c <file> --func FUN_02320a64 --addr 0x02320a64 --size 0x64 --module unk_autoload_0 --version 2.0/sp1


void FUN_02320a64(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_023215d0();
  FUN_02321634();
  FUN_023215d0();
  FUN_02321634();
  FUN_023215d0();
  FUN_02321634();
  iVar1 = DAT_02320ab8;
  *(undefined4 *)(DAT_02320ab8 + 0x40) = 0;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  uVar2 = FUN_02322820();
  FUN_023216e0(DAT_02320ab8,uVar2);
  iVar1 = DAT_02320ab8;
  if (param_1 == 2) {
    *(undefined4 *)(DAT_02320ab8 + 0x40) = 10;
    *(undefined4 *)(iVar1 + 0x44) = 1;
  }
  return;
}

