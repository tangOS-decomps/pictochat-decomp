// decomp: module=unk_autoload_0 addr=0x0232ebc0 name=FUN_0232ebc0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x60 - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=28
// verify:  python tools/match.py --c <file> --func FUN_0232ebc0 --addr 0x0232ebc0 --size 0x64 --module unk_autoload_0 --version 2.0/sp1


undefined4 * FUN_0232ebc0(int *param_1,int param_2,int param_3)

{
  int p;
  undefined4 *puVar1;
  int *a;
  
  a = (int *)(DAT_0232ec20 + param_2 * 0x24);
  if (*param_1 != 0) {
    FUN_0232e988(param_1);
  }
  if ((uint)a[6] <= (uint)*(ushort *)(a + 2)) {
    p = FUN_0232e178(a,0);
    if (p == 0) {
      return (undefined4 *)0x0;
    }
    if (param_3 < (int)(uint)*(byte *)(p + 0x3d)) {
      return (undefined4 *)0x0;
    }
    FUN_0232ed94(p);
  }
  puVar1 = (undefined4 *)FUN_0232edc4(param_3);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_0232ed20(a,puVar1);
  *puVar1 = param_1;
  *param_1 = (int)puVar1;
  return puVar1;
}

