// decomp: module=unk_autoload_0 addr=0x0232a304 name=FUN_0232a304
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x5a - it excludes this function's trailing literal pool), thumb
// triage: noise=12 statements=15
// verify:  python tools/match.py --c <file> --func FUN_0232a304 --addr 0x0232a304 --size 0x64 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a304(void)

{
  if (*DAT_0232a360 != 0) {
    FUN_0232c0b4();
    FUN_0232b8fc();
    (*(code *)*DAT_0232a360)(*(undefined4 *)(DAT_0232a364 + 0x3c));
    (*(code *)*DAT_0232a360)(*(undefined4 *)(DAT_0232a364 + 0x44));
    (*(code *)*DAT_0232a360)(*(undefined4 *)(DAT_0232a364 + 0x28));
    (*(code *)*DAT_0232a360)(*(undefined4 *)(DAT_0232a364 + 0x18));
    (*(code *)*DAT_0232a360)(*(undefined4 *)(DAT_0232a364 + 0x34));
    (*(code *)*DAT_0232a360)(*(undefined4 *)(DAT_0232a364 + 0x50));
  }
  FUN_0232c8c0(0xc,0,0);
  return;
}

