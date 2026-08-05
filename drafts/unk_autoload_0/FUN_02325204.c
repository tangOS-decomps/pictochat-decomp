// decomp: module=unk_autoload_0 addr=0x02325204 name=FUN_02325204
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x42 - it excludes this function's trailing literal pool), thumb
// triage: noise=9 statements=22
// verify:  python tools/match.py --c <file> --func FUN_02325204 --addr 0x02325204 --size 0x4c --module unk_autoload_0 --version 2.0/sp1


void FUN_02325204(void)

{
  undefined *puVar1;
  undefined2 uVar2;
  int iVar3;
  
  if ((*(short *)(PTR_DAT_02325248 + 10) == 0) &&
     (iVar3 = FUN_023212bc(*(undefined2 *)(PTR_DAT_02325248 + 8)), iVar3 != 0)) {
    uVar2 = FUN_023212bc(*(undefined2 *)(PTR_DAT_02325248 + 8));
    *(undefined2 *)(PTR_DAT_02325248 + 10) = uVar2;
    return;
  }
  iVar3 = FUN_023212c8(*(undefined2 *)(PTR_DAT_02325248 + 10));
  puVar1 = PTR_DAT_02325248;
  if (iVar3 != 0) {
    FUN_0232519c(PTR_DAT_0232524c);
    return;
  }
  *(undefined2 *)PTR_DAT_02325248 = 0;
  *(undefined2 *)(puVar1 + 6) = 0;
  *(undefined2 *)(puVar1 + 10) = 0;
  return;
}

