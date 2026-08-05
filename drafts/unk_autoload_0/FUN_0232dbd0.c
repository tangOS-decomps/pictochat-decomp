// decomp: module=unk_autoload_0 addr=0x0232dbd0 name=FUN_0232dbd0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7a, thumb
// triage: noise=0 statements=17  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232dbd0 --addr 0x0232dbd0 --size 0x7a --module unk_autoload_0 --version 2.0/sp1


void FUN_0232dbd0(int *param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((((-1 < (int)param_2) && ((int)param_2 < (int)(uint)*(ushort *)(param_1 + 1))) &&
      (-1 < (int)param_3)) && ((int)param_3 < (int)(uint)*(ushort *)((int)param_1 + 6))) {
    iVar3 = *param_1 +
            (((int)param_2 >> 3) * 0x10 +
            ((int)param_3 >> 3) * ((int)((uint)*(ushort *)(param_1 + 1) << 4) >> 3)) * 2;
    iVar2 = (((int)param_2 >> 2 & 1U) + (param_3 & 7) * 2) * 2;
    iVar1 = (param_2 & 3) << 2;
    *(ushort *)(iVar3 + iVar2) =
         (ushort)((param_4 & 0xf) << iVar1) | ~(ushort)(0xf << iVar1) & *(ushort *)(iVar3 + iVar2);
  }
  return;
}

