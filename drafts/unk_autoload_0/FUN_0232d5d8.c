// decomp: module=unk_autoload_0 addr=0x0232d5d8 name=FUN_0232d5d8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x72, thumb
// triage: noise=1 statements=21
// verify:  python tools/match.py --c <file> --func FUN_0232d5d8 --addr 0x0232d5d8 --size 0x72 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232d5d8(int param_1)

{
  if (((int)((uint)*(ushort *)(param_1 + 100) << 0x12) < 0) &&
     (5 < (*(ushort *)(param_1 + 100) & 7))) {
    return 0;
  }
  if (((int)((uint)*(ushort *)(param_1 + 100) << 0x15) < 0) &&
     ((0xc < *(byte *)(param_1 + 3) || (0x1f < *(byte *)(param_1 + 4))))) {
    return 0;
  }
  if (((int)((uint)*(ushort *)(param_1 + 100) << 0x10) < 0) && (10 < *(byte *)(param_1 + 0x1a))) {
    return 0;
  }
  if (0x1a < *(byte *)(param_1 + 0x50)) {
    return 0;
  }
  if ((*(byte *)(param_1 + 0x52) < 0x18) && (*(byte *)(param_1 + 0x53) < 0x3c)) {
    return 1;
  }
  return 0;
}

