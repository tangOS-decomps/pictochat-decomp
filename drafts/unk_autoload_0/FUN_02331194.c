// decomp: module=unk_autoload_0 addr=0x02331194 name=FUN_02331194
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x40 - it excludes this function's trailing literal pool), arm
// triage: noise=7 statements=10
// verify:  python tools/match.py --c <file> --func FUN_02331194 --addr 0x02331194 --size 0x44 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331194(int param_1)

{
  (*DAT_023311d4)(param_1 + 0x48);
                    /* WARNING: Could not recover jumptable at 0x023311d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(*(int *)(param_1 + 0x3c) + -4))
            (*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
             *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
  return;
}

