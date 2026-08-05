// decomp: module=unk_autoload_0 addr=0x02322244 name=FUN_02322244
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48 (Ghidra's cache says 0x3a - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=14
// verify:  python tools/match.py --c <file> --func FUN_02322244 --addr 0x02322244 --size 0x48 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322244(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 0x54;
    FUN_02321634(param_1,DAT_02322284 + iVar1 + 0x14,DAT_02322288,
                 *(undefined2 *)(DAT_02322280 + iVar2 * 8 + 2),param_4);
    FUN_02321684(DAT_02322284 + iVar1 + 0x14,DAT_02322288,*(undefined4 *)(DAT_02322284 + iVar1));
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  return;
}

