// decomp: module=unk_autoload_0 addr=0x023380b0 name=FUN_023380b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xea, thumb
// triage: noise=35 statements=68
// verify:  python tools/match.py --c <file> --func FUN_023380b0 --addr 0x023380b0 --size 0xea --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023380b0(int param_1,byte *param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  
  uVar2 = *param_3;
  if (uVar2 < *(uint *)(param_1 + 0x38)) {
    do {
      uVar2 = *(uint *)(param_1 + uVar2 * 4 + 0x3c);
      *param_2 = (byte)uVar2;
      uVar2 = uVar2 >> 8;
      bVar1 = *param_2;
      if (bVar1 < 0x11) {
        if (bVar1 < 0x10) {
          switch(bVar1) {
          case 1:
          case 2:
          case 3:
          case 4:
          case 5:
            iVar3 = param_1 + uVar2;
            *(undefined2 *)(param_2 + 2) = *(undefined2 *)(param_1 + uVar2);
            *(undefined2 *)(param_2 + 4) = *(undefined2 *)(iVar3 + 2);
            *(undefined2 *)(param_2 + 6) = *(undefined2 *)(iVar3 + 4);
            *(undefined2 *)(param_2 + 8) = *(undefined2 *)(iVar3 + 6);
            *(undefined2 *)(param_2 + 10) = *(undefined2 *)(iVar3 + 8);
            *param_3 = *param_3 + 1;
            return 1;
          }
        }
        else {
          pbVar5 = (byte *)(param_1 + uVar2);
          uVar2 = param_3[1];
          if (uVar2 < ((uint)pbVar5[1] - (uint)*pbVar5) + 1) {
            *(undefined2 *)param_2 = *(undefined2 *)(pbVar5 + uVar2 * 0xc + 2);
            *(undefined2 *)(param_2 + 2) = *(undefined2 *)(pbVar5 + uVar2 * 0xc + 4);
            *(undefined2 *)(param_2 + 4) = *(undefined2 *)(pbVar5 + uVar2 * 0xc + 6);
            *(undefined2 *)(param_2 + 6) = *(undefined2 *)(pbVar5 + uVar2 * 0xc + 8);
            *(undefined2 *)(param_2 + 8) = *(undefined2 *)(pbVar5 + uVar2 * 0xc + 10);
            *(undefined2 *)(param_2 + 10) = *(undefined2 *)(pbVar5 + uVar2 * 0xc + 0xc);
            param_3[1] = param_3[1] + 1;
            return 1;
          }
        }
      }
      else if (bVar1 == 0x11) {
        uVar4 = param_3[1];
        if ((uVar4 < 8) && (*(char *)(param_1 + uVar2 + uVar4) != '\0')) {
          iVar3 = param_1 + uVar2 + uVar4 * 0xc;
          *(undefined2 *)param_2 = *(undefined2 *)(iVar3 + 8);
          *(undefined2 *)(param_2 + 2) = *(undefined2 *)(iVar3 + 10);
          *(undefined2 *)(param_2 + 4) = *(undefined2 *)(iVar3 + 0xc);
          *(undefined2 *)(param_2 + 6) = *(undefined2 *)(iVar3 + 0xe);
          *(undefined2 *)(param_2 + 8) = *(undefined2 *)(iVar3 + 0x10);
          *(undefined2 *)(param_2 + 10) = *(undefined2 *)(iVar3 + 0x12);
          param_3[1] = param_3[1] + 1;
          return 1;
        }
      }
      *param_3 = *param_3 + 1;
      param_3[1] = 0;
      uVar2 = *param_3;
    } while (uVar2 < *(uint *)(param_1 + 0x38));
  }
  return 0;
}

