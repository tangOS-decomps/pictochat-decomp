// decomp: module=unk_autoload_0 addr=0x0232df14 name=FUN_0232df14
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14, thumb
// triage: noise=0 statements=6  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232df14 --addr 0x0232df14 --size 0x14 --module unk_autoload_0 --version 2.0/sp1


ushort FUN_0232df14(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0232db60();
  return *(ushort *)(*(int *)(param_1 + 0xc) + iVar1 * 2) & 0xff;
}

