// decomp: module=unk_autoload_0 addr=0x0232cd94 name=FUN_0232cd94
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x86 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=30  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232cd94 --addr 0x0232cd94 --size 0x8c --module unk_autoload_0 --version 2.0/sp1


int FUN_0232cd94(int param_1,uint param_2)

{
  short sVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = FUN_0232c4d0();
  iVar3 = FUN_0232c520(5,7,9,8,10,0xb);
  if (iVar3 == 0) {
    sVar1 = **(short **)((int)pvVar2 + 4);
    if ((sVar1 == 7) || (sVar1 == 9)) {
      if ((param_2 == 0) || (0xf < param_2)) {
        return 6;
      }
      FUN_023314cc((int)*(short **)((int)pvVar2 + 4) + DAT_0232ce1c,2);
      if ((1 << (param_2 & 0xff) & (uint)*(ushort *)(*(int *)((int)pvVar2 + 4) + DAT_0232ce1c)) == 0
         ) {
        return 7;
      }
    }
    else if (param_2 != 0) {
      return 6;
    }
    FUN_0232c3bc(0xd,param_1);
    iVar3 = FUN_0232c408(0xd,1,1 << (param_2 & 0xff));
    if (iVar3 == 0) {
      iVar3 = 2;
    }
  }
  return iVar3;
}

