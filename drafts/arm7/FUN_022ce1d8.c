// decomp: module=arm7 addr=0x022ce1d8 name=FUN_022ce1d8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x78 (Ghidra's cache says 0x70 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=18
// verify:  python tools/match.py --c <file> --func FUN_022ce1d8 --addr 0x022ce1d8 --size 0x78 --module arm7 --version 2.0/sp1


int FUN_022ce1d8(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined2 *puVar1;
  int local_8 [2];
  
  local_8[0] = param_4;
  func_0x037c9e90(DAT_022ce248,param_1,1);
  func_0x037c9f1c(DAT_022ce24c,local_8,1);
  if (*(short *)(local_8[0] + (uint)*(ushort *)(local_8[0] + 0xe) * 2 + 0x14) == 0xe) {
    puVar1 = (undefined2 *)func_0x037d14bc();
    *puVar1 = 0x80;
    puVar1[1] = 0x13;
    puVar1[2] = 0x18;
    func_0x037d1464();
    thunk_EXT_FUN_037ff004();
    func_0x037cb674();
  }
  return local_8[0];
}

