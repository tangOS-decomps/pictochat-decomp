// decomp: module=unk_autoload_0 addr=0x0232eca4 name=FUN_0232eca4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x36 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=15
// verify:  python tools/match.py --c <file> --func FUN_0232eca4 --addr 0x0232eca4 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232eca4(int param_1,int param_2)

{
  int iVar1;
  void *obj;
  
  iVar1 = DAT_0232ecdc;
  obj = (void *)FUN_0232e178((int *)(DAT_0232ecdc + param_1 * 0x24 + 0xc),0);
  if (obj == (void *)0x0) {
    return 0;
  }
  FUN_0232e13c((undefined4 *)(iVar1 + param_1 * 0x24 + 0xc),obj);
  *(int *)((int)obj + 0xc) = param_2;
  *(void **)(param_2 + 8) = obj;
  FUN_0232f7dc(*(undefined4 *)((int)obj + 8));
  return *(undefined4 *)((int)obj + 8);
}

