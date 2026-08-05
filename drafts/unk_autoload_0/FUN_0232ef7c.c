// decomp: module=unk_autoload_0 addr=0x0232ef7c name=FUN_0232ef7c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4e, thumb
// triage: noise=5 statements=16
// verify:  python tools/match.py --c <file> --func FUN_0232ef7c --addr 0x0232ef7c --size 0x4e --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ef7c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x2c) << 0x1e < 0) {
    FUN_02337784(*(undefined4 *)(param_1 + 0x4c),0,1 << (*(uint *)(param_1 + 0x48) & 0xff),0,param_4
                );
    FUN_02339890(param_1 + 8);
    FUN_023398a0(param_1 + 0x18);
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffffffd;
    uVar1 = FUN_02337cac();
    FUN_02337b54(1);
    FUN_02337c68(uVar1);
  }
  FUN_0232efcc(param_1);
  return;
}

