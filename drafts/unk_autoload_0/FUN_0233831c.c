// decomp: module=unk_autoload_0 addr=0x0233831c name=FUN_0233831c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x6e - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=15
// verify:  python tools/match.py --c <file> --func FUN_0233831c --addr 0x0233831c --size 0x74 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0233831c(uint param_1,int param_2,uint param_3)

{
  if (((uint)DAT_0233838c >> 0xc & (uint)*DAT_0233838c) != 0) {
    *DAT_0233838c = *DAT_0233838c | 0xc000;
    return 0xffffffff;
  }
  FUN_02332080();
  if ((*DAT_0233838c & 2) != 0) {
    FUN_02332094();
    return 0xfffffffe;
  }
  *(uint *)(DAT_0233838c + 2) = param_2 << 6 | param_1 & 0x1f | (param_3 & 1) << 5;
  FUN_02332094();
  return 0;
}

