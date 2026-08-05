// decomp: module=unk_autoload_0 addr=0x0232bf8c name=FUN_0232bf8c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x10c (Ghidra's cache says 0xf8 - it excludes this function's trailing literal pool), thumb
// triage: noise=21 statements=58
// verify:  python tools/match.py --c <file> --func FUN_0232bf8c --addr 0x0232bf8c --size 0x10c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232bf8c(int param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  undefined1 auStack_14 [8];
  undefined4 local_c;
  
  iVar1 = DAT_0232c084;
  if (*(short *)(param_1 + 10) == 0xe) {
    if (*(int *)(DAT_0232c084 + 0x24) == 0) {
      if (((*(int *)(DAT_0232c084 + 0x28) == *(int *)(DAT_0232c084 + 0x1c)) &&
          (*(int *)(DAT_0232c084 + 0x28) != 0)) &&
         ((uVar2 = FUN_0232a4e8(), uVar2 == 0 && (*(int *)(DAT_0232c084 + 0x14) == 2)))) {
        if (*(code **)(DAT_0232c084 + 0x3c) != (code *)0x0) {
          (**(code **)(DAT_0232c084 + 0x3c))(0,*DAT_0232c094,*(undefined4 *)(DAT_0232c084 + 0x28));
        }
        if (*(int *)(DAT_0232c084 + 0x2c) == 0) {
          *(undefined4 *)(DAT_0232c084 + 0x38) = 0;
        }
        else {
          *(undefined4 *)(DAT_0232c084 + 0x38) = 3;
        }
        iVar1 = DAT_0232c084;
        *(undefined4 *)(DAT_0232c084 + 0x14) = 0;
        *(undefined4 *)(iVar1 + 0x28) = 0;
        *(undefined4 *)(iVar1 + 0x1c) = 0;
        *(undefined4 *)(iVar1 + 0x20) = 0xffffffff;
        FUN_0232bd8c();
        return;
      }
      uVar2 = FUN_0232a4e8();
      if (uVar2 == 0) {
        FUN_02337584(*(undefined4 *)(param_1 + 0x14),auStack_14,0xc);
        *(undefined4 *)(DAT_0232c084 + 0x20) = local_c;
      }
      FUN_0232becc();
      return;
    }
    *(undefined4 *)(DAT_0232c084 + 0x24) = 0;
    iVar3 = FUN_0232b834(DAT_0232c088);
    iVar1 = DAT_0232c084;
    if (iVar3 == 0) {
      *(undefined4 *)(DAT_0232c084 + 0x24) = 1;
      FUN_0232b7ec(DAT_0232c088,*(undefined4 *)(iVar1 + 0x10),0xac);
      FUN_02337584(*(undefined4 *)(DAT_0232c084 + 0x10),auStack_14,0xc);
      FUN_0232c100(0xe,*(undefined4 *)(DAT_0232c084 + 0x10),0xac,DAT_0232c090,DAT_0232c08c);
      return;
    }
  }
  else if ((((*(short *)(param_1 + 10) == 0xd) &&
            (*(int *)(param_1 + 0x14) == *(int *)(DAT_0232c084 + 0xc))) &&
           (*(undefined4 *)(DAT_0232c084 + 0x2c) = 0, *(int *)(iVar1 + 0x38) == 3)) &&
          (uVar2 = FUN_0232a4e8(), uVar2 == 0)) {
    *(undefined4 *)(DAT_0232c084 + 0x38) = 0;
    FUN_0232bd8c();
  }
  return;
}

