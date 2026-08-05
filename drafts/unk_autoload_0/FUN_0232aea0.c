// decomp: module=unk_autoload_0 addr=0x0232aea0 name=FUN_0232aea0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x88 (Ghidra's cache says 0x76 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=30
// verify:  python tools/match.py --c <file> --func FUN_0232aea0 --addr 0x0232aea0 --size 0x88 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232aea0(short *param_1)

{
  uchar uVar1;
  int iVar2;
  int extraout_r1;
  
  if (*param_1 == 1) {
    FUN_02329bcc();
  }
  iVar2 = FUN_0232981c();
  if (iVar2 == 0) {
    if (param_1[1] == 0) {
      FUN_02329bd8(1);
      iVar2 = DAT_0232af1c;
      *(short *)(DAT_0232af1c + 0xc) = (short)DAT_0232af18;
      *(undefined4 *)(iVar2 + 0x30) = 0;
      *(undefined4 *)(iVar2 + 0x40) = 0;
      if (*(int *)(iVar2 + 0x2c) != 0) {
        *(int *)(iVar2 + 0x4c) = DAT_0232af20 * *(int *)(iVar2 + 0x4c) + DAT_0232af24;
        uVar1 = FUN_02329dac();
        FUN_02336018(*(undefined4 *)(DAT_0232af1c + 0x4c),200);
        FUN_02329db8(uVar1,1,1,extraout_r1 * 2 + 500);
        return;
      }
      FUN_0232a1e4();
      return;
    }
    FUN_02329bd8(0xc);
  }
  return;
}

