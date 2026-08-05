// decomp: module=unk_autoload_0 addr=0x0232e6e8 name=FUN_0232e6e8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20, thumb
// triage: noise=2 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0232e6e8 --addr 0x0232e6e8 --size 0x20 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232e6e8(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = param_2 + param_1 & 0xfffffffc;
  uVar1 = param_1 + 3U & 0xfffffffc;
  if ((uVar1 <= uVar3) && (0x2f < uVar3 - uVar1)) {
    uVar2 = FUN_0232e614();
    return uVar2;
  }
  return 0;
}

