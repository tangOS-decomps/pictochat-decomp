// decomp: module=unk_autoload_0 addr=0x02330784 name=FUN_02330784
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=10
// verify:  python tools/match.py --c <file> --func FUN_02330784 --addr 0x02330784 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_02330784(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = param_1 * 0xc;
  *(undefined4 *)(DAT_023307a8 + iVar1) = param_2;
  *(undefined4 *)(DAT_023307ac + iVar1) = param_3;
  FUN_023307d4(1 << (param_1 + 3U & 0xff));
  *(undefined4 *)(DAT_023307b0 + iVar1) = 1;
  return;
}

