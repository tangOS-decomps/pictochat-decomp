// decomp: module=arm7 addr=0x022c565c name=FUN_022c565c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c, arm
// triage: noise=7 statements=9
// verify:  python tools/match.py --c <file> --func FUN_022c565c --addr 0x022c565c --size 0x2c --module arm7 --version 2.0/sp1


void FUN_022c565c(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x022c5684. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(*(int *)(param_1 + 0x3c) + -4))
            (*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
             *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
  return;
}

