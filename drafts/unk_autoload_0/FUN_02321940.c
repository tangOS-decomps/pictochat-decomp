// decomp: module=unk_autoload_0 addr=0x02321940 name=FUN_02321940
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x12c (Ghidra's cache says 0x126 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=36
// verify:  python tools/match.py --c <file> --func FUN_02321940 --addr 0x02321940 --size 0x12c --module unk_autoload_0 --version 2.0/sp1


int FUN_02321940(int param_1,undefined4 *param_2,int param_3,int param_4,int param_5,uint param_6,
                uint param_7,int param_8,int param_9,int param_10,undefined4 param_11,uint param_12)

{
  ushort uVar1;
  int *piVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_28 [16];
  int iStack_18;
  
  iVar5 = ((int)(param_7 + ((uint)((int)param_7 >> 2) >> 0x1d)) >> 3) *
          ((int)(param_6 + ((uint)((int)param_6 >> 2) >> 0x1d)) >> 3);
  iVar4 = (param_8 - (uint)*(ushort *)(param_1 + 0xc)) * 0x80;
  iStack_18 = param_4;
  piVar2 = FUN_02321c58();
  FUN_0232dfa8(param_2,param_3);
  FUN_0233746c(0,*(int *)(param_1 + 0x14) + iVar4,(int)(param_6 * param_7) / 2);
  FUN_0232db10(auStack_28,*(int *)(param_1 + 0x14) + iVar4,param_6 & 0xffff,param_7 & 0xffff,0,
               piVar2);
  puVar3 = FUN_0232dfa8(param_2,param_3);
  uVar1 = (ushort)((uint)DAT_02321a68 >> 0x10);
  if (param_12 == DAT_02321a68 >> 0xc) {
    param_12 = puVar3[3] & 0xff;
  }
  FUN_0232dd40(piVar2 + (uint)(puVar3[3] >> 0xc) * 8,auStack_28,
               *puVar3 & (ushort)DAT_02321a68 |
               uVar1 >> 4 &
               (ushort)((uint)(((((int)(short)*puVar3 << 0x14) >> 0x14) - (param_9 + param_4)) *
                              0x10000) >> 0x10),
               puVar3[1] & (ushort)DAT_02321a68 |
               uVar1 >> 4 &
               (ushort)((uint)(((((int)(short)puVar3[1] << 0x14) >> 0x14) - (param_10 + param_5)) *
                              0x10000) >> 0x10),(int)(char)puVar3[2],
               ((int)(short)puVar3[2] << 0x10) >> 0x18,param_11,param_12);
  return (int)(iVar5 + ((uint)(iVar5 >> 1) >> 0x1e)) >> 2;
}

