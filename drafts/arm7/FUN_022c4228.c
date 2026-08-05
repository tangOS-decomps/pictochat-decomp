// decomp: module=arm7 addr=0x022c4228 name=FUN_022c4228
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50, arm
// triage: noise=3 statements=27
// verify:  python tools/match.py --c <file> --func FUN_022c4228 --addr 0x022c4228 --size 0x50 --module arm7 --version 2.0/sp1


void FUN_022c4228(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 <= param_1) {
    uVar1 = 0x1c;
    uVar2 = param_1 >> 4;
    if ((int)param_2 <= (int)(param_1 >> 0x10)) {
      uVar1 = 0xc;
      uVar2 = param_1 >> 0x14;
    }
    if ((int)param_2 <= (int)(uVar2 >> 4)) {
      uVar1 = uVar1 - 8;
      uVar2 = uVar2 >> 8;
    }
    if ((int)param_2 <= (int)uVar2) {
      uVar1 = uVar1 - 4;
      uVar2 = uVar2 >> 4;
    }
                    /* WARNING: Could not recover jumptable at 0x022c4274. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&LAB_022c427c + uVar1 * 0xc))
              ((param_1 << (uVar1 & 0xff)) * 2,-param_2,uVar1 * 3,uVar2);
    return;
  }
  return;
}

