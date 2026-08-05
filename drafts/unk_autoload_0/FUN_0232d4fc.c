// decomp: module=unk_autoload_0 addr=0x0232d4fc name=FUN_0232d4fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2e - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=20
// verify:  python tools/match.py --c <file> --func FUN_0232d4fc --addr 0x0232d4fc --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232d4fc(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  puVar2 = DAT_0232d52c;
  *DAT_0232d52c = 0x80;
  iVar1 = 0;
  puVar2 = puVar2 + 7;
  do {
    uVar3 = *(undefined4 *)(param_1 + (1 - iVar1) * 4);
    iVar1 = iVar1 + 1;
    *puVar2 = (char)((uint)uVar3 >> 0x18);
    puVar2[1] = (char)((uint)uVar3 >> 0x10);
    puVar2[2] = (char)((uint)uVar3 >> 8);
    puVar2[3] = (char)uVar3;
    puVar2 = puVar2 + 4;
  } while (iVar1 < 2);
  return;
}

