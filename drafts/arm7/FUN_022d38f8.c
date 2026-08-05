// decomp: module=arm7 addr=0x022d38f8 name=FUN_022d38f8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1a8 (Ghidra's cache says 0x19c - it excludes this function's trailing literal pool), arm
// triage: noise=16 statements=80
// verify:  python tools/match.py --c <file> --func FUN_022d38f8 --addr 0x022d38f8 --size 0x1a8 --module arm7 --version 2.0/sp1


void FUN_022d38f8(int param_1)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  ushort uVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *a0;
  short *psVar10;
  undefined1 local_22c [16];
  undefined1 auStack_21c [512];
  
  psVar10 = *(short **)(DAT_022d3a94 + 0x550);
  a0 = auStack_21c;
  if (*psVar10 == 2) {
    iVar8 = FUN_022d0960((int)a0);
    if (*(short *)(iVar8 + 4) == 0) {
      sVar1 = *(short *)(iVar8 + 6);
      psVar10[0x73] = 2;
      if (sVar1 == 0x10) {
        iVar8 = FUN_022ce3e8(10,a0);
        if (iVar8 == 0) {
          return;
        }
        puVar9 = a0;
        FUN_022d08ec(a0);
        if (*(short *)(puVar9 + 4) != 0) {
          FUN_022d3aa0(DAT_022d3a98);
          return;
        }
        *psVar10 = 3;
        iVar8 = FUN_022cfdf8(a0,1,0,1);
        if (*(short *)(iVar8 + 4) != 0) {
          FUN_022d3aa0();
          return;
        }
        psVar10[99] = 1;
      }
      uVar2 = *(undefined2 *)(param_1 + 2);
      uVar3 = *(undefined2 *)(param_1 + 4);
      uVar4 = *(undefined2 *)(param_1 + 6);
      uVar5 = *(undefined2 *)(param_1 + 8);
      func_0x037cb820(local_22c,0,0x10);
      local_22c[0] = (undefined1)uVar4;
      iVar8 = FUN_022d01bc(a0,uVar2,uVar3,uVar5,local_22c);
      if (*(short *)(iVar8 + 4) == 0) {
        uVar6 = *(ushort *)(iVar8 + 8);
        FUN_022d08d4(a0);
        if (*(short *)(a0 + 4) == 0) {
          *psVar10 = 2;
          puVar7 = (undefined2 *)func_0x037d14bc();
          *puVar7 = 0x1e;
          puVar7[1] = 0;
          puVar7[4] = uVar6 & 0xff;
          puVar7[5] = uVar6 >> 8;
          func_0x037d1464();
        }
        else {
          FUN_022d3aa0(DAT_022d3a9c);
        }
      }
      else {
        FUN_022d3aa0(10);
      }
    }
    else {
      FUN_022d3aa0(0x308);
    }
  }
  else {
    puVar7 = (undefined2 *)func_0x037d14bc();
    *puVar7 = 0x1e;
    puVar7[1] = 3;
    func_0x037d1464();
  }
  return;
}

