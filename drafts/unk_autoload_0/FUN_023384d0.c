// decomp: module=unk_autoload_0 addr=0x023384d0 name=FUN_023384d0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40, thumb
// triage: noise=1 statements=16
// verify:  python tools/match.py --c <file> --func FUN_023384d0 --addr 0x023384d0 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


int FUN_023384d0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0x100) {
    uVar1 = FUN_02332080();
    if ((*(uint *)(param_1 + 0xc) & 8) == 0) {
      do {
        FUN_02330f38(param_1 + 0x18);
      } while ((*(uint *)(param_1 + 0xc) & 8) == 0);
    }
    FUN_02332094(uVar1);
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffff7;
    param_2 = *(int *)(param_1 + 0x14);
  }
  return param_2;
}

