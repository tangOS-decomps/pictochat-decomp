// decomp: module=unk_autoload_0 addr=0x02329ad4 name=FUN_02329ad4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1a - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=10
// verify:  python tools/match.py --c <file> --func FUN_02329ad4 --addr 0x02329ad4 --size 0x20 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02329ad4(void)

{
  int iVar1;
  
  iVar1 = FUN_0232cb0c(DAT_02329af0);
  if (iVar1 != 2) {
    FUN_02329bd8(0xc);
    return 0;
  }
  return 1;
}

