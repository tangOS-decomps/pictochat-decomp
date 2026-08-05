// decomp: module=unk_autoload_0 addr=0x0232ca3c name=FUN_0232ca3c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x5a - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=27
// verify:  python tools/match.py --c <file> --func FUN_0232ca3c --addr 0x0232ca3c --size 0x60 --module unk_autoload_0 --version 2.0/sp1


undefined2 FUN_0232ca3c(void)

{
  short sVar1;
  void *pvVar2;
  int iVar3;
  short *psVar4;
  
  pvVar2 = FUN_0232c4d0();
  iVar3 = FUN_0232c4dc();
  if (iVar3 != 0) {
    return 0;
  }
  FUN_023314cc(*(undefined4 *)((int)pvVar2 + 4),2);
  psVar4 = *(short **)((int)pvVar2 + 4);
  sVar1 = *psVar4;
  if (sVar1 == 9) {
    FUN_023314cc((int)psVar4 + DAT_0232ca98,2);
    psVar4 = *(short **)((int)pvVar2 + 4);
    if (*(short *)((int)psVar4 + DAT_0232ca98) == 0) {
      return 0;
    }
  }
  else if ((sVar1 != 10) && (sVar1 != 0xb)) {
    return 0;
  }
  FUN_023314cc(psVar4 + 0x5e,2);
  return *(undefined2 *)(*(int *)((int)pvVar2 + 4) + 0xbc);
}

