// decomp: module=unk_autoload_0 addr=0x02325250 name=FUN_02325250
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x1e - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=13
// verify:  python tools/match.py --c <file> --func FUN_02325250 --addr 0x02325250 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


undefined2 FUN_02325250(void)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = FUN_023251cc(PTR_DAT_02325270);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_023212c8(*(undefined2 *)(PTR_DAT_02325274 + 10));
  }
  return uVar1;
}

