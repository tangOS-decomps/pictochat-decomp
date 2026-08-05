// decomp: module=arm7 addr=0x022c8150 name=FUN_022c8150
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28, thumb
// triage: noise=10 statements=12
// verify:  python tools/match.py --c <file> --func FUN_022c8150 --addr 0x022c8150 --size 0x28 --module arm7 --version 2.0/sp1


undefined4 FUN_022c8150(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 1) = 0;
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 0x38) = *param_2;
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  *(undefined4 *)(param_1 + 0x40) = param_2[2];
  *(undefined4 *)(param_1 + 0x44) = param_3;
  FUN_022c864c(param_1,param_4);
  return 1;
}

