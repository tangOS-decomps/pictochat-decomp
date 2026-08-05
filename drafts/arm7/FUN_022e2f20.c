// decomp: module=arm7 addr=0x022e2f20 name=FUN_022e2f20
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xec (Ghidra's cache says 0xe4 - it excludes this function's trailing literal pool), arm
// triage: noise=10 statements=38
// verify:  python tools/match.py --c <file> --func FUN_022e2f20 --addr 0x022e2f20 --size 0xec --module arm7 --version 2.0/sp1


undefined4 FUN_022e2f20(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint in_r3;
  uint local_8 [2];
  
  local_8[0] = in_r3;
  thunk_EXT_FUN_03801c44(*(undefined4 *)(*DAT_022e3004 + 0x314));
  FUN_022e2df4();
  local_8[0] = 0;
  thunk_EXT_FUN_03802a68(0x2c,2,local_8);
  thunk_EXT_FUN_03801c8c(*(undefined4 *)(*DAT_022e3004 + 0x314));
  if ((local_8[0] < 0xa4) || (DAT_022e3008 < local_8[0])) {
    uVar2 = 0;
  }
  else {
    local_8[0] = local_8[0] + 2;
    uVar2 = func_0x037c58fc(*DAT_022e3004 + 0x188);
    piVar1 = DAT_022e3004;
    *(undefined4 *)(*DAT_022e3004 + 0x318) = uVar2;
    iVar4 = *piVar1;
    iVar3 = *(int *)(iVar4 + 0x318);
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      *(int *)(iVar4 + 0x318) = iVar3 + 0xc;
      thunk_EXT_FUN_03801c44(*(undefined4 *)(*piVar1 + 0x314));
      FUN_022e2df4();
      thunk_EXT_FUN_03802a68(0x2a,local_8[0],*(undefined4 *)(*DAT_022e3004 + 0x318));
      thunk_EXT_FUN_03801c8c(*(undefined4 *)(*DAT_022e3004 + 0x314));
      uVar2 = 1;
    }
  }
  return uVar2;
}

