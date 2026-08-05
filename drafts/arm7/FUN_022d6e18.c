// decomp: module=arm7 addr=0x022d6e18 name=FUN_022d6e18
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x7c - it excludes this function's trailing literal pool), arm
// triage: noise=8 statements=14
// verify:  python tools/match.py --c <file> --func FUN_022d6e18 --addr 0x022d6e18 --size 0x80 --module arm7 --version 2.0/sp1


void FUN_022d6e18(undefined4 param_1,undefined2 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*DAT_022d6e94 + 0x3e0);
  func_0x037cb774(0,*DAT_022d6e94 + 0x31c,0x28);
  func_0x037cb774(0,*DAT_022d6e94 + 0x344,0xc0);
  piVar1 = DAT_022d6e94;
  *(undefined4 *)(*DAT_022d6e94 + 0x31c) = param_1;
  *(undefined2 *)(*piVar1 + 800) = param_2;
  *(undefined2 *)(*piVar1 + 0x322) = param_2;
  *(undefined4 *)(*piVar1 + 0x3e0) = uVar2;
  return;
}

