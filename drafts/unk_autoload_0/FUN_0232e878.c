// decomp: module=unk_autoload_0 addr=0x0232e878 name=FUN_0232e878
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x26 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=16  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232e878 --addr 0x0232e878 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


int FUN_0232e878(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 1;
  iVar1 = 0;
  do {
    if ((*(uint *)(DAT_0232e8a0 + 4) & uVar2) == 0) {
      *(uint *)(DAT_0232e8a0 + 4) = *(uint *)(DAT_0232e8a0 + 4) | uVar2;
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    uVar2 = uVar2 << 1;
  } while (iVar1 < 8);
  return -1;
}

