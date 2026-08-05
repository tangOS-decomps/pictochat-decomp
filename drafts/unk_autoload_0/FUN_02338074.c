// decomp: module=unk_autoload_0 addr=0x02338074 name=FUN_02338074
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2a, thumb
// triage: noise=5 statements=16
// verify:  python tools/match.py --c <file> --func FUN_02338074 --addr 0x02338074 --size 0x2a --module unk_autoload_0 --version 2.0/sp1


void FUN_02338074(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  FUN_02337980();
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)puVar1[1];
    *puVar1 = 0;
    puVar1[1] = 0;
    FUN_023314e8(puVar1,8);
    puVar1 = puVar2;
  }
  FUN_02337990();
  return;
}

