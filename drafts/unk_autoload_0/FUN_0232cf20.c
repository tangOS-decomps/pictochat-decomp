// decomp: module=unk_autoload_0 addr=0x0232cf20 name=FUN_0232cf20
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x60 - it excludes this function's trailing literal pool), thumb
// triage: noise=17 statements=27
// verify:  python tools/match.py --c <file> --func FUN_0232cf20 --addr 0x0232cf20 --size 0x64 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232cf20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5,int param_6,undefined2 param_7,undefined1 param_8,
                 undefined1 param_9,int param_10,undefined1 param_11)

{
  uint local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  
  FUN_02337440(0,&local_24,0x10);
  local_24 = DAT_0232cf80;
  local_20 = (undefined2)param_6;
  local_1a = param_7;
  local_18 = param_8;
  local_17 = param_9;
  local_16 = param_11;
  if ((param_10 != 0) && (param_6 != 0)) {
    local_24 = DAT_0232cf80 | 4;
    local_1c = local_20;
  }
  local_1e = local_20;
  FUN_0232ce20(param_1,param_2,param_3,param_4,param_5,&local_24);
  return;
}

