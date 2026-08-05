// decomp: module=unk_autoload_0 addr=0x0232b834 name=FUN_0232b834
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1e, thumb
// triage: noise=0 statements=10  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232b834 --addr 0x0232b834 --size 0x1e --module unk_autoload_0 --version 2.0/sp1


bool FUN_0232b834(int param_1)

{
  short sVar1;
  short sVar2;
  
  FUN_02332080();
  sVar1 = *(short *)(param_1 + 8);
  sVar2 = *(short *)(param_1 + 10);
  FUN_02332094();
  return sVar1 == sVar2;
}

