// decomp: module=unk_autoload_0 addr=0x023243a0 name=FUN_023243a0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44, thumb
// triage: noise=1 statements=22
// verify:  python tools/match.py --c <file> --func FUN_023243a0 --addr 0x023243a0 --size 0x44 --module unk_autoload_0 --version 2.0/sp1


uint FUN_023243a0(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    if (1 < iVar3) {
      return param_2;
    }
    iVar1 = FUN_023346a8(*(undefined4 *)(param_1 + iVar3 * 4),param_2);
    if (iVar1 != 0) break;
    iVar3 = iVar3 + 1;
  }
  uVar2 = (uint)*(ushort *)
                 (*(int *)(param_1 + (1 - iVar3) * 4) +
                 ((iVar1 - *(int *)(param_1 + iVar3 * 4)) / 2) * 2);
  if (uVar2 != 0x3000) {
    return uVar2;
  }
  return param_2;
}

