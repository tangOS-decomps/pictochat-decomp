// decomp: module=unk_autoload_0 addr=0x0232598c name=FUN_0232598c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc8 (Ghidra's cache says 0xba - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=32
// verify:  python tools/match.py --c <file> --func FUN_0232598c --addr 0x0232598c --size 0xc8 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232598c(int param_1,undefined4 param_2)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  piVar3 = FUN_02321c60();
  uVar2 = FUN_0232de60(piVar3,param_2);
  piVar3 = FUN_02321c60();
  uVar4 = FUN_0232df14(piVar3,param_2);
  if (((uint)uVar2 +
       (uint)*(ushort *)(param_1 + (uint)*(ushort *)(param_1 + DAT_02325a48) * 0x104 + 0x158) < 0xe2
      ) || (iVar5 = FUN_02325960(param_1), iVar5 != 0)) {
    iVar5 = DAT_02325a48;
    iVar6 = (uint)*(ushort *)(param_1 + DAT_02325a48) * 0x104;
    uVar1 = *(ushort *)(param_1 + DAT_02325a4c + iVar6);
    *(ushort *)(param_1 + DAT_02325a4c + iVar6) = uVar1 + 1;
    *(short *)(param_1 + (uint)*(ushort *)(param_1 + iVar5) * 0x104 + (uint)uVar1 * 2 + 0x56) =
         (short)param_2;
    uVar7 = (uint)*(ushort *)(param_1 + iVar5);
    piVar3 = FUN_02321c60();
    FUN_0232dc5c(piVar3,param_1 + 0x14,
                 (*(ushort *)(param_1 + uVar7 * 0x104 + 0x158) + 0x18) - (uVar4 & 0xffff),
                 (uint)*(ushort *)(param_1 + DAT_02325a50) + uVar7 * 0x10,param_2,1);
    iVar5 = (uint)*(ushort *)(param_1 + DAT_02325a48) * 0x104;
    *(ushort *)(param_1 + 0x158 + iVar5) = *(short *)(param_1 + 0x158 + iVar5) + uVar2 + 1;
  }
  return;
}

