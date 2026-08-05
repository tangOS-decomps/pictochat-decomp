// decomp: module=unk_autoload_0 addr=0x02320b9c name=FUN_02320b9c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x72 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=22
// verify:  python tools/match.py --c <file> --func FUN_02320b9c --addr 0x02320b9c --size 0x8c --module unk_autoload_0 --version 2.0/sp1


void FUN_02320b9c(void)

{
  undefined4 in_r3;
  int iVar1;
  int iVar2;
  
  iVar1 = *DAT_02320c10;
  FUN_0233746c(0xc0,DAT_02320c14 + iVar1 * 8,(0x80 - iVar1) * 8,iVar1,in_r3);
  FUN_0233746c(0xc0,DAT_02320c1c + *(int *)(DAT_02320c18 + 0x30) * 8,
               (0x80 - *(int *)(DAT_02320c18 + 0x30)) * 8);
  iVar1 = DAT_02320c14;
  iVar2 = 0;
  do {
    FUN_02320c28((undefined4 *)(iVar1 + iVar2 * 0x20),(int *)(DAT_02320c20 + iVar2 * 0x10));
    FUN_02320c28((undefined4 *)(DAT_02320c1c + iVar2 * 0x20),(int *)(DAT_02320c24 + iVar2 * 0x10));
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x20);
  FUN_023314e8(DAT_02320c14,0x400);
  FUN_023314e8(DAT_02320c1c,0x400);
  *(undefined4 *)(DAT_02320c18 + 0x60) = 1;
  FUN_0233210c();
  return;
}

