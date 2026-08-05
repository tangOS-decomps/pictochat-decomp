// decomp: module=arm7 addr=0x022db560 name=FUN_022db560
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe4 (Ghidra's cache says 0xdc - it excludes this function's trailing literal pool), arm
// triage: noise=8 statements=32
// verify:  python tools/match.py --c <file> --func FUN_022db560 --addr 0x022db560 --size 0xe4 --module arm7 --version 2.0/sp1


void FUN_022db560(void)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  
  iVar2 = *DAT_022db63c;
  puVar3 = (undefined2 *)(iVar2 + 0x404);
  if (*(short *)(iVar2 + 0x404) == 0x30) {
    iVar1 = FUN_022dfe18(*(int *)(iVar2 + 0x41c) + 0x10,0,0);
    if (iVar1 == 0) {
      *(undefined2 *)(*(int *)(iVar2 + 0x420) + 4) = 8;
      *puVar3 = 0x35;
      func_0x037c5628(2,2);
    }
    else {
      *(undefined2 *)(iVar1 + 0x2c) = *(undefined2 *)(*(int *)(iVar2 + 0x41c) + 0x16);
      *(undefined2 *)(iVar1 + 0x2e) = 1;
      *(undefined2 *)(iVar1 + 0x30) = 0;
      *puVar3 = 0x31;
      FUN_022df098();
      FUN_022d8b1c(*(undefined2 *)(*(int *)(iVar2 + 0x41c) + 0x18),DAT_022db640);
    }
  }
  else if (*(short *)(iVar2 + 0x404) == 0x35) {
    FUN_022decf0(1);
    FUN_022dec8c(1);
    FUN_022df00c(1,0);
    *puVar3 = 0;
    FUN_022dbb30();
  }
  return;
}

