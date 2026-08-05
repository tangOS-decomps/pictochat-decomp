// decomp: module=unk_autoload_0 addr=0x0232bac4 name=FUN_0232bac4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x4e - it excludes this function's trailing literal pool), thumb
// triage: noise=13 statements=26
// verify:  python tools/match.py --c <file> --func FUN_0232bac4 --addr 0x0232bac4 --size 0x58 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232bac4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 *puVar1;
  ushort uVar2;
  code *pcVar3;
  
  if (*(int *)(DAT_0232bb14 + 0x16) == 0) {
    *(undefined4 *)(DAT_0232bb14 + 0x1c) = 0;
  }
  else {
    *(undefined4 *)(DAT_0232bb14 + 0x1c) = 3;
  }
  puVar1 = DAT_0232bb14;
  *(undefined4 *)(DAT_0232bb14 + 0x10) = 0xffffffff;
  pcVar3 = *(code **)(puVar1 + 0x1e);
  if ((pcVar3 != (code *)0x0) && (*(char *)(param_2 + 0xc) != '\0')) {
    (*pcVar3)(*puVar1,*(undefined4 *)(puVar1 + 0x18),*(undefined4 *)(puVar1 + 0xc),pcVar3,param_4);
  }
  uVar2 = FUN_0232a4e8();
  puVar1 = DAT_0232bb14;
  if ((uVar2 == 0) && (*(int *)(DAT_0232bb14 + 10) == 2)) {
    *(undefined4 *)(DAT_0232bb14 + 10) = 0;
    *puVar1 = (short)DAT_0232bb18;
  }
  FUN_0232bd8c();
  return;
}

