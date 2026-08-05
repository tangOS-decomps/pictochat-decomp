// decomp: module=unk_autoload_0 addr=0x0232d2cc name=FUN_0232d2cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x54 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=25
// verify:  python tools/match.py --c <file> --func FUN_0232d2cc --addr 0x0232d2cc --size 0x60 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232d2cc(void)

{
  undefined1 *puVar1;
  int iVar2;
  ushort *puVar3;
  undefined4 in_r3;
  undefined4 local_10;
  undefined4 uStack_c;
  
  uStack_c = in_r3;
  iVar2 = FUN_0232d530(DAT_0232d320);
  *DAT_0232d324 = iVar2;
  if (iVar2 != 0) {
    local_10 = 0;
    FUN_02332d32(&local_10,DAT_0232d320,DAT_0232d328);
    puVar1 = DAT_0232d320;
    *DAT_0232d320 = 5;
    puVar3 = (ushort *)(puVar1 + 100);
    *puVar3 = *puVar3 & 0xffcf | 0x20;
    *puVar3 = *puVar3 & 0xfff8 | 1;
    *puVar3 = *puVar3 | 0x200;
    puVar1[3] = 1;
    puVar1[4] = 1;
  }
  return;
}

