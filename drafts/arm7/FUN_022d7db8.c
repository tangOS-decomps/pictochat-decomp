// decomp: module=arm7 addr=0x022d7db8 name=FUN_022d7db8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb4 (Ghidra's cache says 0x98 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=26
// verify:  python tools/match.py --c <file> --func FUN_022d7db8 --addr 0x022d7db8 --size 0xb4 --module arm7 --version 2.0/sp1


void FUN_022d7db8(void)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  int *piVar4;
  
  uVar2 = DAT_022d7e54;
  *DAT_022d7e50 = 0;
  func_0x037c83b4(8000,uVar2);
  piVar4 = DAT_022d7e5c;
  puVar3 = DAT_022d7e58;
  *DAT_022d7e58 = 0;
  if (*(short *)(*piVar4 + 0x5f8) == 2) {
    puVar3[-8] = (short)DAT_022d7e60;
    func_0x037c849c();
    uVar1 = *DAT_022d7e64;
    FUN_022d862c(1,uVar1 & 0x7f);
    FUN_022d862c(1,uVar1);
    func_0x037c83b4(DAT_022d7e68,DAT_022d7e54);
    FUN_022d87fc();
  }
  else if (*(short *)(*piVar4 + 0x5f8) == 3) {
    FUN_022d87fc();
  }
  return;
}

