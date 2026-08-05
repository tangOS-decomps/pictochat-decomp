// decomp: module=unk_autoload_0 addr=0x02339e00 name=FUN_02339e00
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x46, thumb
// triage: noise=0 statements=27  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02339e00 --addr 0x02339e00 --size 0x46 --module unk_autoload_0 --version 2.0/sp1


int FUN_02339e00(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = 0;
  iVar2 = 0;
  uVar4 = 0;
  do {
    if (9 < (param_1 >> (uVar4 & 0xff) & 0xf)) {
      return 0;
    }
    iVar2 = iVar2 + 1;
    uVar4 = uVar4 + 4;
  } while (iVar2 < 8);
  iVar3 = 0;
  iVar2 = 1;
  uVar4 = 0;
  do {
    iVar3 = iVar3 + 1;
    iVar1 = iVar1 + iVar2 * (param_1 >> (uVar4 & 0xff) & 0xf);
    uVar4 = uVar4 + 4;
    iVar2 = iVar2 * 10;
  } while (iVar3 < 8);
  return iVar1;
}

