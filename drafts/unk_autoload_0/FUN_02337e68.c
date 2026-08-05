// decomp: module=unk_autoload_0 addr=0x02337e68 name=FUN_02337e68
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1a - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02337e68 --addr 0x02337e68 --size 0x20 --module unk_autoload_0 --version 2.0/sp1


undefined1 FUN_02337e68(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = DAT_02337e84 + param_1 * 0xc;
  *(undefined4 *)(DAT_02337e84 + param_1 * 0xc) = param_2;
  *(undefined4 *)(iVar1 + 4) = param_3;
  *(char *)(iVar1 + 8) = *(char *)(iVar1 + 8) + '\x01';
  return *(undefined1 *)(iVar1 + 8);
}

