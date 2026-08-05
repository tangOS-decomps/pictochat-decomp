// decomp: module=unk_autoload_0 addr=0x02338d6c name=FUN_02338d6c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x5a - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=24
// verify:  python tools/match.py --c <file> --func FUN_02338d6c --addr 0x02338d6c --size 0x60 --module unk_autoload_0 --version 2.0/sp1


void FUN_02338d6c(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = FUN_02332080();
  iVar3 = FUN_0233831c(6,0x3000000,0);
  iVar1 = DAT_02338dc8;
  if (iVar3 < 0) {
    FUN_02332094(uVar2);
    iVar1 = DAT_02338dc8;
    *(ushort *)(DAT_02338dc8 + 0x38) = *(ushort *)(DAT_02338dc8 + 0x38) | 1;
    if (*(code **)(iVar1 + 4) != (code *)0x0) {
      (**(code **)(iVar1 + 4))(0,4,0);
      return;
    }
  }
  else {
    *(ushort *)(DAT_02338dc8 + 0x3a) = *(ushort *)(DAT_02338dc8 + 0x3a) | 1;
    *(ushort *)(iVar1 + 0x38) = *(ushort *)(iVar1 + 0x38) & 0xfffe;
    FUN_02332094(uVar2);
  }
  return;
}

