// decomp: module=unk_autoload_0 addr=0x02325308 name=FUN_02325308
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe4 (Ghidra's cache says 0xd4 - it excludes this function's trailing literal pool), thumb
// triage: noise=11 statements=50
// verify:  python tools/match.py --c <file> --func FUN_02325308 --addr 0x02325308 --size 0xe4 --module unk_autoload_0 --version 2.0/sp1


void FUN_02325308(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_1c;
  
  local_1c = 0;
  uVar1 = (*(ushort *)(param_1 + 0x48) & 0xff) >> 4;
  uVar3 = 1;
  if (uVar1 == 2) {
    local_1c = 1;
    uVar3 = 2;
    switch(*(undefined1 *)(param_1 + 0x570)) {
    case 1:
      uVar2 = FUN_02335e0c(*(undefined1 *)(param_1 + 0x571),6);
      FUN_02335e0c(uVar2,0xd);
      local_1c = extraout_r1_01 + 3;
      FUN_02322d64();
      break;
    case 3:
      FUN_02335e0c(param_2,0xd);
      local_1c = extraout_r1 + 3;
      break;
    case 4:
      FUN_02335e0c(param_3,0xd);
      local_1c = extraout_r1_00 + 3;
    }
    *(char *)(param_1 + DAT_023253e8) = *(char *)(param_1 + DAT_023253e8) + '\x01';
  }
  else if (uVar1 == 3) {
    uVar3 = 4;
  }
  if ((*(ushort *)(param_1 + 0x48) & 0xf) == 0) {
    FUN_0232529c(*(undefined4 *)(param_1 + 0x10),param_2,param_3,local_1c);
  }
  else if ((*(ushort *)(param_1 + 0x48) & 0xf) == 1) {
    for (iVar4 = 0; iVar4 < (int)uVar3; iVar4 = iVar4 + 1) {
      for (iVar5 = 0; iVar5 < (int)uVar3; iVar5 = iVar5 + 1) {
        FUN_0232529c(*(undefined4 *)(param_1 + 0x10),iVar5 + (param_2 - uVar3 / 2),
                     iVar4 + (param_3 - uVar3 / 2),local_1c);
      }
    }
  }
  return;
}

