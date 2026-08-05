// decomp: module=unk_autoload_0 addr=0x0232db60 name=FUN_0232db60
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x70, thumb
// triage: noise=2 statements=28
// verify:  python tools/match.py --c <file> --func FUN_0232db60 --addr 0x0232db60 --size 0x70 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232db60(int param_1,uint param_2)

{
  ushort *puVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  iVar5 = 0;
  if (*(ushort *)(param_1 + 0x1a) != 0) {
    iVar2 = 0;
    puVar3 = *(ushort **)(param_1 + 8);
    puVar1 = puVar3;
    do {
      if ((*puVar1 <= param_2) && (param_2 <= *(ushort *)((int)puVar3 + iVar2 + 2))) {
        return (uVar4 + param_2) - (uint)puVar3[iVar5 * 2];
      }
      iVar5 = iVar5 + 1;
      puVar1 = puVar1 + 2;
      uVar4 = uVar4 + ((uint)*(ushort *)((int)puVar3 + iVar2 + 2) -
                      (uint)*(ushort *)((int)puVar3 + iVar2)) + 1;
      iVar2 = iVar2 + 4;
    } while (iVar5 < (int)(uint)*(ushort *)(param_1 + 0x1a));
  }
  iVar5 = FUN_0232db20(param_2,0,*(ushort *)(param_1 + 0x18) - 1,*(undefined4 *)(param_1 + 4),
                       uVar4 & 0xffff,*(undefined2 *)(param_1 + 0x12));
  return iVar5;
}

