// decomp: module=unk_autoload_0 addr=0x0232ed20 name=FUN_0232ed20
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x36, thumb
// triage: noise=0 statements=10  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232ed20 --addr 0x0232ed20 --size 0x36 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ed20(int *param_1,int param_2)

{
  int b;
  
  for (b = FUN_0232e178(param_1,0); (b != 0 && (*(byte *)(b + 0x3d) <= *(byte *)(param_2 + 0x3d)));
      b = FUN_0232e178(param_1,b)) {
  }
  FUN_0232e104(param_1,b,param_2);
  *(int **)(param_2 + 4) = param_1;
  return;
}

