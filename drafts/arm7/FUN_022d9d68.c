// decomp: module=arm7 addr=0x022d9d68 name=FUN_022d9d68
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=15  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d9d68 --addr 0x022d9d68 --size 0x5c --module arm7 --version 2.0/sp1


void FUN_022d9d68(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *DAT_022d9db8;
  *(ushort *)(iVar1 + 0x52e) =
       *(ushort *)(iVar1 + 0x52e) & ~(ushort)(1 << (param_1 & 0xff)) |
       (ushort)(param_2 << (param_1 & 0xff));
  if ((*(ushort *)(iVar1 + 0x52e) & ~*(ushort *)(iVar1 + 0x532)) == 0) {
    *DAT_022d9dc0 = 8;
  }
  else {
    *DAT_022d9dbc = 8;
  }
  return;
}

