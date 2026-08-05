// decomp: module=unk_autoload_0 addr=0x0232bb9c name=FUN_0232bb9c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe8 (Ghidra's cache says 0xd8 - it excludes this function's trailing literal pool), thumb
// triage: noise=15 statements=62
// verify:  python tools/match.py --c <file> --func FUN_0232bb9c --addr 0x0232bb9c --size 0xe8 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232bb9c(int param_1)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  undefined1 auStack_14 [4];
  byte local_10;
  undefined1 local_e;
  char local_d;
  int local_c;
  
  if (*(short *)(param_1 + 0x10) != 0) {
    FUN_02337584(*(undefined4 *)(param_1 + 0xc),auStack_14,0xc);
    FUN_02337584(*(int *)(param_1 + 0xc) + 0xc,*(int *)(DAT_0232bc74 + 0x18) + local_c,local_e);
    uVar2 = FUN_0232a4e8();
    puVar1 = DAT_0232bc74;
    if (uVar2 == 0) {
      if (*(int *)(DAT_0232bc74 + 0x10) != local_c) {
        *(int *)(DAT_0232bc74 + 0x10) = local_c;
        if (*(int *)(puVar1 + 0x12) == 0) {
          puVar1[0x12] = 1;
          puVar1[0x13] = 0;
          FUN_02337584(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(puVar1 + 8),
                       *(undefined2 *)(param_1 + 0x10));
          FUN_0232c100(0xe,*(undefined4 *)(DAT_0232bc74 + 8),*(undefined2 *)(param_1 + 0x10),
                       DAT_0232bc7c,DAT_0232bc78);
          return;
        }
        iVar3 = FUN_0232b794(DAT_0232bc80,*(undefined4 *)(param_1 + 0xc),
                             *(undefined2 *)(param_1 + 0x10));
        if (iVar3 == 0) {
          FUN_0232a480();
          FUN_02329bd8(0xc);
          return;
        }
      }
    }
    else {
      *(int *)(DAT_0232bc74 + 0x10) = local_c;
      if ((local_d == '\x01') && (*puVar1 != DAT_0232bc7c)) {
        uVar2 = FUN_0232a4e8();
        if (local_10 == uVar2) {
          if (*(int *)(DAT_0232bc74 + 10) == 2) {
            puVar1 = DAT_0232bc74;
            puVar1[10] = 0;
            puVar1[0xb] = 0;
          }
          FUN_0232be80(1);
        }
        if (*(code **)(DAT_0232bc74 + 0x1e) != (code *)0x0) {
          (**(code **)(DAT_0232bc74 + 0x1e))
                    (*DAT_0232bc74,*(undefined4 *)(DAT_0232bc74 + 0x18),
                     *(undefined4 *)(DAT_0232bc74 + 0xc));
        }
        puVar1 = DAT_0232bc74;
        *DAT_0232bc74 = (ushort)DAT_0232bc7c;
        puVar1[0x10] = 0xffff;
        puVar1[0x11] = 0xffff;
      }
    }
  }
  return;
}

