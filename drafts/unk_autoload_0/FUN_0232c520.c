// decomp: module=unk_autoload_0 addr=0x0232c520 name=FUN_0232c520
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=22
// verify:  python tools/match.py --c <file> --func FUN_0232c520 --addr 0x0232c520 --size 0x50 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232c520(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  uint local_c [3];
  
  local_c[0] = param_2;
  local_c[1] = param_3;
  local_c[2] = param_4;
  iVar2 = FUN_0232c4dc();
  if (iVar2 == 0) {
    FUN_023314cc(*(undefined4 *)(*(int *)(DAT_0232c56c + 4) + 4),2);
    iVar2 = 3;
    puVar1 = local_c;
    for (; param_1 != 0; param_1 = param_1 + -1) {
      if (*puVar1 == (uint)**(ushort **)(*(int *)(DAT_0232c56c + 4) + 4)) {
        iVar2 = 0;
      }
      puVar1 = puVar1 + 1;
    }
  }
  return iVar2;
}

