// decomp: module=main addr=0x02000c00 name=_start
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x13c (Ghidra's cache says 0x118 - it excludes this function's trailing literal pool), arm
// triage: noise=10 statements=38
// verify:  python tools/match.py --c <file> --func _start --addr 0x02000c00 --size 0x13c --module main --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _start(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  _DAT_04000208 = 0x4000000;
  do {
  } while (_DAT_04000006 != 0);
  FUN_02000e78();
  FUN_02000d3c(0,DAT_02000d18,0x4000);
  FUN_02000d3c(0,DAT_02000d20,0x400);
  FUN_02000d3c(0x200,DAT_02000d24,0x400);
  FUN_02000d50(*(undefined4 *)(DAT_02000d28 + 0x14));
  FUN_02000dfc();
  puVar4 = *(undefined4 **)(DAT_02000d28 + 0x10);
  puVar1 = *(undefined4 **)(DAT_02000d28 + 0xc);
  for (puVar2 = puVar1; puVar2 < puVar4; puVar2 = puVar2 + 1) {
    *puVar2 = 0;
  }
  uVar3 = (uint)puVar1 & 0xffffffe0;
  do {
    coproc_moveto_Data_Synchronization(0);
    coproc_moveto_Invalidate_Instruction_Cache_by_MVA(uVar3);
    coproc_moveto_Invalidate_Data_Cache_by_MVA(uVar3);
    uVar3 = uVar3 + 0x20;
  } while ((int)uVar3 < (int)puVar4);
  *DAT_02000d2c = 0;
  *(undefined4 *)(DAT_02000d18 + 0x3ffc) = DAT_02000d30;
  FUN_023361fc();
  FUN_02000f60();
  FUN_02336200();
                    /* WARNING: Could not recover jumptable at 0x02000d14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_02000d34)();
  return;
}

