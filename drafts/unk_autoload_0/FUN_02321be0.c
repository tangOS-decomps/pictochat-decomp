// decomp: module=unk_autoload_0 addr=0x02321be0 name=FUN_02321be0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x78 (Ghidra's cache says 0x44 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=16
// verify:  python tools/match.py --c <file> --func FUN_02321be0 --addr 0x02321be0 --size 0x78 --module unk_autoload_0 --version 2.0/sp1


void FUN_02321be0(void)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  
  FUN_0232daa8(DAT_02321c24,DAT_02321c28,DAT_02321c2c);
  FUN_0232daa8(DAT_02321c30,DAT_02321c34,DAT_02321c38);
  FUN_0232daa8(DAT_02321c3c,DAT_02321c40,DAT_02321c44);
  FUN_0232daa8(DAT_02321c48,DAT_02321c4c,DAT_02321c50);
  puVar2 = DAT_02321c54;
  iVar1 = DAT_02321c24;
  for (uVar3 = 0; uVar3 < 4; uVar3 = uVar3 + 1) {
    FUN_0232df28(iVar1 + uVar3 * 0x20,*puVar2);
  }
  return;
}

