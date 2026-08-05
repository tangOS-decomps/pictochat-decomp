// decomp: module=unk_autoload_0 addr=0x02330944 name=FUN_02330944
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48, thumb
// triage: noise=6 statements=25
// verify:  python tools/match.py --c <file> --func FUN_02330944 --addr 0x02330944 --size 0x48 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02330944(uint param_1,undefined4 *param_2,code *param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 != *(ushort *)(param_2 + 1)) {
    return 0xfffffffe;
  }
  if (param_4 == 0) {
    uVar1 = FUN_02332080();
  }
  else {
    uVar1 = FUN_023320ac();
  }
  *(undefined2 *)(param_2 + 1) = 0;
  if (param_3 != (code *)0x0) {
    (*param_3)();
  }
  *param_2 = 0;
  if (param_4 == 0) {
    FUN_02332094(uVar1);
  }
  else {
    FUN_023320c0(uVar1);
  }
  return 0;
}

