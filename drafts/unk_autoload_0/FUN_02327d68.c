// decomp: module=unk_autoload_0 addr=0x02327d68 name=FUN_02327d68
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x3e - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=21
// verify:  python tools/match.py --c <file> --func FUN_02327d68 --addr 0x02327d68 --size 0x44 --module unk_autoload_0 --version 2.0/sp1


void FUN_02327d68(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_023271c0(8,1);
  if (iVar1 != 0) {
    FUN_02320978(0xc);
    return;
  }
  iVar1 = FUN_023212ec();
  if (iVar1 == 1) {
    uVar2 = FUN_023212f8();
    uVar3 = FUN_02321304();
    iVar1 = FUN_0232e004(DAT_02327da8,uVar2,uVar3);
    if (iVar1 == 4) {
      FUN_02320978(0xf);
    }
  }
  return;
}

