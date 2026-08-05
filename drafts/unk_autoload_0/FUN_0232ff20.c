// decomp: module=unk_autoload_0 addr=0x0232ff20 name=FUN_0232ff20
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe4 (Ghidra's cache says 0xda - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=43  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232ff20 --addr 0x0232ff20 --size 0xe4 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ff20(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = DAT_02330000;
  iVar5 = 0;
  iVar4 = DAT_0232fffc;
  do {
    if (*(int *)(iVar4 + 0x118) << 0x1f < 0) {
      if (*(int *)(iVar4 + 0x11c) == 0) {
        FUN_02330034(iVar4);
      }
      else {
        if ((*(int *)(iVar4 + 0x118) << 0x1d < 0) && (*(int *)(iVar4 + 0x120) != 0)) {
          FUN_0232eef0(iVar4);
          *(uint *)(iVar4 + 0x118) = *(uint *)(iVar4 + 0x118) | 2;
          *(uint *)(iVar4 + 0x118) = *(uint *)(iVar4 + 0x118) & 0xfffffffb;
        }
        if (*(int *)(iVar4 + 0x118) << 0x1e < 0) {
          FUN_023305c8((int *)(iVar4 + 0xf0));
          sVar1 = *(short *)(iVar2 + *(int *)(iVar4 + 0x15c) * 2);
          iVar3 = FUN_023305a8(iVar4 + 0xf0);
          iVar3 = (int)*(short *)(iVar2 + *(int *)(iVar4 + 0x160) * 2) +
                  (int)*(short *)(iVar2 + (iVar3 >> 8) * 2) + (int)sVar1;
          if (iVar3 != *(int *)(iVar4 + 0x164)) {
            FUN_0232ef38(iVar4,iVar3);
            *(int *)(iVar4 + 0x164) = iVar3;
          }
          if ((*(int *)(iVar4 + 0x118) << 0x1c < 0) &&
             (iVar3 = FUN_023305d8((int *)(iVar4 + 0xf0)), iVar3 != 0)) {
            FUN_02330034(iVar4);
          }
        }
      }
    }
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x17c;
  } while (iVar5 < 4);
  return;
}

