// decomp: module=unk_autoload_0 addr=0x0232c954 name=FUN_0232c954
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44, thumb
// triage: noise=0 statements=16  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232c954 --addr 0x0232c954 --size 0x44 --module unk_autoload_0 --version 2.0/sp1


uint FUN_0232c954(void)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = FUN_0232c4d0();
  iVar2 = FUN_0232c520(2,7,8);
  if (iVar2 != 0) {
    return 0;
  }
  FUN_023314cc(*(int *)((int)pvVar1 + 4) + 0xc,4);
  if (*(int *)(*(int *)((int)pvVar1 + 4) + 0xc) == 1) {
    return 0;
  }
  FUN_023314cc(*(int *)((int)pvVar1 + 4) + 0x3c,4);
  return *(ushort *)(*(int *)((int)pvVar1 + 4) + 0x3c) + 0x1f & 0xffffffe0;
}

