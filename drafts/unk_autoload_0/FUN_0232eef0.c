// decomp: module=unk_autoload_0 addr=0x0232eef0 name=FUN_0232eef0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x36, thumb
// triage: noise=1 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0232eef0 --addr 0x0232eef0 --size 0x36 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232eef0(int param_1)

{
  FUN_02337768(*(undefined4 *)(param_1 + 0x4c),0,1 << (*(uint *)(param_1 + 0x48) & 0xff),0);
  if (-1 < *(int *)(param_1 + 0x2c) << 0x1e) {
    FUN_0233984c(param_1 + 8);
    FUN_02339864(param_1 + 0x18);
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 2;
  }
  return;
}

