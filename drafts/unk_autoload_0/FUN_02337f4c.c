// decomp: module=unk_autoload_0 addr=0x02337f4c name=FUN_02337f4c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x46 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=22  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02337f4c --addr 0x02337f4c --size 0x54 --module unk_autoload_0 --version 2.0/sp1


uint FUN_02337f4c(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_02337f94;
  if ((DAT_02337f94 <= param_1) && (iVar1 = param_1, 0 < param_1)) {
    iVar1 = 0;
  }
  if (iVar1 < -0xf0) {
    iVar2 = 3;
  }
  else if (iVar1 < -0x78) {
    iVar2 = 2;
  }
  else if (iVar1 < -0x3c) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  return iVar2 << 8 | (uint)*(byte *)(DAT_02337f9c + iVar1 + DAT_02337f98);
}

