// decomp: module=arm7 addr=0x022dbb30 name=FUN_022dbb30
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=11
// verify:  python tools/match.py --c <file> --func FUN_022dbb30 --addr 0x022dbb30 --size 0x54 --module arm7 --version 2.0/sp1


void FUN_022dbb30(void)

{
  int iVar1;
  
  iVar1 = *DAT_022dbb80;
  *(ushort *)(iVar1 + 0x428) = *(ushort *)(iVar1 + 0x428) & 0xfffe;
  func_0x037c5de8(iVar1 + 0x200,*(undefined4 *)(iVar1 + 0x424));
  if (*(short *)(iVar1 + 0x208) != 0) {
    func_0x037c5628(2,0xb);
  }
  return;
}

