// decomp: module=unk_autoload_0 addr=0x02322104 name=FUN_02322104
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xac (Ghidra's cache says 0xa0 - it excludes this function's trailing literal pool), thumb
// triage: noise=9 statements=50
// verify:  python tools/match.py --c <file> --func FUN_02322104 --addr 0x02322104 --size 0xac --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02322104(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0xffffffff;
  if ((*(int *)(PTR_DAT_023221a4 + 0x18) == 2) && (*(int *)(PTR_DAT_023221a4 + 0x1c) == 1)) {
    bVar1 = false;
    bVar2 = false;
    FUN_02321328(PTR_DAT_023221a8,PTR_DAT_023221ac);
    iVar3 = FUN_023213c4((undefined4 *)PTR_DAT_023221a8,1);
    if (iVar3 == 0) {
      iVar3 = FUN_023213c4((undefined4 *)PTR_DAT_023221a8,0);
      if (iVar3 != 0) {
        *(undefined4 *)(PTR_DAT_023221a4 + 0x20) = 0;
        bVar2 = true;
      }
    }
    else {
      bVar1 = true;
      *(undefined4 *)(PTR_DAT_023221a4 + 0x20) = 1;
    }
    iVar3 = FUN_023212bc(0x20);
    if (iVar3 == 0) {
      iVar3 = FUN_023212bc(0x10);
      if (iVar3 == 0) {
        iVar3 = FUN_023212bc(1);
        if ((iVar3 != 0) || (bVar1)) {
          uVar4 = *(undefined4 *)(PTR_DAT_023221a4 + 0x20);
        }
        else {
          iVar3 = FUN_023212bc(2);
          if ((iVar3 != 0) || (bVar2)) {
            uVar4 = 0;
          }
        }
      }
      else {
        *(undefined4 *)(PTR_DAT_023221a4 + 0x20) = 1;
        FUN_02320978(0x1d);
      }
    }
    else {
      *(undefined4 *)(PTR_DAT_023221a4 + 0x20) = 0;
      FUN_02320978(0x1d);
    }
  }
  return uVar4;
}

