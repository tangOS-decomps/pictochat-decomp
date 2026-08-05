// decomp: module=unk_autoload_0 addr=0x0232ba7c name=FUN_0232ba7c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48 (Ghidra's cache says 0x44 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=24
// verify:  python tools/match.py --c <file> --func FUN_0232ba7c --addr 0x0232ba7c --size 0x48 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ba7c(undefined4 param_1,int param_2)

{
  ushort *puVar1;
  ushort uVar2;
  
  puVar1 = DAT_0232bac0;
  *(undefined4 *)(DAT_0232bac0 + 0xc) = *(undefined4 *)(param_2 + 8);
  *puVar1 = (ushort)*(byte *)(param_2 + 4);
  uVar2 = FUN_0232a4e8();
  if (*(byte *)(param_2 + 4) == uVar2) {
    if (*(int *)(DAT_0232bac0 + 10) == 1) {
      if (*(int *)(param_2 + 0x10) == *(int *)(DAT_0232bac0 + 2)) {
        puVar1 = DAT_0232bac0;
        puVar1[10] = 2;
        puVar1[0xb] = 0;
        FUN_0232becc();
        return;
      }
    }
    if (*(uint *)(DAT_0232bac0 + 10) < 2) {
      FUN_0232be80(0);
    }
  }
  return;
}

