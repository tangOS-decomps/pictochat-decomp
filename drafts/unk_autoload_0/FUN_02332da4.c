// decomp: module=unk_autoload_0 addr=0x02332da4 name=FUN_02332da4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50, thumb
// triage: noise=4 statements=26
// verify:  python tools/match.py --c <file> --func FUN_02332da4 --addr 0x02332da4 --size 0x50 --module unk_autoload_0 --version 2.0/sp1


uint FUN_02332da4(int param_1,short *param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_1c [4];
  undefined4 uStack_18;
  
  uVar2 = 0;
  if ((param_1 != 0) && (uStack_18 = param_4, param_2 != (short *)0x0)) {
    while( true ) {
      if (*param_2 == 0) {
        *(undefined1 *)(param_1 + uVar2) = 0;
        return uVar2;
      }
      param_2 = param_2 + 1;
      iVar1 = FUN_02332d94(auStack_1c);
      if (param_3 < uVar2 + iVar1) break;
      FUN_02334598(param_1 + uVar2,auStack_1c,iVar1);
      uVar2 = uVar2 + iVar1;
      if (param_3 < uVar2) {
        return uVar2;
      }
    }
    return uVar2;
  }
  return 0;
}

