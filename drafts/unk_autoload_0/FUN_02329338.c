// decomp: module=unk_autoload_0 addr=0x02329338 name=FUN_02329338
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x98 (Ghidra's cache says 0x90 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=32
// verify:  python tools/match.py --c <file> --func FUN_02329338 --addr 0x02329338 --size 0x98 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02329338(int param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = FUN_0232b95c();
  puVar1 = DAT_023293c8;
  if (iVar4 != 0) {
    FUN_0233746c(0,DAT_023293c8,0x4000);
    uVar5 = FUN_02329994();
    FUN_02337584(uVar5,puVar1 + 2,6);
    *puVar1 = 3;
    puVar1[1] = param_1 == 0;
    uVar5 = FUN_02322820();
    FUN_02334628(puVar1 + 8,uVar5,10);
    uVar5 = FUN_02322844();
    FUN_02334628(puVar1 + 0x1c,uVar5,0x1a);
    uVar3 = FUN_02322870();
    *(undefined2 *)(puVar1 + 0x50) = uVar3;
    puVar2 = DAT_023293cc;
    puVar1[0x52] = *DAT_023293cc;
    puVar1[0x53] = puVar2[1];
    FUN_023314e8(puVar1,0x4000);
    iVar4 = FUN_0232b984(puVar1,0x54);
    if (iVar4 != 0) {
      return 1;
    }
  }
  return 0;
}

