// decomp: module=unk_autoload_0 addr=0x02325278 name=FUN_02325278
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x1e - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02325278 --addr 0x02325278 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


uint FUN_02325278(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_023212bc(DAT_02325298);
  if (iVar1 != 0) {
    uVar2 = FUN_023212bc(DAT_02325298);
    return uVar2 & 0xffff;
  }
  uVar2 = FUN_02325250();
  return uVar2;
}

