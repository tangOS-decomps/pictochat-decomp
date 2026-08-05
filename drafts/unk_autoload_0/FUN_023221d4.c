// decomp: module=unk_autoload_0 addr=0x023221d4 name=FUN_023221d4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x70 (Ghidra's cache says 0x60 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=37
// verify:  python tools/match.py --c <file> --func FUN_023221d4 --addr 0x023221d4 --size 0x70 --module unk_autoload_0 --version 2.0/sp1


void FUN_023221d4(uint param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    iVar3 = DAT_02322234 + iVar4 * 0x54;
    *(undefined4 *)(iVar3 + 4) = 0xffffffff;
    uVar2 = *(uint *)(DAT_02322238 + iVar4 * 4);
    *(undefined4 *)(iVar3 + 0x10) = 0;
    if ((uVar2 & param_3) == 0) {
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *(undefined4 *)(iVar3 + 8) = 0x18;
    }
    else {
      *(undefined4 *)(iVar3 + 0xc) = 1;
      *(undefined4 *)(iVar3 + 8) = 0;
    }
    puVar1 = DAT_0232223c;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  DAT_0232223c[6] = param_1;
  puVar1[0x1b] = param_2;
  *puVar1 = param_3;
  if ((param_3 & 1) == 0) {
    uVar2 = 0x18;
  }
  else {
    uVar2 = 0;
  }
  puVar1[1] = uVar2;
  DAT_0232223c[2] = 1;
  FUN_0232131c(DAT_02322240);
  return;
}

