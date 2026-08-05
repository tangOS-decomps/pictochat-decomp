// decomp: module=arm7 addr=0x022de298 name=FUN_022de298
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x7c - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=21  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022de298 --addr 0x022de298 --size 0x80 --module arm7 --version 2.0/sp1


bool FUN_022de298(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *DAT_022de314;
  uVar2 = *(ushort *)(iVar3 + 0x3d0) & 0x1fff;
  uVar4 = uVar2 << 3;
  if ((*(ushort *)(param_1 + 0x14) & 0xf) >> 2 == 0) {
    if ((*(short *)(iVar3 + 0x350) == 1) &&
       (uVar1 = (*(ushort *)(param_1 + 0x14) & 0xff) >> 4,
       (uVar1 == 1 || uVar1 == 3) || uVar1 == 0xb)) {
      uVar4 = uVar2;
    }
  }
  else {
    uVar4 = *(ushort *)(iVar3 + 0x3d0) & 0x1fff;
  }
  return uVar4 < (*(int *)(iVar3 + 0x3ec) - (uint)*(ushort *)(param_1 + 4) & 0xffff);
}

