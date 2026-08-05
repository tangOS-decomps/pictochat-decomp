// decomp: module=unk_autoload_0 addr=0x0232529c name=FUN_0232529c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x6c, thumb
// triage: noise=0 statements=18  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232529c --addr 0x0232529c --size 0x6c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232529c(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (((((param_3 + -0x10 < 0) || (0xf < param_3 + -0x10)) || ((int)param_2 < 0x18)) ||
      (iVar1 = FUN_02327990(), iVar1 + 0x18 <= (int)param_2)) &&
     (((uVar3 = param_3 - 0x10, -1 < (int)uVar3 && ((int)uVar3 < 0x50)) &&
      ((0x17 < (int)param_2 && ((int)param_2 < 0xfc)))))) {
    param_1 = param_1 + (((int)param_2 >> 3) * 0x10 + ((int)uVar3 >> 3) * 0x200) * 2;
    iVar2 = (((int)param_2 >> 2 & 1U) + (uVar3 & 7) * 2) * 2;
    iVar1 = (param_2 & 3) << 2;
    *(ushort *)(param_1 + iVar2) =
         ~(ushort)(0xf << iVar1) & *(ushort *)(param_1 + iVar2) | (ushort)((param_4 & 0xf) << iVar1)
    ;
  }
  return;
}

