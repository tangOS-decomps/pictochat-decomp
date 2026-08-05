// decomp: module=unk_autoload_0 addr=0x02322e4c name=FUN_02322e4c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48, thumb
// triage: noise=0 statements=27  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02322e4c --addr 0x02322e4c --size 0x48 --module unk_autoload_0 --version 2.0/sp1


uint FUN_02322e4c(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = 0;
  if ((*(byte *)(param_1 + 1) == 0) || (0x30 < *(byte *)(param_1 + 1))) {
    return 0;
  }
  do {
    iVar2 = param_1 + uVar1;
    uVar1 = uVar1 + 1 & 0xff;
    if (*(char *)(iVar2 + 6) == '\x1b') break;
  } while (uVar1 < 0x11);
  uVar3 = 0;
  while( true ) {
    if (uVar1 <= uVar3) {
      if (0x10 < uVar1) {
        uVar1 = 0;
      }
      return uVar1;
    }
    if (0x1c < *(byte *)(param_1 + uVar3 + 6)) break;
    uVar3 = uVar3 + 1 & 0xff;
  }
  return 0;
}

