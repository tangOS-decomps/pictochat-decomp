// decomp: module=unk_autoload_0 addr=0x0232a8b8 name=FUN_0232a8b8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x70 (Ghidra's cache says 0x58 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=19
// verify:  python tools/match.py --c <file> --func FUN_0232a8b8 --addr 0x0232a8b8 --size 0x70 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a8b8(void)

{
  int iVar1;
  undefined2 local_c;
  undefined2 local_a;
  int local_8;
  
  iVar1 = DAT_0232a910;
  if (*(int *)(DAT_0232a910 + 0x10) == 0) {
    *(undefined4 *)(DAT_0232a910 + 0x10) = 1;
    local_c = 5;
    local_a = 0x68;
    local_8 = DAT_0232a914 * *(int *)(iVar1 + 0x4c) + DAT_0232a918;
    *(int *)(iVar1 + 0x4c) = local_8;
    FUN_02337584(&local_c,*(undefined4 *)(iVar1 + 0x3c),8);
    FUN_02337584(DAT_0232a91c,*(int *)(DAT_0232a910 + 0x3c) + 8,0x60);
    FUN_0232c100(0xc,*(undefined4 *)(DAT_0232a910 + 0x3c),0x68,DAT_0232a924,DAT_0232a920);
  }
  return;
}

