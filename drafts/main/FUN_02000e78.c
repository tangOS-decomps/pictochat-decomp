// decomp: module=main addr=0x02000e78 name=FUN_02000e78
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe8 (Ghidra's cache says 0xb8 - it excludes this function's trailing literal pool), arm
// triage: noise=42 statements=36
// verify:  python tools/match.py --c <file> --func FUN_02000e78 --addr 0x02000e78 --size 0xe8 --module main --version 2.0/sp1


uint FUN_02000e78(void)

{
  uint uVar1;
  undefined4 in_cr0;
  undefined4 in_cr1;
  undefined4 in_cr2;
  undefined4 in_cr3;
  undefined4 in_cr4;
  undefined4 in_cr5;
  undefined4 in_cr6;
  undefined4 in_cr7;
  undefined4 in_cr9;
  
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 & ~DAT_02000f30);
  coproc_moveto_Invalidate_Entire_Instruction(0);
  coproc_moveto_Invalidate_Entire_Data_cache(0);
  coproc_moveto_Data_Synchronization(0);
  coprocessor_moveto(0xf,0,0,DAT_02000f34,in_cr6,in_cr0);
  coprocessor_moveto(0xf,0,0,DAT_02000f38,in_cr6,in_cr1);
  coprocessor_moveto(0xf,0,0,DAT_02000f3c,in_cr6,in_cr2);
  coprocessor_moveto(0xf,0,0,DAT_02000f40,in_cr6,in_cr3);
  coprocessor_moveto(0xf,0,0,DAT_02000f44 | 0x1b,in_cr6,in_cr4);
  coprocessor_moveto(0xf,0,0,DAT_02000f48,in_cr6,in_cr5);
  coprocessor_moveto(0xf,0,0,DAT_02000f4c,in_cr6,in_cr6);
  coprocessor_moveto(0xf,0,0,DAT_02000f50,in_cr6,in_cr7);
  coprocessor_moveto(0xf,0,1,0x20,in_cr9,in_cr1);
  coprocessor_moveto(0xf,0,0,DAT_02000f44 | 10,in_cr9,in_cr1);
  coproc_moveto_Translation_table_base_1(0x4a);
  coproc_moveto_Translation_table_base_0(0x4a);
  coproc_moveto_Domain_Access_Control(10);
  coprocessor_moveto(0xf,0,3,DAT_02000f54,in_cr5,in_cr0);
  coprocessor_moveto(0xf,0,2,DAT_02000f58,in_cr5,in_cr0);
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 | DAT_02000f5c);
  return uVar1 | DAT_02000f5c;
}

