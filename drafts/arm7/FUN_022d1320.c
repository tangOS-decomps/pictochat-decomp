// decomp: module=arm7 addr=0x022d1320 name=FUN_022d1320
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c4 (Ghidra's cache says 0x1bc - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=76
// verify:  python tools/match.py --c <file> --func FUN_022d1320 --addr 0x022d1320 --size 0x1c4 --module arm7 --version 2.0/sp1


void FUN_022d1320(void)

{
  short sVar1;
  ushort uVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined1 *a0;
  uint uVar5;
  int iVar6;
  short *psVar7;
  undefined1 auStack_228 [8];
  undefined1 auStack_220 [512];
  
  psVar7 = *(short **)(DAT_022d14dc + 0x550);
  if (*psVar7 == 7) {
    psVar7[0x7b] = 0;
    uVar5 = 1;
    do {
      if (((uint)(ushort)psVar7[0xc1] & 1 << (uVar5 & 0xff)) != 0) {
        func_0x037cb8b4(psVar7 + (uVar5 - 1) * 3 + 0x94,auStack_228);
        for (iVar6 = 0; iVar6 < 2; iVar6 = iVar6 + 1) {
          iVar4 = FUN_022d0008(auStack_220,auStack_228,3);
          sVar1 = *(short *)(iVar4 + 4);
          if ((sVar1 == 0) || (sVar1 != 7 && sVar1 != 0xc)) break;
        }
        func_0x037cb520();
        if (((uint)(ushort)psVar7[0xc1] & 1 << (uVar5 & 0xff)) == 0) {
          func_0x037cb534();
        }
        else {
          uVar2 = ~(ushort)(1 << (uVar5 & 0xff));
          psVar7[0xc1] = psVar7[0xc1] & uVar2;
          psVar7[0x43] = psVar7[0x43] & uVar2;
          (psVar7 + uVar5 * 4 + 0x39c)[0] = 0;
          (psVar7 + uVar5 * 4 + 0x39c)[1] = 0;
          (psVar7 + uVar5 * 4 + 0x39e)[0] = 0;
          (psVar7 + uVar5 * 4 + 0x39e)[1] = 0;
          func_0x037cb534();
          FUN_022d2ad8(1,uVar5 & 0xffff,auStack_228);
        }
      }
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 0x10);
    iVar6 = FUN_022cfda4(auStack_220,1);
    if (*(short *)(iVar6 + 4) == 0) {
      psVar7[0x61] = 0;
      *psVar7 = 3;
      a0 = auStack_220;
      FUN_022d08d4(a0);
      if (*(short *)(a0 + 4) == 0) {
        *psVar7 = 2;
        psVar7[0xcc] = 0;
        psVar7[0xcd] = 0;
        psVar7[0xcb] = 0;
        func_0x037cb820(psVar7 + 0xce,0,0x50);
        FUN_022ce784();
        puVar3 = (undefined2 *)func_0x037d14bc();
        *puVar3 = 9;
        puVar3[1] = 0;
        func_0x037d1464();
      }
      else {
        FUN_022d14e4(DAT_022d14e0);
      }
    }
    else {
      FUN_022d14e4();
    }
  }
  else {
    puVar3 = (undefined2 *)func_0x037d14bc();
    *puVar3 = 9;
    puVar3[1] = 3;
    func_0x037d1464();
  }
  return;
}

