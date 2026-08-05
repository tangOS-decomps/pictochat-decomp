// decomp: module=unk_autoload_0 addr=0x02323c90 name=FUN_02323c90
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x70, thumb
// triage: noise=0 statements=46  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02323c90 --addr 0x02323c90 --size 0x70 --module unk_autoload_0 --version 2.0/sp1


ushort FUN_02323c90(int param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 8) + 0xc);
  if (uVar2 < param_2) {
    uVar1 = *(ushort *)(*(int *)(param_1 + 0x14) + ((param_2 - uVar2) + -1) * 2);
    if (uVar1 < 0x21) {
      return 0;
    }
  }
  else {
    switch(param_2) {
    default:
      return 0;
    case 1:
      return 8;
    case 2:
      return 10;
    case 3:
      if (*(int *)(param_1 + 0x28) == 1) {
        return 0x3000;
      }
      return 0x20;
    case 6:
      if (*(int *)(param_1 + 0x28) == 1) {
        return 7;
      }
      break;
    case 7:
      if (*(int *)(param_1 + 0x28) == 1) {
        return 9;
      }
      break;
    case 8:
      if (*(int *)(param_1 + 0x28) == 1) {
        return 0xb;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

