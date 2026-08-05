// decomp: module=unk_autoload_0 addr=0x02332494 name=FUN_02332494
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x32 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=18
// verify:  python tools/match.py --c <file> --func FUN_02332494 --addr 0x02332494 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


void FUN_02332494(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  pcVar3 = *(code **)(param_1 + DAT_023324c8);
  uVar4 = *(undefined4 *)(param_1 + DAT_023324c8 + 4);
  uVar2 = FUN_02332080();
  iVar1 = DAT_023324cc;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffffb3;
  FUN_02330f6c(param_1 + iVar1);
  FUN_02332094(uVar2);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(uVar4);
  }
  return;
}

