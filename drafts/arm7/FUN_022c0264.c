// decomp: module=arm7 addr=0x022c0264 name=FUN_022c0264
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x36, thumb
// triage: noise=0 statements=18  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c0264 --addr 0x022c0264 --size 0x36 --module arm7 --version 2.0/sp1


void FUN_022c0264(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = 0;
    do {
      piVar1 = (int *)(param_1 + 0xc + iVar2 * 0x10);
      if ((piVar1[3] & 1U) == param_2) {
        if (*piVar1 != piVar1[1]) {
          thunk_EXT_FUN_0380f600(*piVar1,piVar1[1],piVar1[2]);
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  return;
}

