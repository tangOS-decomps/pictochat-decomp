// decomp: module=unk_autoload_0 addr=0x023279bc name=FUN_023279bc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x198 (Ghidra's cache says 0x132 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=50
// verify:  python tools/match.py --c <file> --func FUN_023279bc --addr 0x023279bc --size 0x198 --module unk_autoload_0 --version 2.0/sp1


void FUN_023279bc(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  FUN_0233746c(0,DAT_02327af0,0x20);
  FUN_023234c0();
  *(undefined4 *)(DAT_02327af4 + 0x20) = 0xffffffff;
  FUN_0232517c(DAT_02327af8);
  FUN_02336880(DAT_02327afc,0,DAT_02327b00 - DAT_02327afc);
  FUN_02336880(DAT_02327b04,0x40,0x20);
  FUN_02322870();
  FUN_02328da8();
  FUN_02336800(DAT_02327b08,0,DAT_02327b0c - DAT_02327b08);
  FUN_02336800(DAT_02327b10,0,2);
  FUN_02336800(DAT_02327b14,0x140,0x16);
  iVar1 = FUN_02322870();
  FUN_02336800(DAT_02327b18 + iVar1 * 0x10 + 6,DAT_02327b1c,10);
  *DAT_02327b20 = *DAT_02327b20 & 0x43 | 4;
  FUN_023369fc(DAT_02327b24,0,DAT_02327b28 - DAT_02327b24);
  *DAT_02327b2c = 0;
  FUN_02320c7c();
  FUN_02320ac8();
  uVar2 = FUN_02320c7c();
  FUN_02320afc(uVar2,DAT_02327b30);
  uVar2 = FUN_02320c7c();
  FUN_02320afc(uVar2,DAT_02327b34);
  pvVar3 = FUN_023215e4();
  iVar1 = FUN_02320c7c();
  FUN_02321600(pvVar3,*(undefined4 *)(iVar1 + DAT_02327b38));
  pvVar3 = FUN_023215e4();
  FUN_02321664(pvVar3,DAT_02327b3c,DAT_02327b40,0);
  uVar2 = FUN_02322820();
  FUN_023216e0(DAT_02327b3c,uVar2);
  pvVar3 = FUN_023215e4();
  FUN_02321634(pvVar3,DAT_02327b44,DAT_02327b40,3);
  iVar1 = FUN_02321d04(0x1b);
  FUN_023216e0(DAT_02327b44,iVar1);
  pvVar3 = FUN_023215e4();
  FUN_02321634(pvVar3,DAT_02327b48,DAT_02327b40,3);
  pvVar3 = FUN_023215e4();
  FUN_02321664(pvVar3,DAT_02327b4c,DAT_02327b40,5);
  FUN_023274b4();
  FUN_0232575c();
  FUN_0232571c(DAT_02327b50);
  FUN_02321df4();
  FUN_023215e4();
  FUN_02321e24();
  return;
}

