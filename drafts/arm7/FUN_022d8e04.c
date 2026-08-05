// decomp: module=arm7 addr=0x022d8e04 name=FUN_022d8e04
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x78 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=9  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d8e04 --addr 0x022d8e04 --size 0x80 --module arm7 --version 2.0/sp1


uint FUN_022d8e04(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*(ushort *)(DAT_022d8e7c + (param_2 & 0xf) * 2) ^
          DAT_022d8e80 & (int)param_2 >> 4 & 0xffff ^
          (uint)*(ushort *)(DAT_022d8e7c + (param_1 & 0xf) * 2);
  return (uint)*(ushort *)(DAT_022d8e7c + (uVar1 & 0xf) * 2) ^ DAT_022d8e80 & (int)uVar1 >> 4 ^
         (uint)*(ushort *)(DAT_022d8e7c + ((int)param_1 >> 4 & 0xfU) * 2);
}

