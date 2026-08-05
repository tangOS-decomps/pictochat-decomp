// decomp: module=unk_autoload_0 addr=0x02324fb0 name=FUN_02324fb0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x90 (Ghidra's cache says 0x8c - it excludes this function's trailing literal pool), thumb
// triage: noise=8 statements=34
// verify:  python tools/match.py --c <file> --func FUN_02324fb0 --addr 0x02324fb0 --size 0x90 --module unk_autoload_0 --version 2.0/sp1


void FUN_02324fb0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 in_r3;
  undefined1 auStack_108 [256];
  undefined4 uStack_8;
  
  iVar1 = *(int *)(DAT_0232503c + 0x2c);
  if (((iVar1 != 2) && (iVar1 != 4)) && (iVar1 != 3)) {
    uStack_8 = in_r3;
    iVar1 = FUN_0232996c();
    if (iVar1 == 0xc) {
      *(undefined4 *)(DAT_0232503c + 0x2c) = 2;
      FUN_02321f9c();
      FUN_023223f0(0x1b,0);
      FUN_023224fc();
    }
    else if (iVar1 == 0xd) {
      *(undefined4 *)(DAT_0232503c + 0x2c) = 4;
      piVar2 = FUN_023260bc();
      FUN_02329650((int)auStack_108,*piVar2);
      FUN_02321fbc(0x34,1,(int)auStack_108);
      FUN_023223f0(0x1b,0);
      FUN_023224fc();
    }
    else if (iVar1 == 0xe) {
      *(undefined4 *)(DAT_0232503c + 0x2c) = 3;
      FUN_02321f9c();
      FUN_023223f0(0x1b,0);
      FUN_023224fc();
    }
  }
  return;
}

