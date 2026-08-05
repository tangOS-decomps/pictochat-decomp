// decomp: module=unk_autoload_0 addr=0x02336234 name=FUN_02336234
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xdc (Ghidra's cache says 0xb4 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=49
// verify:  python tools/match.py --c <file> --func FUN_02336234 --addr 0x02336234 --size 0xdc --module unk_autoload_0 --version 2.0/sp1


void FUN_02336234(void)

{
  short sVar1;
  undefined2 *puVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  undefined4 in_r3;
  
  puVar3 = DAT_023362e8;
  *DAT_023362e8 = (ushort)((uint)DAT_023362e8 >> 0xb) | *DAT_023362e8;
  *puVar3 = (ushort)DAT_023362f0 | *puVar3 & (ushort)DAT_023362ec;
  *puVar3 = *puVar3 | 1;
  FUN_023371a4();
  iVar4 = DAT_023362f4;
  sVar1 = *(short *)(DAT_023362f4 + 2);
  puVar2 = DAT_023362f8;
  while (DAT_023362f8 = puVar2, sVar1 == 0) {
    iVar5 = FUN_02330aa4();
    if (iVar5 == -3) {
      FUN_02332274();
    }
    *(short *)(iVar4 + 2) = (short)iVar5;
    puVar2 = DAT_023362f8;
    sVar1 = *(short *)(iVar4 + 2);
  }
  *puVar2 = 0;
  *(undefined4 *)(puVar2 + -2) = 0;
  if (*(int *)(DAT_023362fc + 4) == -1) {
    FUN_02337440(0,puVar2 + 2,0x60);
    *DAT_02336300 = 0;
    FUN_02337440(0,DAT_02336304,0x70);
  }
  else {
    FUN_023371e4(*(int *)(DAT_023362fc + 4),puVar2 + 2,0,0x60,1,in_r3);
    *DAT_02336300 = 0;
    FUN_023371e4(*(undefined4 *)(DAT_023362fc + 4),DAT_02336304,0,0x70,1);
  }
  puVar2 = DAT_02336308;
  *DAT_02336308 = 0x100;
  puVar2[3] = 0x100;
  puVar2[8] = 0x100;
  puVar2[0xb] = 0x100;
  puVar2 = DAT_0233630c;
  *DAT_0233630c = 0x100;
  puVar2[3] = 0x100;
  puVar2[8] = 0x100;
  puVar2[0xb] = 0x100;
  return;
}

