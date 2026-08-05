// decomp: module=unk_autoload_0 addr=0x0232aadc name=FUN_0232aadc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x4a - it excludes this function's trailing literal pool), thumb
// triage: noise=9 statements=24
// verify:  python tools/match.py --c <file> --func FUN_0232aadc --addr 0x0232aadc --size 0x64 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232aadc(void)

{
  int iVar1;
  int iVar2;
  int extraout_r1;
  undefined4 in_r3;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = FUN_02331ca8();
  iVar1 = DAT_0232ab28;
  *(undefined8 *)(DAT_0232ab28 + 0x5c) = uVar4;
  iVar3 = DAT_0232ab2c * *(int *)(iVar1 + 0x4c);
  iVar2 = iVar3 + DAT_0232ab30;
  *(int *)(iVar1 + 0x4c) = iVar2;
  FUN_02336018(iVar2,200,iVar1,iVar3,in_r3);
  iVar1 = DAT_0232ab28;
  *(int *)(DAT_0232ab28 + 0x58) = extraout_r1 * 5 + 0x4b0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  if (*(int *)(iVar1 + 0x54) == 0) {
    *(undefined4 *)(iVar1 + 0x54) = 1;
    FUN_02331ea8(DAT_0232ab34,DAT_0232ab38,0,DAT_0232ab3c,0);
  }
  return;
}

