// decomp: module=unk_autoload_0 addr=0x02327b54 name=FUN_02327b54
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa8 (Ghidra's cache says 0x82 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=21
// verify:  python tools/match.py --c <file> --func FUN_02327b54 --addr 0x02327b54 --size 0xa8 --module unk_autoload_0 --version 2.0/sp1


void FUN_02327b54(void)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_02325654(PTR_DAT_02327bd8);
  FUN_02325774();
  FUN_0232563c(PTR_DAT_02327bd8);
  FUN_02323510(0x16,0x60,0);
  FUN_02323458((int)PTR_FUN_02325b00_1_02327bdc,(int)PTR_DAT_02327bd8);
  uVar1 = FUN_02323d28();
  iVar2 = FUN_02323d3c();
  FUN_02336ce8(uVar1,0,iVar2);
  FUN_02323464(PTR_DAT_02327be0,10,0);
  FUN_02336b0c(PTR_DAT_02327be0,0,0x800);
  FUN_02336d2c(PTR_DAT_02327be4,0,(int)PTR_DAT_02327be8 - (int)PTR_DAT_02327be4);
  uVar1 = FUN_0233665c();
  FUN_0233740c(DAT_02327bec,uVar1,0x800);
  FUN_02336800(PTR_DAT_02327bf0,0,(int)PTR_DAT_02327bf4 - (int)PTR_DAT_02327bf0);
  FUN_02336800(PTR_DAT_02327bf8,0,2);
  return;
}

