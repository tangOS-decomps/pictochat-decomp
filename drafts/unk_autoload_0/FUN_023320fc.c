// decomp: module=unk_autoload_0 addr=0x023320fc name=FUN_023320fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x10, thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023320fc --addr 0x023320fc --size 0x10 --module unk_autoload_0 --version 2.0/sp1


void FUN_023320fc(int param_1)

{
  if (0x10 < (uint)(param_1 * 2)) {
    FUN_023320f0(param_1 * 2 - 0x10);
  }
  return;
}

