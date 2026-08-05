// decomp: module=unk_autoload_0 addr=0x0232e754 name=FUN_0232e754
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x48 - it excludes this function's trailing literal pool), thumb
// triage: noise=8 statements=24
// verify:  python tools/match.py --c <file> --func FUN_0232e754 --addr 0x0232e754 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e754(void)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if (*(int *)(DAT_0232e79c + 0xc) == 0) {
    *(undefined4 *)(DAT_0232e79c + 0xc) = 1;
    FUN_02337958();
    puVar1 = DAT_0232e79c;
    *(undefined4 *)(DAT_0232e79c + 0x10) = DAT_0232e7a0;
    uVar2 = DAT_0232e7a4;
    *(undefined4 *)(puVar1 + 0x14) = 0;
    *(undefined4 *)(puVar1 + 0x20) = uVar2;
    *(undefined4 *)(puVar1 + 0x24) = 0;
    FUN_0233984c(DAT_0232e7a8);
    FUN_02339864(DAT_0232e7ac);
    FUN_0232e8b8();
    FUN_0232f06c();
    FUN_0232ea30();
    puVar1 = DAT_0232e79c;
    *DAT_0232e79c = 0xff;
    *(undefined4 *)(puVar1 + 4) = 1;
  }
  return;
}

