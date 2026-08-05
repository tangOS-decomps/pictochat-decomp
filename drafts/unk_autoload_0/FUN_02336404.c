// decomp: module=unk_autoload_0 addr=0x02336404 name=FUN_02336404
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x22, thumb
// triage: noise=0 statements=13  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02336404 --addr 0x02336404 --size 0x22 --module unk_autoload_0 --version 2.0/sp1


void FUN_02336404(ushort *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = 0;
    return;
  }
  if (0 < param_2) {
    *param_1 = (ushort)param_2 | 0x4000;
    return;
  }
  *param_1 = -(ushort)param_2 | 0x8000;
  return;
}

