// decomp: module=unk_autoload_0 addr=0x02338cbc name=FUN_02338cbc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb0 (Ghidra's cache says 0xa4 - it excludes this function's trailing literal pool), thumb
// triage: noise=10 statements=58
// verify:  python tools/match.py --c <file> --func FUN_02338cbc --addr 0x02338cbc --size 0xb0 --module unk_autoload_0 --version 2.0/sp1


void FUN_02338cbc(short *param_1)

{
  short sVar1;
  ushort *puVar2;
  int iVar3;
  
  if (param_1 == (short *)0x0) {
    *(undefined2 *)(DAT_02338d60 + 0x34) = 0;
    return;
  }
  FUN_02332080();
  puVar2 = DAT_02338d64;
  iVar3 = DAT_02338d60;
  sVar1 = param_1[2];
  if (sVar1 == 0) {
    *(undefined4 *)(DAT_02338d60 + 0x1c) = 0;
    *(undefined4 *)(iVar3 + 0x20) = 0;
    *(undefined4 *)(iVar3 + 0x24) = 0;
  }
  else {
    *DAT_02338d64 = 0;
    puVar2[8] = 0;
    puVar2[9] = 0x1000;
    *(int *)(puVar2 + 0xc) = (int)sVar1;
    puVar2[0xe] = 0;
    iVar3 = DAT_02338d60;
    puVar2[0xf] = 0;
    *(int *)(DAT_02338d60 + 0x1c) = (int)*param_1;
    *(int *)(iVar3 + 0x20) = (int)param_1[2];
    do {
    } while (((uint)*puVar2 & (uint)puVar2 >> 0xb) != 0);
    *(undefined4 *)(DAT_02338d60 + 0x24) = *DAT_02338d68;
  }
  puVar2 = DAT_02338d64;
  iVar3 = DAT_02338d60;
  sVar1 = param_1[3];
  if (sVar1 == 0) {
    *(undefined4 *)(DAT_02338d60 + 0x28) = 0;
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    *(undefined4 *)(iVar3 + 0x30) = 0;
  }
  else {
    *DAT_02338d64 = 0;
    puVar2[8] = 0;
    puVar2[9] = 0x1000;
    *(int *)(puVar2 + 0xc) = (int)sVar1;
    puVar2[0xe] = 0;
    iVar3 = DAT_02338d60;
    puVar2[0xf] = 0;
    *(int *)(DAT_02338d60 + 0x28) = (int)param_1[1];
    *(int *)(iVar3 + 0x2c) = (int)param_1[3];
    do {
    } while (((uint)*puVar2 & (uint)puVar2 >> 0xb) != 0);
    *(undefined4 *)(DAT_02338d60 + 0x30) = *DAT_02338d68;
  }
  FUN_02332094();
  *(undefined2 *)(DAT_02338d60 + 0x34) = 1;
  return;
}

