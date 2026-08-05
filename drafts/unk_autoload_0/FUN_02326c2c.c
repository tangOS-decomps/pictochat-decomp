// decomp: module=unk_autoload_0 addr=0x02326c2c name=FUN_02326c2c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x70 (Ghidra's cache says 0x64 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=25
// verify:  python tools/match.py --c <file> --func FUN_02326c2c --addr 0x02326c2c --size 0x70 --module unk_autoload_0 --version 2.0/sp1


void FUN_02326c2c(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  if ((param_1 == -2) || (param_1 == 0x23)) {
    uVar3 = 5;
    uVar2 = 0;
  }
  else if ((param_1 == -1) || (param_1 == 0x22)) {
    uVar3 = 3;
    uVar2 = 0;
  }
  else if (param_4 == 0) {
    uVar3 = 1;
    uVar2 = 0;
  }
  else {
    uVar3 = 0;
    uVar2 = *(undefined1 *)(*(int *)(DAT_02326c90 + 8) + param_2 * 0x1c + 0x1a);
  }
  uVar1 = FUN_02320c74();
  FUN_02320f74(uVar1,DAT_02326c94,DAT_02326c98,uVar3,0,param_1 * -4,uVar2,1);
  return;
}

