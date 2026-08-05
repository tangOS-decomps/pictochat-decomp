// decomp: module=unk_autoload_0 addr=0x02329e4c name=FUN_02329e4c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x30 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=14
// verify:  python tools/match.py --c <file> --func FUN_02329e4c --addr 0x02329e4c --size 0x34 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02329e4c(void)

{
  if (*(int *)(DAT_02329e7c + 0xc) == 0) {
    FUN_0232a0b8();
    return 1;
  }
  if (*(int *)(DAT_02329e7c + 0xc) == 1) {
    FUN_0232b6a4((uchar *)(*(int *)(DAT_02329e7c + 0x30) + (uint)*(byte *)(DAT_02329e7c + 2) * 0x10)
                );
    FUN_0232a16c();
    return 1;
  }
  return 0;
}

