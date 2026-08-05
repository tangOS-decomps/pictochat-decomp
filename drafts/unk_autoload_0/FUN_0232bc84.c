// decomp: module=unk_autoload_0 addr=0x0232bc84 name=FUN_0232bc84
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48 (Ghidra's cache says 0x3a - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=24  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232bc84 --addr 0x0232bc84 --size 0x48 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232bc84(int param_1)

{
  short *psVar1;
  
  psVar1 = DAT_0232bcc0;
  if (*DAT_0232bcc0 == *(short *)(param_1 + 0x12)) {
    *DAT_0232bcc0 = (short)DAT_0232bcc4;
    if (*(int *)(psVar1 + 0x1c) != 0) {
      if (*(int *)(psVar1 + 0x16) == 0) {
        psVar1[0x1c] = 0;
        psVar1[0x1d] = 0;
      }
      else {
        psVar1[0x1c] = 3;
        psVar1[0x1d] = 0;
      }
    }
    psVar1 = DAT_0232bcc0;
    psVar1[0x10] = -1;
    psVar1[0x11] = -1;
    FUN_0232b854(DAT_0232bcc8);
    FUN_0232bd8c();
  }
  return;
}

