// decomp: module=unk_autoload_0 addr=0x0232f89c name=FUN_0232f89c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x22, thumb
// triage: noise=3 statements=11
// verify:  python tools/match.py --c <file> --func FUN_0232f89c --addr 0x0232f89c --size 0x22 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232f89c(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_0232e084(param_1 + 1,0xc);
  *param_1 = param_2;
  iVar1 = FUN_0232f8c0(param_1);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

