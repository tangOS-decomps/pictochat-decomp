// decomp: module=unk_autoload_0 addr=0x0232a824 name=FUN_0232a824
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7c (Ghidra's cache says 0x64 - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=22
// verify:  python tools/match.py --c <file> --func FUN_0232a824 --addr 0x0232a824 --size 0x7c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a824(void)

{
  int iVar1;
  undefined2 local_c;
  undefined2 local_a;
  int local_8;
  
  iVar1 = DAT_0232a888;
  if (*(int *)(DAT_0232a888 + 0x20) == 0) {
    *(undefined4 *)(DAT_0232a888 + 0x20) = 1;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    local_c = 4;
    local_a = 0x68;
    local_8 = DAT_0232a88c * *(int *)(iVar1 + 0x4c) + DAT_0232a890;
    *(int *)(iVar1 + 0x4c) = local_8;
    FUN_02337584(&local_c,*(undefined4 *)(iVar1 + 0x44),8);
    FUN_02337584(DAT_0232a894,*(int *)(DAT_0232a888 + 0x44) + 8,0x60);
    FUN_0232c100(0xc,*(undefined4 *)(DAT_0232a888 + 0x44),0x68,DAT_0232a89c,DAT_0232a898);
    return;
  }
  *(undefined4 *)(DAT_0232a888 + 0x24) = 1;
  return;
}

