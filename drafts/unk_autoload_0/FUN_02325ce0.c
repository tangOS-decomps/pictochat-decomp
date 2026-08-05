// decomp: module=unk_autoload_0 addr=0x02325ce0 name=FUN_02325ce0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48 (Ghidra's cache says 0x44 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=23
// verify:  python tools/match.py --c <file> --func FUN_02325ce0 --addr 0x02325ce0 --size 0x48 --module unk_autoload_0 --version 2.0/sp1


void FUN_02325ce0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if ((int)((uint)*(ushort *)(param_1 + 0x48) << 0x17) < 0) {
    uVar2 = FUN_023212f8();
    uVar3 = FUN_02321304();
    iVar4 = FUN_02325c4c(uVar2,uVar3);
    iVar1 = DAT_02325d24;
    if (iVar4 == 0) {
      if ((*(ushort *)(param_1 + DAT_02325d24) < 0x3c) &&
         (*(ushort *)(param_1 + DAT_02325d24) = *(ushort *)(param_1 + DAT_02325d24) + 1,
         *(short *)(param_1 + iVar1) == 0x3c)) {
        FUN_02321198();
      }
      return;
    }
  }
  *(undefined2 *)(param_1 + DAT_02325d24) = 0;
  return;
}

