// decomp: module=unk_autoload_0 addr=0x02322d30 name=FUN_02322d30
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x28 - it excludes this function's trailing literal pool), thumb
// triage: noise=8 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02322d30 --addr 0x02322d30 --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322d30(void)

{
  undefined4 in_r3;
  undefined1 auStack_28 [32];
  undefined4 uStack_8;
  
  uStack_8 = in_r3;
  FUN_02334564(auStack_28,PTR_s_plt_number__d_02322d5c,*(undefined4 *)(PTR_DAT_02322d58 + 0xc));
  FUN_02334564(auStack_28,PTR_s_init_plt_number__d_02322d60,*(undefined4 *)(PTR_DAT_02322d58 + 4));
  FUN_02328e04(*(undefined4 *)(PTR_DAT_02322d58 + 0xc));
  return;
}

