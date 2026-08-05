// decomp: module=unk_autoload_0 addr=0x023371a4 name=FUN_023371a4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2c - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=26
// verify:  python tools/match.py --c <file> --func FUN_023371a4 --addr 0x023371a4 --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_023371a4(void)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = DAT_023371d0;
  *DAT_023371d0 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar2 = DAT_023371d4;
  *DAT_023371d4 = 0;
  *(undefined1 *)(puVar2 + 1) = 0;
  *(undefined1 *)((int)puVar2 + 5) = 0;
  *(undefined1 *)((int)puVar2 + 6) = 0;
  *(undefined2 *)(puVar2 + 2) = 0;
  return;
}

