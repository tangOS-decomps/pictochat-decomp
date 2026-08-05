// decomp: module=arm7 addr=0x022c88bc name=FUN_022c88bc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x30 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=12
// verify:  python tools/match.py --c <file> --func FUN_022c88bc --addr 0x022c88bc --size 0x38 --module arm7 --version 2.0/sp1


undefined1 FUN_022c88bc(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x28);
  if ((uVar2 < *(uint *)(DAT_022c88ec + 4)) || (*(uint *)(DAT_022c88ec + 8) <= uVar2)) {
    FUN_022c8bf0(uVar2);
  }
  uVar1 = *(undefined1 *)(DAT_022c88f0 + (uVar2 - *(int *)(DAT_022c88ec + 4)));
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1;
  return uVar1;
}

