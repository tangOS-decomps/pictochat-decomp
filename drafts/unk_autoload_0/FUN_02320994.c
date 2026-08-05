// decomp: module=unk_autoload_0 addr=0x02320994 name=FUN_02320994
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x2a - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=19
// verify:  python tools/match.py --c <file> --func FUN_02320994 --addr 0x02320994 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02320994(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int i;
  
  i = 0;
  iVar3 = 0;
  do {
    uVar1 = FUN_0232e998(i);
    i = i + 1;
    iVar3 = iVar3 + (uint)uVar1;
  } while (i < 0x10);
  uVar2 = FUN_02337ed0();
  if (((uVar2 & DAT_023209c0) == 0) && (iVar3 == 0)) {
    return 0;
  }
  return 1;
}

