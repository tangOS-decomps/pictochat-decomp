// decomp: module=unk_autoload_0 addr=0x02329ed0 name=FUN_02329ed0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb8 (Ghidra's cache says 0xa0 - it excludes this function's trailing literal pool), thumb
// triage: noise=8 statements=30
// verify:  python tools/match.py --c <file> --func FUN_02329ed0 --addr 0x02329ed0 --size 0xb8 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329ed0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  ushort local_18 [4];
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  FUN_023314cc(*(undefined4 *)(DAT_02329f70 + 0x24),0xc0);
  if (*(short *)(*(int *)(DAT_02329f70 + 0x24) + 0x3c) != 0) {
    FUN_02337584(*(int *)(DAT_02329f70 + 0x24) + 0x50,local_18,8);
    FUN_023314e8(local_18,8);
    iVar1 = FUN_0232a028(param_1,local_18);
    if (iVar1 != 0) {
      FUN_0232b410(*(int *)(DAT_02329f70 + 0x30) + (uint)*(byte *)(DAT_02329f70 + 2) * 0x10,4000,
                   param_1 + 10,local_18[0],*(undefined2 *)(param_1 + 0x12),
                   *(undefined4 *)(DAT_02329f70 + 0x24));
      if (*(int *)(DAT_02329f70 + 0x1c) != 0) {
        if (local_18[0] == DAT_02329f74) {
          FUN_02329f90();
        }
        else if ((local_18[0] == DAT_02329f78) && (*(int *)(DAT_02329f70 + 0x14) == 0)) {
          FUN_02331ef0(DAT_02329f7c);
          FUN_02331ea8(DAT_02329f7c,DAT_02329f80,0,DAT_02329f84,0);
          *(undefined4 *)(DAT_02329f70 + 0x14) = 1;
        }
      }
    }
  }
  FUN_02329e4c();
  return;
}

