// decomp: module=unk_autoload_0 addr=0x0232b064 name=FUN_0232b064
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x30 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=15
// verify:  python tools/match.py --c <file> --func FUN_0232b064 --addr 0x0232b064 --size 0x38 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b064(void)

{
  int iVar1;
  undefined4 in_r3;
  
  iVar1 = FUN_02329c00();
  if (iVar1 == 0) {
    iVar1 = FUN_0232d098(DAT_0232b098,*(undefined4 *)(DAT_0232b094 + 0x34),
                         *(undefined2 *)(DAT_0232b094 + 4),0,*(undefined2 *)(DAT_0232b094 + 8),1,
                         in_r3);
    if (iVar1 != 2) {
      FUN_02329bd8(0xc);
    }
  }
  return;
}

