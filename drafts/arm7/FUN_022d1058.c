// decomp: module=arm7 addr=0x022d1058 name=FUN_022d1058
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28c (Ghidra's cache says 0x284 - it excludes this function's trailing literal pool), arm
// triage: noise=16 statements=101
// verify:  python tools/match.py --c <file> --func FUN_022d1058 --addr 0x022d1058 --size 0x28c --module arm7 --version 2.0/sp1


void FUN_022d1058(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  short sVar4;
  int extraout_r1;
  short *psVar5;
  int iVar6;
  bool bVar7;
  undefined2 local_2b0;
  undefined2 local_2ae;
  short local_2ac;
  undefined2 local_2aa;
  undefined1 auStack_290 [128];
  undefined1 auStack_210 [512];
  
  psVar5 = *(short **)(DAT_022d12dc + 0x550);
  if ((*psVar5 == 2) && ((*(uint *)(psVar5 + 100) & 1) == 0)) {
    iVar6 = *(int *)(param_1 + 4);
    if (((uint)(ushort)psVar5[0xfb] & (1 << ((ushort)psVar5[0x8d] & 0xff)) >> 1) == 0) {
      puVar1 = (undefined2 *)func_0x037d14bc();
      *puVar1 = 8;
      puVar1[1] = 6;
      puVar1[4] = 0;
      func_0x037d1464();
    }
    else {
      psVar5[0x73] = 1;
      psVar5[0xc4] = 0;
      func_0x037cb520();
      psVar5[0xc1] = 0;
      psVar5[0x43] = 0;
      func_0x037cb534();
      psVar5[0xf7] = 1;
      iVar2 = FUN_022ce3e8(8,auStack_210);
      if (iVar2 != 0) {
        puVar3 = auStack_210;
        FUN_022d08ec(auStack_210);
        if (*(short *)(puVar3 + 4) == 0) {
          bVar7 = iVar6 != 0;
          iVar6 = FUN_022cfdf8(auStack_210,bVar7,0,1);
          if (*(short *)(iVar6 + 4) == 0) {
            psVar5[99] = (ushort)bVar7;
            func_0x037cb774(0,auStack_290,0x80);
            FUN_022ce324(auStack_290,psVar5 + 0x74);
            func_0x037cb774(0,&local_2b0,0x20);
            local_2b0 = (undefined2)*(undefined4 *)(psVar5 + 0x78);
            local_2ae = (undefined2)((uint)*(undefined4 *)(psVar5 + 0x78) >> 0x10);
            local_2ac = psVar5[0x7a];
            local_2aa = 0;
            iVar6 = FUN_022d00fc(auStack_210,0x20,&local_2b0,psVar5[0x80],2,psVar5[0x8d],3,3,
                                 psVar5[0x76] + 0x10,auStack_290);
            if (*(short *)(iVar6 + 4) == 0) {
              if (psVar5[0x7e] == 0) {
                sVar4 = 0;
              }
              else {
                sVar4 = 0x2a;
              }
              FUN_022ce7b8(psVar5[0x8e] + sVar4);
              iVar6 = extraout_r1;
              if (psVar5[0x7e] != 0) {
                iVar6 = 6;
              }
              if (psVar5[0x7e] == 0) {
                iVar6 = 0;
              }
              FUN_022ce808((uint)(ushort)psVar5[0x8f] + iVar6 & 0xffff);
              puVar1 = (undefined2 *)func_0x037d14bc();
              *psVar5 = 7;
              *puVar1 = 8;
              puVar1[1] = 0;
              puVar1[4] = 0;
              puVar1[0x16] = psVar5[0x18];
              puVar1[0x17] = psVar5[0x19];
              func_0x037d1464();
              psVar5[0x61] = 1;
            }
            else {
              FUN_022d12e4(9);
            }
          }
          else {
            FUN_022d12e4(1);
          }
        }
        else {
          FUN_022d12e4(DAT_022d12e0);
        }
      }
    }
  }
  else {
    puVar1 = (undefined2 *)func_0x037d14bc();
    *puVar1 = 8;
    puVar1[1] = 3;
    puVar1[4] = 0;
    func_0x037d1464();
  }
  return;
}

