// decomp: module=unk_autoload_0 addr=0x0232c408 name=FUN_0232c408
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7c (Ghidra's cache says 0x76 - it excludes this function's trailing literal pool), thumb
// triage: noise=11 statements=33
// verify:  python tools/match.py --c <file> --func FUN_0232c408 --addr 0x0232c408 --size 0x7c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232c408(undefined2 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined4 local_8 [2];
  
  local_8[0] = param_3;
  local_8[1] = param_4;
  puVar1 = (undefined2 *)FUN_0232c3cc();
  if (puVar1 == (undefined2 *)0x0) {
    return 8;
  }
  *puVar1 = param_1;
  puVar2 = local_8;
  iVar3 = 0;
  puVar4 = puVar1;
  if ((param_2 & 0xffff) != 0) {
    do {
      iVar3 = iVar3 + 1;
      *(undefined4 *)(puVar4 + 2) = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 2;
    } while (iVar3 < (int)(param_2 & 0xffff));
  }
  FUN_023314e8(puVar1,0x100);
  iVar3 = FUN_0233831c(10,puVar1,0);
  FUN_02331244(DAT_0232c480,puVar1,1);
  if (-1 < iVar3) {
    return 2;
  }
  return 8;
}

