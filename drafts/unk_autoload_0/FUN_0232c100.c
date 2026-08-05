// decomp: module=unk_autoload_0 addr=0x0232c100 name=FUN_0232c100
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x84 (Ghidra's cache says 0x7a - it excludes this function's trailing literal pool), thumb
// triage: noise=12 statements=52
// verify:  python tools/match.py --c <file> --func FUN_0232c100 --addr 0x0232c100 --size 0x84 --module unk_autoload_0 --version 2.0/sp1


undefined4
FUN_0232c100(undefined2 param_1,undefined4 param_2,undefined2 param_3,int param_4,undefined4 param_5
            )

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  int iStack_18;
  
  iVar2 = 0;
  local_20 = 0;
  local_28 = param_2;
  local_1e = param_1;
  local_1c = param_3;
  iStack_18 = param_4;
  if (param_4 == 1) {
    local_1a = 1;
    local_24 = param_5;
    iVar2 = FUN_0232b794(DAT_0232c17c,&local_28,0x10);
    if (iVar2 == 0) {
      FUN_02329bd8(0xc);
    }
  }
  else {
    uVar3 = 1;
    do {
      local_1a = (undefined2)(7 << (uVar3 & 0xff));
      if (iVar2 == 4) {
        local_24 = param_5;
      }
      else {
        local_24 = 0;
      }
      iVar1 = FUN_0232b794(DAT_0232c17c,&local_28,0x10);
      if (iVar1 == 0) {
        FUN_0232a480();
        FUN_02329bd8(0xc);
      }
      iVar2 = iVar2 + 1;
      uVar3 = uVar3 + 3;
    } while (iVar2 < 5);
  }
  if (*DAT_0232c180 == 0) {
    FUN_0232c184();
  }
  return 1;
}

