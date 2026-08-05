// decomp: module=unk_autoload_0 addr=0x02325c4c name=FUN_02325c4c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2e, thumb
// triage: noise=1 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02325c4c --addr 0x02325c4c --size 0x2e --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02325c4c(int param_1,int param_2)

{
  int iVar1;
  
  if ((((0x17 < param_1) && (param_1 < 0xfc)) && (0x11 < param_2)) && (param_2 < 0x62)) {
    if ((param_2 < 0x22) && (iVar1 = FUN_02327990(), param_1 < iVar1 + 0x18)) {
      return 0;
    }
    return 1;
  }
  return 0;
}

