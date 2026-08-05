// decomp: module=unk_autoload_0 addr=0x02327c70 name=FUN_02327c70
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c, thumb
// triage: noise=6 statements=16
// verify:  python tools/match.py --c <file> --func FUN_02327c70 --addr 0x02327c70 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_02327c70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_10 [4];
  undefined4 uStack_c;
  
  uStack_c = param_4;
  iVar1 = FUN_02325b74(*(undefined4 *)(param_1 + 0x3c),auStack_10,1);
  if (iVar1 == 0) {
    FUN_02320978(0xf);
  }
  else {
    FUN_02320978(4);
  }
  FUN_0232571c(param_1);
  return;
}

