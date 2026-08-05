// decomp: module=unk_autoload_0 addr=0x023326f0 name=FUN_023326f0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x44 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=24
// verify:  python tools/match.py --c <file> --func FUN_023326f0 --addr 0x023326f0 --size 0x4c --module unk_autoload_0 --version 2.0/sp1


void FUN_023326f0(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  bVar1 = true;
  if ((int)(*DAT_02332734 & 0x8000) >> 0xf != 0) {
    iVar3 = FUN_023393e0();
    uVar2 = DAT_02332738;
    while (iVar3 == 4) {
      FUN_023320fc(uVar2);
      iVar3 = FUN_023393e0();
    }
    if (iVar3 == 0) {
      bVar1 = false;
    }
  }
  if (bVar1) {
    FUN_0233273c(1,1);
  }
  FUN_023373a8();
  FUN_02332274();
  return;
}

