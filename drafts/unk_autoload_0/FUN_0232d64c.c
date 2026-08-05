// decomp: module=unk_autoload_0 addr=0x0232d64c name=FUN_0232d64c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xac (Ghidra's cache says 0xa2 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=42
// verify:  python tools/match.py --c <file> --func FUN_0232d64c --addr 0x0232d64c --size 0xac --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232d64c(int param_1)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  uVar4 = 0;
  do {
    iVar3 = uVar4 * 0x80;
    uVar2 = FUN_02332d3a(DAT_0232d6f0,param_1 + iVar3,0x70);
    if ((((uVar2 == *(ushort *)(param_1 + iVar3 + 0x72)) &&
         (*(ushort *)(param_1 + iVar3 + 0x70) < 0x80)) && (*(char *)(param_1 + iVar3) == '\x05')) &&
       (iVar3 = FUN_0232d5d8(param_1 + iVar3), iVar3 != 0)) {
      uVar5 = 1 << (uVar4 & 0xff) & 0xffffU | uVar5;
    }
    puVar1 = DAT_0232d6f4;
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 2);
  if (uVar5 == 3) {
    if ((*(short *)(param_1 + 0x70) + 1U & 0x7f) == *(ushort *)(param_1 + 0xf0)) {
      *DAT_0232d6f4 = 1;
    }
    else {
      *DAT_0232d6f4 = 0;
    }
  }
  else {
    if (uVar5 == 0) {
      return 1;
    }
    *DAT_0232d6f4 = 0;
    do {
      if ((1 << (*puVar1 & 0xff) & uVar5) != 0) {
        return 0;
      }
      *puVar1 = *puVar1 + 1;
    } while (*puVar1 < 2);
  }
  return 0;
}

