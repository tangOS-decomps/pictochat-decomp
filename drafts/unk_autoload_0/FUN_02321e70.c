// decomp: module=unk_autoload_0 addr=0x02321e70 name=FUN_02321e70
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x104 (Ghidra's cache says 0xe8 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=34
// verify:  python tools/match.py --c <file> --func FUN_02321e70 --addr 0x02321e70 --size 0x104 --module unk_autoload_0 --version 2.0/sp1


void FUN_02321e70(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (-1 < *(int *)(PTR_DAT_02321f58 + 0x14)) {
    if (*(int *)(PTR_DAT_02321f58 + 0x18) == 2) {
      uVar1 = FUN_02320c7c();
      FUN_02320e14(uVar1,PTR_DAT_02321f60,PTR_DAT_02321f5c,4,*(undefined4 *)(PTR_DAT_02321f58 + 0xc)
                   ,*(undefined4 *)PTR_DAT_02321f58);
      if (*(int *)PTR_DAT_02321f58 < 0x4d) {
        FUN_023210c8(PTR_DAT_02321f64,0,*(int *)PTR_DAT_02321f58,0,0);
      }
      if (*(int *)PTR_DAT_02321f58 < 0x4d) {
        FUN_023210c8(PTR_DAT_02321f68,0,*(int *)PTR_DAT_02321f58,0,0);
      }
      iVar2 = FUN_023213e8(PTR_DAT_02321f6c,1);
      uVar1 = FUN_02320c7c();
      FUN_02320e60(uVar1,PTR_DAT_02321f60,PTR_DAT_02321f5c,2,0,*(undefined4 *)PTR_DAT_02321f58,iVar2
                  );
      iVar2 = FUN_023213e8(PTR_DAT_02321f6c,0);
      uVar1 = FUN_02320c7c();
      FUN_02320e60(uVar1,PTR_DAT_02321f60,PTR_DAT_02321f5c,3,0,*(undefined4 *)PTR_DAT_02321f58,iVar2
                  );
    }
    FUN_023210c8(PTR_DAT_02321f70,0,*(int *)PTR_DAT_02321f58 + *(int *)(PTR_DAT_02321f58 + 4),0,0);
    uVar1 = FUN_02320c7c();
    FUN_02320e14(uVar1,PTR_DAT_02321f60,PTR_DAT_02321f5c,1,0,
                 *(int *)PTR_DAT_02321f58 + *(int *)(PTR_DAT_02321f58 + 8));
    uVar1 = FUN_02320c7c();
    FUN_02320e14(uVar1,PTR_DAT_02321f60,PTR_DAT_02321f5c,0,0,
                 *(int *)PTR_DAT_02321f58 + *(int *)(PTR_DAT_02321f58 + 4));
  }
  return;
}

