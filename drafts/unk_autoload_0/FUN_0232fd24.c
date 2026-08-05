// decomp: module=unk_autoload_0 addr=0x0232fd24 name=FUN_0232fd24
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x6c, thumb
// triage: noise=9 statements=28
// verify:  python tools/match.py --c <file> --func FUN_0232fd24 --addr 0x0232fd24 --size 0x6c --module unk_autoload_0 --version 2.0/sp1


undefined4
FUN_0232fd24(undefined4 param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  char local_20 [2];
  undefined2 local_1e;
  ushort local_1c;
  
  FUN_023380a0(&local_30);
  local_28 = local_30;
  local_24 = local_2c;
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = FUN_023380b0(param_2,local_20,&local_28);
  while( true ) {
    if (iVar1 == 0) {
      return 1;
    }
    if (((local_20[0] == '\x01') && (param_3 == local_1c)) &&
       (iVar1 = FUN_0232fc94(param_1,local_1e,param_4,param_5), iVar1 == 0)) break;
    iVar1 = FUN_023380b0(param_2,local_20,&local_28);
  }
  return 0;
}

