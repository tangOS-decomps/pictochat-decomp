// decomp: module=unk_autoload_0 addr=0x0232a7c4 name=FUN_0232a7c4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x4e - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=16
// verify:  python tools/match.py --c <file> --func FUN_0232a7c4 --addr 0x0232a7c4 --size 0x60 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a7c4(void)

{
  int iVar1;
  undefined2 local_c;
  undefined2 local_a;
  int local_8;
  
  iVar1 = DAT_0232a814;
  local_c = 6;
  local_a = 0x68;
  local_8 = DAT_0232a818 * *(int *)(DAT_0232a814 + 0x4c) + DAT_0232a81c;
  *(int *)(DAT_0232a814 + 0x4c) = local_8;
  FUN_02337584(&local_c,*(undefined4 *)(iVar1 + 0x44),8);
  FUN_02337584(DAT_0232a820,*(int *)(DAT_0232a814 + 0x44) + 8,0x60);
  FUN_0232c100(0xc,*(undefined4 *)(DAT_0232a814 + 0x44),0x68,1,0);
  return;
}

