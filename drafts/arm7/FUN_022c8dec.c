// decomp: module=arm7 addr=0x022c8dec name=FUN_022c8dec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c8dec --addr 0x022c8dec --size 0x20 --module arm7 --version 2.0/sp1


int FUN_022c8dec(int param_1,int param_2)

{
  uint uVar1;
  
  if (0xf < param_2) {
    return 0;
  }
  uVar1 = (uint)*(byte *)(param_1 + param_2 + 8);
  if (uVar1 == 0xff) {
    return 0;
  }
  return DAT_022c8e08 + uVar1 * 0x40;
}

