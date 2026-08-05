// decomp: module=unk_autoload_0 addr=0x02325834 name=FUN_02325834
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xdc (Ghidra's cache says 0xce - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=38
// verify:  python tools/match.py --c <file> --func FUN_02325834 --addr 0x02325834 --size 0xdc --module unk_autoload_0 --version 2.0/sp1


void FUN_02325834(int param_1,int param_2)

{
  undefined2 uVar1;
  ushort uVar2;
  short sVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = DAT_02325908;
  if ((*(ushort *)(param_1 + DAT_02325904) != 0) || (*(short *)(param_1 + DAT_02325908) != 0)) {
    iVar6 = (uint)*(ushort *)(param_1 + DAT_02325904) * 0x104;
    sVar3 = *(short *)(param_1 + DAT_02325908 + iVar6);
    if (sVar3 != 0) {
      *(short *)(param_1 + DAT_02325908 + iVar6) = sVar3 + -1;
      iVar6 = param_1 + (uint)*(ushort *)(param_1 + DAT_02325904) * 0x104;
      uVar1 = *(undefined2 *)(iVar6 + (uint)*(ushort *)(iVar6 + iVar5) * 2 + 0x56);
      piVar4 = FUN_02321c60();
      sVar3 = FUN_0232de60(piVar4,uVar1);
      iVar5 = DAT_02325904;
      iVar6 = (uint)*(ushort *)(param_1 + DAT_02325904) * 0x104;
      *(short *)(param_1 + 0x158 + iVar6) = *(short *)(param_1 + 0x158 + iVar6) - (sVar3 + 1);
      iVar6 = (uint)*(ushort *)(param_1 + iVar5) * 0x10;
      iVar7 = *(ushort *)(param_1 + (uint)*(ushort *)(param_1 + iVar5) * 0x104 + 0x158) + 0x18;
      piVar4 = FUN_02321c60();
      iVar5 = FUN_0232de60(piVar4,uVar1);
      FUN_0232153c(param_1 + 0x14,iVar7,(uint)*(ushort *)(param_1 + DAT_0232590c) + iVar6,
                   iVar7 + iVar5,(uint)*(ushort *)(param_1 + DAT_0232590c) + iVar6 + 0x10,0);
    }
    if (param_2 != 0) {
      uVar2 = *(ushort *)(param_1 + DAT_02325904);
      if ((*(short *)(param_1 + (uint)uVar2 * 0x104 + DAT_02325908) == 0) && (uVar2 != 0)) {
        *(ushort *)(param_1 + DAT_02325904) = uVar2 - 1;
      }
    }
  }
  return;
}

