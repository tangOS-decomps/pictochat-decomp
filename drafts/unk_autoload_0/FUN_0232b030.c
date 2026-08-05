// decomp: module=unk_autoload_0 addr=0x0232b030 name=FUN_0232b030
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2e - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=17
// verify:  python tools/match.py --c <file> --func FUN_0232b030 --addr 0x0232b030 --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b030(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0232981c();
  if (iVar1 == 0) {
    if (*(short *)(param_1 + 2) == 0) {
      FUN_02329bd8(1);
      iVar1 = DAT_0232b060;
      *(undefined4 *)(DAT_0232b060 + 0x30) = 0;
      *(undefined4 *)(iVar1 + 0x40) = 0;
      FUN_0232a1e4();
      return;
    }
    FUN_02329bd8(0xc);
  }
  return;
}

