// decomp: module=unk_autoload_0 addr=0x023374f0 name=FUN_023374f0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x94, arm
// triage: noise=0 statements=50  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023374f0 --addr 0x023374f0 --size 0x94 --module unk_autoload_0 --version 2.0/sp1


void FUN_023374f0(uint *param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  
  if (param_3 == 0) {
    return;
  }
  if (((uint)param_1 & 1) != 0) {
    *(ushort *)((int)param_1 + -1) = *(ushort *)((int)param_1 + -1) & 0xff | (ushort)(param_2 << 8);
    param_1 = (uint *)((int)param_1 + 1);
    param_3 = param_3 - 1;
    if (param_3 == 0) {
      return;
    }
  }
  if (1 < param_3) {
    uVar3 = param_2 | param_2 << 8;
    puVar1 = param_1;
    if (((uint)param_1 & 2) != 0) {
      puVar1 = (uint *)((int)param_1 + 2);
      *(ushort *)param_1 = (ushort)uVar3;
      param_3 = param_3 - 2;
      if (param_3 == 0) {
        return;
      }
    }
    param_2 = uVar3 | uVar3 << 0x10;
    if ((param_3 & 0xfffffffc) != 0) {
      puVar4 = (uint *)((param_3 & 0xfffffffc) + (int)puVar1);
      puVar2 = puVar1;
      do {
        puVar1 = puVar2 + 1;
        *puVar2 = param_2;
        puVar2 = puVar1;
      } while (puVar1 < puVar4);
    }
    param_1 = puVar1;
    if ((param_3 & 2) != 0) {
      param_1 = (uint *)((int)puVar1 + 2);
      *(ushort *)puVar1 = (ushort)uVar3;
    }
  }
  if ((param_3 & 1) == 0) {
    return;
  }
  *(ushort *)param_1 = (ushort)param_2 & 0xff | (ushort)*param_1 & 0xff00;
  return;
}

