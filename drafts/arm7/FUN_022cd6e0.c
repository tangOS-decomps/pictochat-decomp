// decomp: module=arm7 addr=0x022cd6e0 name=FUN_022cd6e0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xce, thumb
// triage: noise=3 statements=32
// verify:  python tools/match.py --c <file> --func FUN_022cd6e0 --addr 0x022cd6e0 --size 0xce --module arm7 --version 2.0/sp1


/* WARNING: Removing unreachable block (ram,0x022cd750) */
/* WARNING: Removing unreachable block (ram,0x022cd784) */

void FUN_022cd6e0(uint param_1)

{
  ushort local_10 [2];
  undefined1 auStack_c [4];
  
  if ((param_1 & 1) == 1) {
    thunk_EXT_FUN_037fefe0(0x8000);
    FUN_022cdca8(0x86,0,local_10,1);
    if ((local_10[0] & 3) >> 1 != 1) {
      local_10[0] = local_10[0] & 0xfffd | 2;
      thunk_EXT_FUN_037fefe0(0x8000);
      thunk_EXT_FUN_02300fa0();
      thunk_EXT_FUN_02301014(6,0);
      thunk_EXT_FUN_02301084(local_10,1);
      thunk_EXT_FUN_02300fe0();
      FUN_022cdca8(0x86,0x10,auStack_c,3);
      FUN_022cdbfc(auStack_c);
      thunk_EXT_FUN_02300fa0();
      thunk_EXT_FUN_02301014(6,0x10);
      thunk_EXT_FUN_02301084(auStack_c,3);
      thunk_EXT_FUN_02300fe0();
      FUN_022cdca8(0x86,0x50,auStack_c,3);
      FUN_022cdbfc(auStack_c);
      thunk_EXT_FUN_02300fa0();
      thunk_EXT_FUN_02301014(6,0x50);
      thunk_EXT_FUN_02301084(auStack_c,3);
      thunk_EXT_FUN_02300fe0();
    }
  }
  return;
}

