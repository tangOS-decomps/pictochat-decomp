// decomp: module=unk_autoload_0 addr=0x0232228c name=FUN_0232228c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc0 (Ghidra's cache says 0xa8 - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=31
// verify:  python tools/match.py --c <file> --func FUN_0232228c --addr 0x0232228c --size 0xc0 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232228c(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 in_r3;
  int iVar4;
  int iVar5;
  
  uVar2 = FUN_02320c7c();
  iVar4 = 0;
  do {
    puVar1 = PTR_DAT_02322334;
    if ((*(int *)(PTR_DAT_02322334 + iVar4 * 0x54 + 0xc) != 0) &&
       (*(int *)(PTR_DAT_02322334 + iVar4 * 0x54 + 8) != 0x18)) {
      iVar5 = *(int *)(PTR_DAT_02322338 + 4) + *(int *)(PTR_DAT_02322334 + iVar4 * 0x54 + 8);
      if (*(int *)(PTR_DAT_02322338 + 8) == 0) {
        iVar3 = 2;
      }
      else {
        iVar3 = FUN_023213e8(PTR_DAT_02322340,(uint)*(ushort *)(PTR_DAT_0232233c + iVar4 * 8 + 4));
      }
      FUN_023210c8(puVar1 + iVar4 * 0x54 + 0x14,0,iVar5,0,0);
      FUN_02320e60(uVar2,PTR_DAT_02322344,PTR_DAT_02322348,
                   *(undefined2 *)(PTR_DAT_0232233c + iVar4 * 8),0,iVar5,iVar3,iVar3,in_r3);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  FUN_02320e14(uVar2,PTR_DAT_02322344,PTR_DAT_02322348,0,0,-*(int *)(PTR_DAT_02322338 + 4));
  FUN_02320e14(uVar2,PTR_DAT_02322344,PTR_DAT_02322348,1,0,*(undefined4 *)(PTR_DAT_02322338 + 4));
  return;
}

