// decomp: module=unk_autoload_0 addr=0x02325cb4 name=FUN_02325cb4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=10
// verify:  python tools/match.py --c <file> --func FUN_02325cb4 --addr 0x02325cb4 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


undefined2 FUN_02325cb4(int param_1)

{
  uint uVar1;
  
  param_1 = param_1 + (uint)*(ushort *)(param_1 + DAT_02325cd8) * 0x104;
  uVar1 = (uint)*(ushort *)(param_1 + DAT_02325cdc);
  if (uVar1 == 0) {
    return 0;
  }
  return *(undefined2 *)(param_1 + (uVar1 - 1) * 2 + 0x56);
}

