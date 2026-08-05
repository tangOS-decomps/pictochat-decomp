// decomp: module=unk_autoload_0 addr=0x02336428 name=FUN_02336428
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c, thumb
// triage: noise=0 statements=5  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02336428 --addr 0x02336428 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_02336428(uint *param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  *param_1 = (param_5 << 8 | param_4) << 0x10 | param_2 | 0x40 | param_3 << 8;
  return;
}

