// decomp: module=unk_autoload_0 addr=0x0232df28 name=FUN_0232df28
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18, thumb
// triage: noise=1 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0232df28 --addr 0x0232df28 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232df28(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_0232db60();
  if (uVar1 != *(ushort *)(param_1 + 0x12)) {
    *(short *)(param_1 + 0x12) = (short)uVar1;
    return 1;
  }
  return 0;
}

