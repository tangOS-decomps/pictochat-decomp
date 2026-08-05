// decomp: module=unk_autoload_0 addr=0x0232f688 name=FUN_0232f688
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1a - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=7
// verify:  python tools/match.py --c <file> --func FUN_0232f688 --addr 0x0232f688 --size 0x20 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232f688(uint param_1)

{
  if (*(uint *)(*(int *)(*DAT_0232f6a4 + 0x84) + 8) <= param_1) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(*DAT_0232f6a4 + 0x84) + param_1 * 0x10 + 0x10);
}

