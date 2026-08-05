// decomp: module=arm7 addr=0x022d77ec name=FUN_022d77ec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x150 (Ghidra's cache says 0x134 - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=36
// verify:  python tools/match.py --c <file> --func FUN_022d77ec --addr 0x022d77ec --size 0x150 --module arm7 --version 2.0/sp1


void FUN_022d77ec(void)

{
  undefined4 in_r3;
  ushort local_10;
  undefined1 auStack_e [6];
  undefined4 local_8;
  
  local_8 = in_r3;
  FUN_022e2e4c(0x36,6,auStack_e);
  FUN_022e2e4c(0x3c,2,&local_10);
  FUN_022d6e98(auStack_e);
  FUN_022d6ef8(7);
  FUN_022d6f2c(local_10 & DAT_022d7920);
  FUN_022d6f6c(2);
  FUN_022d6fec(0);
  FUN_022d7020(0);
  FUN_022d70c0(0);
  FUN_022d70e4(DAT_022d7924);
  FUN_022d771c(500);
  FUN_022d7144(0);
  FUN_022d717c(0);
  FUN_022d71b4(0x10);
  FUN_022d71ec(DAT_022d7928,0);
  FUN_022d729c(DAT_022d792c);
  FUN_022d72cc(1);
  FUN_022d7374(0);
  FUN_022d7bc8(DAT_022d7930);
  FUN_022d7398(0,0x1f);
  FUN_022d7e6c(5);
  FUN_022d7444(0,0);
  FUN_022d73dc(0);
  FUN_022d7518(0);
  FUN_022d7558(0);
  FUN_022d8d88((uint)*DAT_022d7934 + (uint)*DAT_022d7934 * 0x100,*DAT_022d7934);
  *(undefined2 *)(*DAT_022d7938 + 0x358) = 1;
  return;
}

