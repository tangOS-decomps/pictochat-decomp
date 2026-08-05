// decomp: module=unk_autoload_0 addr=0x0232c4f0 name=FUN_0232c4f0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x2a - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0232c4f0 --addr 0x0232c4f0 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232c4f0(void)

{
  int iVar1;
  
  iVar1 = FUN_0232c4dc();
  if (iVar1 == 0) {
    FUN_023314cc(*(undefined4 *)(*(int *)(DAT_0232c51c + 4) + 4),2);
    if (**(ushort **)(*(int *)(DAT_0232c51c + 4) + 4) < 2) {
      return 3;
    }
    iVar1 = 0;
  }
  return iVar1;
}

