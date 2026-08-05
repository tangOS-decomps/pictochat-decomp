// decomp: module=unk_autoload_0 addr=0x0232e514 name=FUN_0232e514
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x86 - it excludes this function's trailing literal pool), thumb
// triage: noise=18 statements=36
// verify:  python tools/match.py --c <file> --func FUN_0232e514 --addr 0x0232e514 --size 0x8c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232e514(uint *param_1,uint *param_2)

{
  undefined4 *after;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *local_18;
  uint local_14;
  
  local_18 = (undefined4 *)*param_2;
  local_14 = param_2[1];
  after = (undefined4 *)0x0;
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_1;
    do {
      puVar2 = puVar1;
      if ((undefined4 *)*param_2 <= puVar2) {
        if (puVar2 == (undefined4 *)param_2[1]) {
          local_14 = (int)puVar2 + puVar2[1] + 0x10;
          FUN_0232e27c(param_1);
        }
        break;
      }
      puVar1 = (undefined4 *)puVar2[3];
      after = puVar2;
    } while ((undefined4 *)puVar2[3] != (undefined4 *)0x0);
  }
  if ((after != (undefined4 *)0x0) && ((int)after + after[1] + 0x10 == *param_2)) {
    local_18 = after;
    after = (undefined4 *)FUN_0232e27c(param_1,after);
  }
  if (local_14 - (int)local_18 < 0x10) {
    return 0;
  }
  puVar1 = (undefined4 *)FUN_0232e2b8(&local_18,DAT_0232e59c);
  FUN_0232e298(param_1,puVar1,after);
  return 1;
}

