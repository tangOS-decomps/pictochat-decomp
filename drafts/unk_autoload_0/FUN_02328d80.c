// decomp: module=unk_autoload_0 addr=0x02328d80 name=FUN_02328d80
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x1e - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=10  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02328d80 --addr 0x02328d80 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_02328d80(short param_1,int param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)DAT_02328da4 & *DAT_02328da0 | param_1 << 8;
  if (param_2 != 0) {
    uVar1 = uVar1 | (ushort)((uint)DAT_02328da0 >> 0xd);
  }
  *DAT_02328da0 = uVar1;
  return;
}

