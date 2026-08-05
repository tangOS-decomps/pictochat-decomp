// decomp: module=unk_autoload_0 addr=0x02321708 name=FUN_02321708
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x66, thumb
// triage: noise=6 statements=27
// verify:  python tools/match.py --c <file> --func FUN_02321708 --addr 0x02321708 --size 0x66 --module unk_autoload_0 --version 2.0/sp1


void FUN_02321708(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_20;
  int local_1c;
  undefined4 uStack_18;
  
  iVar4 = (uint)*(ushort *)(param_1 + 0x14) * 0x80;
  iVar2 = ((uint)*(ushort *)(param_1 + 0x14) - (uint)*(ushort *)(*(int *)(param_1 + 0x24) + 0xc)) *
          0x80;
  uStack_18 = param_4;
  FUN_02321798(*(undefined4 *)(param_1 + 0x10),&local_1c,&local_20);
  iVar3 = (int)((uint)*(ushort *)(param_1 + 0x1a) *
               (uint)*(ushort *)(param_1 + 0x18) * local_1c * local_20) / 2;
  FUN_023314e8(*(int *)(*(int *)(param_1 + 0x24) + 0x14) + iVar2,iVar3);
  iVar1 = *(int *)(*(int *)(param_1 + 0x24) + 0x14);
  if (*(short *)(*(int *)(param_1 + 0x24) + 0x10) == 0) {
    FUN_0233697c(iVar1 + iVar2,iVar4,iVar3);
  }
  else {
    FUN_02336940(iVar1 + iVar2,iVar4,iVar3);
  }
  *(undefined1 *)(param_1 + 0x28) = 1;
  return;
}

