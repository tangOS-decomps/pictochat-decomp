// decomp: module=unk_autoload_0 addr=0x02330f6c name=FUN_02330f6c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x46, thumb
// triage: noise=2 statements=20
// verify:  python tools/match.py --c <file> --func FUN_02330f6c --addr 0x02330f6c --size 0x46 --module unk_autoload_0 --version 2.0/sp1


void FUN_02330f6c(int *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = FUN_02332080();
  if (*param_1 != 0) {
    do {
      puVar2 = FUN_02330b68(param_1);
      puVar2[0x19] = 1;
      puVar2[0x1e] = 0;
      puVar2[0x20] = 0;
      puVar2[0x1f] = puVar2[0x20];
    } while (*param_1 != 0);
    param_1[1] = 0;
    *param_1 = 0;
    FUN_02330c4c();
  }
  FUN_02332094(uVar1);
  return;
}

