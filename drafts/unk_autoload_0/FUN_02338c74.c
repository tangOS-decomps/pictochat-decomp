// decomp: module=unk_autoload_0 addr=0x02338c74 name=FUN_02338c74
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48 (Ghidra's cache says 0x3e - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=24  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02338c74 --addr 0x02338c74 --size 0x48 --module unk_autoload_0 --version 2.0/sp1


void FUN_02338c74(void)

{
  short *psVar1;
  int iVar2;
  
  if (*DAT_02338cb4 == 0) {
    *DAT_02338cb4 = 1;
    FUN_023381f8();
    psVar1 = DAT_02338cb4;
    DAT_02338cb4[8] = 0;
    psVar1[2] = 0;
    psVar1[3] = 0;
    psVar1[10] = 0;
    psVar1[0xb] = 0;
    psVar1[0x1b] = 0;
    psVar1[0x1a] = 0;
    psVar1[0x1d] = 0;
    psVar1[0x1c] = 0;
    do {
      iVar2 = FUN_023382f8(6,1);
    } while (iVar2 == 0);
    FUN_023382ac(6,DAT_02338cb8);
  }
  return;
}

