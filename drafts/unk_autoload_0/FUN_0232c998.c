// decomp: module=unk_autoload_0 addr=0x0232c998 name=FUN_0232c998
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x86, thumb
// triage: noise=0 statements=26  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232c998 --addr 0x0232c998 --size 0x86 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232c998(void)

{
  short sVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  
  pvVar2 = FUN_0232c4d0();
  iVar3 = FUN_0232c520(2,7,8);
  if (iVar3 != 0) {
    return 0;
  }
  FUN_023314cc(*(int *)((int)pvVar2 + 4) + 0xc,4);
  if (*(int *)(*(int *)((int)pvVar2 + 4) + 0xc) == 1) {
    return 0;
  }
  FUN_023314cc(*(int *)((int)pvVar2 + 4) + 0x188,2);
  sVar1 = *(short *)(*(int *)((int)pvVar2 + 4) + 0x188);
  FUN_023314cc(*(int *)((int)pvVar2 + 4) + 0x3e,2);
  uVar4 = (uint)*(ushort *)(*(int *)((int)pvVar2 + 4) + 0x3e);
  if (sVar1 == 0) {
    FUN_023314cc(*(int *)((int)pvVar2 + 4) + 0xf8,2);
    return ((uint)*(ushort *)(*(int *)((int)pvVar2 + 4) + 0xf8) * (uVar4 + 0xc) + 0x29 & 0xffffffe0)
           << 1;
  }
  return (uVar4 + 0x51 & 0xffffffe0) << 1;
}

