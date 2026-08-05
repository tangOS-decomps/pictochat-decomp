// decomp: module=arm7 addr=0x022d81e8 name=FUN_022d81e8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1f8 (Ghidra's cache says 0x1f0 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=50  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d81e8 --addr 0x022d81e8 --size 0x1f8 --module arm7 --version 2.0/sp1


void FUN_022d81e8(void)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  
  puVar2 = DAT_022d83dc;
  iVar3 = *DAT_022d83d8;
  *(uint *)(iVar3 + 0x58c) = *(int *)(iVar3 + 0x58c) + (*DAT_022d83dc & 0xff);
  uVar1 = puVar2[1];
  *(int *)(iVar3 + 0x588) = *(int *)(iVar3 + 0x588) + ((int)(uint)uVar1 >> 8);
  *(uint *)(iVar3 + 0x598) = *(int *)(iVar3 + 0x598) + (uVar1 & 0xff);
  uVar1 = puVar2[2];
  *(int *)(iVar3 + 0x594) = *(int *)(iVar3 + 0x594) + ((int)(uint)uVar1 >> 8);
  *(uint *)(iVar3 + 0x590) = *(int *)(iVar3 + 0x590) + (uVar1 & 0xff);
  uVar1 = puVar2[3];
  *(int *)(iVar3 + 0x59c) = *(int *)(iVar3 + 0x59c) + ((int)(uint)uVar1 >> 8);
  *(uint *)(iVar3 + 0x574) = *(int *)(iVar3 + 0x574) + (uVar1 & 0xff);
  *(uint *)(iVar3 + 0x584) = *(int *)(iVar3 + 0x584) + (puVar2[4] & 0xff);
  *(uint *)(iVar3 + 0x55c) = *(int *)(iVar3 + 0x55c) + (puVar2[5] & 0xff);
  uVar1 = puVar2[6];
  *(int *)(iVar3 + 0x56c) = *(int *)(iVar3 + 0x56c) + ((int)(uint)uVar1 >> 8);
  *(uint *)(iVar3 + 0x580) = *(int *)(iVar3 + 0x580) + (uVar1 & 0xff);
  uVar1 = puVar2[7];
  *(uint *)(iVar3 + 0x578) = *(int *)(iVar3 + 0x578) + (uVar1 & 0xff);
  *(int *)(iVar3 + 0x57c) = *(int *)(iVar3 + 0x57c) + ((int)(uint)uVar1 >> 8);
  *(uint *)(iVar3 + 0x548) = *(int *)(iVar3 + 0x548) + (puVar2[8] & 0xff);
  *(int *)(iVar3 + 0x5b4) = *(int *)(iVar3 + 0x5b4) + ((int)(uint)puVar2[0x10] >> 8);
  uVar1 = puVar2[0x11];
  *(uint *)(iVar3 + 0x5b8) = *(int *)(iVar3 + 0x5b8) + (uVar1 & 0xff);
  *(int *)(iVar3 + 0x5bc) = *(int *)(iVar3 + 0x5bc) + ((int)(uint)uVar1 >> 8);
  uVar1 = puVar2[0x12];
  *(uint *)(iVar3 + 0x5c0) = *(int *)(iVar3 + 0x5c0) + (uVar1 & 0xff);
  *(int *)(iVar3 + 0x5c4) = *(int *)(iVar3 + 0x5c4) + ((int)(uint)uVar1 >> 8);
  uVar1 = puVar2[0x13];
  *(uint *)(iVar3 + 0x5c8) = *(int *)(iVar3 + 0x5c8) + (uVar1 & 0xff);
  *(int *)(iVar3 + 0x5cc) = *(int *)(iVar3 + 0x5cc) + ((int)(uint)uVar1 >> 8);
  uVar1 = puVar2[0x14];
  *(uint *)(iVar3 + 0x5d0) = *(int *)(iVar3 + 0x5d0) + (uVar1 & 0xff);
  *(int *)(iVar3 + 0x5d4) = *(int *)(iVar3 + 0x5d4) + ((int)(uint)uVar1 >> 8);
  uVar1 = puVar2[0x15];
  *(uint *)(iVar3 + 0x5d8) = *(int *)(iVar3 + 0x5d8) + (uVar1 & 0xff);
  *(int *)(iVar3 + 0x5dc) = *(int *)(iVar3 + 0x5dc) + ((int)(uint)uVar1 >> 8);
  uVar1 = puVar2[0x16];
  *(uint *)(iVar3 + 0x5e0) = *(int *)(iVar3 + 0x5e0) + (uVar1 & 0xff);
  *(int *)(iVar3 + 0x5e4) = *(int *)(iVar3 + 0x5e4) + ((int)(uint)uVar1 >> 8);
  uVar1 = puVar2[0x17];
  *(uint *)(iVar3 + 0x5e8) = *(int *)(iVar3 + 0x5e8) + (uVar1 & 0xff);
  *(int *)(iVar3 + 0x5ec) = *(int *)(iVar3 + 0x5ec) + ((int)(uint)uVar1 >> 8);
  return;
}

