// decomp: module=arm7 addr=0x022c3fc4 name=FUN_022c3fc4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20, arm
// triage: noise=2 statements=6
// verify:  python tools/match.py --c <file> --func FUN_022c3fc4 --addr 0x022c3fc4 --size 0x20 --module arm7 --version 2.0/sp1


undefined8 FUN_022c3fc4(uint param_1,int param_2,uint param_3,int param_4)

{
  return CONCAT44(param_3 * param_2 +
                  param_1 * param_4 + (int)((ulonglong)param_3 * (ulonglong)param_1 >> 0x20),
                  (int)((ulonglong)param_3 * (ulonglong)param_1));
}

