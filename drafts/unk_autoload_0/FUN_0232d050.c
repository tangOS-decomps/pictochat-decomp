// decomp: module=unk_autoload_0 addr=0x0232d050 name=FUN_0232d050
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x46, thumb
// triage: noise=0 statements=19  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232d050 --addr 0x0232d050 --size 0x46 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232d050(int param_1)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = FUN_0232c4d0();
  iVar2 = FUN_0232c520(2,9,10);
  if (iVar2 == 0) {
    FUN_023314cc(*(int *)((int)pvVar1 + 4) + 0xc,4);
    if (*(int *)(*(int *)((int)pvVar1 + 4) + 0xc) == 0) {
      return 3;
    }
    FUN_0232c3bc(0x10,param_1);
    iVar2 = FUN_0232c408(0x10,0);
    if (iVar2 == 0) {
      iVar2 = 2;
    }
  }
  return iVar2;
}

