// decomp: module=unk_autoload_0 addr=0x02329e9c name=FUN_02329e9c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x30 - it excludes this function's trailing literal pool), thumb
// triage: noise=11 statements=15
// verify:  python tools/match.py --c <file> --func FUN_02329e9c --addr 0x02329e9c --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329e9c(void)

{
  int iVar1;
  
  iVar1 = DAT_02329ecc;
  **(undefined4 **)(DAT_02329ecc + 0x18) = *(undefined4 *)(DAT_02329ecc + 0x24);
  *(undefined2 *)(*(int *)(iVar1 + 0x18) + 4) = *(undefined2 *)(iVar1 + 4);
  *(undefined2 *)(*(int *)(iVar1 + 0x18) + 6) = 0x14;
  *(undefined1 *)(*(int *)(iVar1 + 0x18) + 8) = 0xff;
  *(undefined1 *)(*(int *)(iVar1 + 0x18) + 9) = 0xff;
  *(undefined1 *)(*(int *)(iVar1 + 0x18) + 10) = 0xff;
  *(undefined1 *)(*(int *)(iVar1 + 0x18) + 0xb) = 0xff;
  *(undefined1 *)(*(int *)(iVar1 + 0x18) + 0xc) = 0xff;
  *(undefined1 *)(*(int *)(iVar1 + 0x18) + 0xd) = 0xff;
  return;
}

