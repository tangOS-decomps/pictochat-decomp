// decomp: module=unk_autoload_0 addr=0x0232310c name=FUN_0232310c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe8 (Ghidra's cache says 0xde - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=49  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232310c --addr 0x0232310c --size 0xe8 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232310c(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  iVar3 = **(int **)(param_1 + 8);
  iVar6 = 0;
  iVar4 = *(int *)(DAT_023231ec + 8);
  iVar5 = *(int *)(DAT_023231ec + 4);
  do {
    if ((int)(uint)*(ushort *)((int)*(int **)(param_1 + 8) + 0xe) <= iVar6) {
      if (*(int *)(param_1 + 0x34) != 0) {
        for (uVar7 = 0; uVar7 < 2; uVar7 = uVar7 + 1) {
          iVar3 = DAT_023231f0 + uVar7 * 8;
          uVar2 = *(ushort *)(DAT_023231f0 + uVar7 * 8);
          uVar9 = (uint)(uVar2 >> 8);
          if ((((int)(iVar4 + uVar9) <= param_3) &&
              (uVar1 = *(ushort *)(iVar3 + 2), param_3 < (int)(iVar4 + uVar9 + (uVar1 >> 8)))) &&
             ((uVar9 = uVar2 & 0xff, (int)(iVar5 + uVar9) <= param_2 &&
              (param_2 < (int)(iVar5 + uVar9 + (uVar1 & 0xff)))))) {
            return iVar3;
          }
        }
      }
      return 0;
    }
    uVar2 = *(ushort *)(iVar3 + iVar6 * 8);
    uVar7 = (uint)(uVar2 >> 8);
    iVar8 = iVar3 + iVar6 * 8;
    if (((((int)(iVar4 + uVar7) <= param_3) &&
         (param_3 < (int)(iVar4 + uVar7 + (*(ushort *)(iVar8 + 2) >> 8)))) &&
        (uVar7 = uVar2 & 0xff, (int)(iVar5 + uVar7) <= param_2)) &&
       (param_2 < (int)(iVar5 + uVar7 + (*(ushort *)(iVar8 + 2) & 0xff)))) {
      if (*(int *)(param_1 + 0x34) == 0) {
        return iVar8;
      }
      if (*(short *)(iVar8 + 6) != 2) {
        return iVar8;
      }
    }
    iVar6 = iVar6 + 1;
  } while( true );
}

