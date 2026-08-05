// decomp: module=arm7 addr=0x022c4a10 name=FUN_022c4a10
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7c, arm
// triage: noise=6 statements=28
// verify:  python tools/match.py --c <file> --func FUN_022c4a10 --addr 0x022c4a10 --size 0x7c --module arm7 --version 2.0/sp1


undefined4 FUN_022c4a10(uint param_1,undefined4 *param_2,code *param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 == *(ushort *)(param_2 + 1)) {
    if (param_4 == 0) {
      uVar1 = FUN_022c6d40(param_1);
    }
    else {
      uVar1 = FUN_022c6d6c();
    }
    *(undefined2 *)(param_2 + 1) = 0;
    if (param_3 != (code *)0x0) {
      (*param_3)();
    }
    *param_2 = 0;
    if (param_4 == 0) {
      FUN_022c6d54(uVar1);
    }
    else {
      FUN_022c6d80();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}

