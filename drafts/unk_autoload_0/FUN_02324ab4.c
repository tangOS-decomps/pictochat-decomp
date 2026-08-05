// decomp: module=unk_autoload_0 addr=0x02324ab4 name=FUN_02324ab4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x52 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=16
// verify:  python tools/match.py --c <file> --func FUN_02324ab4 --addr 0x02324ab4 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


bool FUN_02324ab4(void)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 in_r3;
  
  if (*(int *)(DAT_02324b08 + 0x14) < 0x10) {
    *(int *)(DAT_02324b08 + 0x14) = *(int *)(DAT_02324b08 + 0x14) + 1;
  }
  uVar1 = FUN_02322884(*(int *)(DAT_02324b08 + 0x14));
  uVar2 = FUN_02322894(*(undefined4 *)(DAT_02324b08 + 0x14),0x10);
  FUN_02336428(DAT_02324b0c,0x10,0xf,uVar2,uVar1,in_r3);
  FUN_0232234c();
  FUN_02322004();
  FUN_02325040();
  return *(int *)(DAT_02324b08 + 0x14) == 0x10;
}

