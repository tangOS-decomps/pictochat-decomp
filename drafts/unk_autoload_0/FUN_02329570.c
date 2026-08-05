// decomp: module=unk_autoload_0 addr=0x02329570 name=FUN_02329570
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x2e - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=16
// verify:  python tools/match.py --c <file> --func FUN_02329570 --addr 0x02329570 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


int FUN_02329570(void)

{
  byte bVar1;
  byte *pbVar2;
  byte extraout_r1;
  
  pbVar2 = DAT_023295a0;
  bVar1 = *DAT_023295a0;
  if (DAT_023295a0[2] != 0) {
    DAT_023295a0[2] = DAT_023295a0[2] - 1;
    *pbVar2 = bVar1 + 1;
    FUN_02335e0c(*pbVar2,6);
    *DAT_023295a0 = extraout_r1;
    return DAT_023295a8 + (uint)bVar1 * DAT_023295a4;
  }
  return 0;
}

