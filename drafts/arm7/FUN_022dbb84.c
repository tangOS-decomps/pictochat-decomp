// decomp: module=arm7 addr=0x022dbb84 name=FUN_022dbb84
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7c (Ghidra's cache says 0x78 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=18
// verify:  python tools/match.py --c <file> --func FUN_022dbb84 --addr 0x022dbb84 --size 0x7c --module arm7 --version 2.0/sp1


bool FUN_022dbb84(ushort *param_1,undefined2 param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = func_0x037c58fc(*DAT_022dbbfc + 0x188,0x18);
  if (iVar2 != 0) {
    *(undefined2 *)(iVar2 + 0xc) = 0x84;
    *(undefined2 *)(iVar2 + 0xe) = 4;
    FUN_022d811c((ushort *)(iVar2 + 0x10),param_1);
    piVar1 = DAT_022dbbfc;
    *(undefined2 *)(iVar2 + 0x16) = param_2;
    func_0x037c5de8(*piVar1 + 0x188,iVar2);
  }
  else {
    FUN_022d9088(1);
  }
  return iVar2 != 0;
}

