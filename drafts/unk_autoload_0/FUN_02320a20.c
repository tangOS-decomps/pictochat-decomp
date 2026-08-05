// decomp: module=unk_autoload_0 addr=0x02320a20 name=FUN_02320a20
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x3e - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=24
// verify:  python tools/match.py --c <file> --func FUN_02320a20 --addr 0x02320a20 --size 0x44 --module unk_autoload_0 --version 2.0/sp1


void FUN_02320a20(void)

{
  int iVar1;
  uint uVar2;
  
  if (*(uint *)(DAT_02320a60 + 4) < 0x1e) {
    *(uint *)(DAT_02320a60 + 4) = *(uint *)(DAT_02320a60 + 4) + 1;
  }
  if (0x1d < *(uint *)(DAT_02320a60 + 4)) {
    iVar1 = FUN_02320994();
    if (iVar1 == 0) {
      uVar2 = *(int *)(DAT_02320a60 + 4) + 1;
      *(uint *)(DAT_02320a60 + 4) = uVar2;
      if (0x27 < uVar2) {
        FUN_023209c4();
        *(undefined4 *)(DAT_02320a60 + 4) = 0;
        return;
      }
    }
    else {
      *(undefined4 *)(DAT_02320a60 + 4) = 0x1e;
    }
  }
  return;
}

