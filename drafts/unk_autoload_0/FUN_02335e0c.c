// decomp: module=unk_autoload_0 addr=0x02335e0c name=FUN_02335e0c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x84, arm
// triage: noise=6 statements=51
// verify:  python tools/match.py --c <file> --func FUN_02335e0c --addr 0x02335e0c --size 0x84 --module unk_autoload_0 --version 2.0/sp1


undefined8 FUN_02335e0c(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  undefined8 uVar5;
  
  uVar2 = (param_1 ^ param_2) & 0x80000000;
  bVar3 = (int)param_1 < 0;
  if (bVar3) {
    param_1 = -param_1;
    uVar2 = uVar2 + 1;
  }
  bVar4 = param_2 != 0;
  if ((int)param_2 < 0) {
    param_2 = -param_2;
  }
  uVar1 = param_1;
  if (bVar4) {
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
                    /* WARNING: Could not recover jumptable at 0x02335e78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*(code *)(&LAB_02335e80 + uVar1 * 0xc))
                        ((param_1 << (uVar1 & 0xff)) * 2,-param_2,uVar1 * 3,uVar2);
      return uVar5;
    }
    uVar1 = 0;
    param_2 = param_1;
  }
  if ((uVar2 & 0x80000000) != 0) {
    uVar1 = -uVar1;
  }
  if (bVar3) {
    param_2 = -param_2;
  }
  return CONCAT44(param_2,uVar1);
}

