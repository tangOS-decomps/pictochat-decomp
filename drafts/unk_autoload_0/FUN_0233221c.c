// decomp: module=unk_autoload_0 addr=0x0233221c name=FUN_0233221c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=27
// verify:  python tools/match.py --c <file> --func FUN_0233221c --addr 0x0233221c --size 0x58 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233221c(uint param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = FUN_02332080();
  iVar2 = DAT_02332270;
  puVar1 = DAT_02332268;
  uVar7 = param_1 & *DAT_02332268 & DAT_0233226c;
  while( true ) {
    iVar4 = FUN_023321f4(uVar7);
    uVar5 = 0x1f - iVar4;
    if ((int)uVar5 < 0) break;
    uVar6 = ~(1 << (uVar5 & 0xff));
    uVar7 = uVar7 & uVar6;
    if (param_2 == *(ushort *)(iVar2 + uVar5 * 2)) {
      *(undefined2 *)(iVar2 + uVar5 * 2) = 0;
      *puVar1 = *puVar1 & uVar6;
    }
  }
  FUN_02332094(uVar3);
  return;
}

