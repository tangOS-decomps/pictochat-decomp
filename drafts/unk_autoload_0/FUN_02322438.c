// decomp: module=unk_autoload_0 addr=0x02322438 name=FUN_02322438
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x6c (Ghidra's cache says 0x54 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=21
// verify:  python tools/match.py --c <file> --func FUN_02322438 --addr 0x02322438 --size 0x6c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02322438(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (((*(int *)(PTR_DAT_02322494 + 8) == 0) ||
      ((*(uint *)PTR_DAT_02322494 & *(uint *)(PTR_DAT_02322490 + param_1 * 4)) == 0)) ||
     (*(int *)(PTR_DAT_0232248c + param_1 * 0x54 + 8) != 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  iVar2 = FUN_023213c4((undefined4 *)PTR_DAT_0232249c,
                       (uint)*(ushort *)(PTR_DAT_02322498 + param_1 * 8));
  iVar3 = FUN_023212bc(*(undefined2 *)(PTR_DAT_023224a0 + param_1 * 8));
  if ((bVar1) && ((iVar2 != 0 || (iVar3 != 0)))) {
    return 1;
  }
  return 0;
}

