// decomp: module=unk_autoload_0 addr=0x0232c884 name=FUN_0232c884
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0232c884 --addr 0x0232c884 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232c884(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = DAT_0232c8a0;
  iVar1 = DAT_0232c89c;
  *(undefined4 *)(DAT_0232c89c + 8) = DAT_0232c898;
  *(undefined4 *)(iVar1 + 0xc) = 0;
                    /* WARNING: Could not recover jumptable at 0x0232c896. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(DAT_0232c8a4,1000);
  return;
}

