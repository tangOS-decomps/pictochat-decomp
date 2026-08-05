// decomp: module=unk_autoload_0 addr=0x02339410 name=FUN_02339410
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x42, thumb
// triage: noise=1 statements=16
// verify:  python tools/match.py --c <file> --func FUN_02339410 --addr 0x02339410 --size 0x42 --module unk_autoload_0 --version 2.0/sp1


void FUN_02339410(uint *param_1,uint *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint local_10;
  
  local_10 = param_4;
  iVar1 = FUN_02339298(0xf,3,&local_10);
  if (iVar1 == 0) {
    if (param_1 != (uint *)0x0) {
      *param_1 = (uint)((local_10 & 8) != 0);
    }
    if (param_2 != (uint *)0x0) {
      *param_2 = (uint)((local_10 & 4) != 0);
    }
  }
  return;
}

