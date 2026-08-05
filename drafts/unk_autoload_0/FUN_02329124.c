// decomp: module=unk_autoload_0 addr=0x02329124 name=FUN_02329124
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20, thumb
// triage: noise=1 statements=12
// verify:  python tools/match.py --c <file> --func FUN_02329124 --addr 0x02329124 --size 0x20 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02329124(void)

{
  int iVar1;
  
  iVar1 = FUN_0232996c();
  if ((iVar1 != 0xc) && (iVar1 != 0xd)) {
    if (iVar1 != 0xe) {
      return 0;
    }
    return 2;
  }
  return 1;
}

