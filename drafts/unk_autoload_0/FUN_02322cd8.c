// decomp: module=unk_autoload_0 addr=0x02322cd8 name=FUN_02322cd8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), thumb
// triage: noise=10 statements=28
// verify:  python tools/match.py --c <file> --func FUN_02322cd8 --addr 0x02322cd8 --size 0x58 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322cd8(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 in_r3;
  undefined1 auStack_28 [32];
  undefined4 uStack_8;
  
  puVar1 = PTR_DAT_02322d24;
  iVar2 = *(int *)(PTR_DAT_02322d24 + 8);
  *(int *)(PTR_DAT_02322d24 + 8) = iVar2 + 1;
  if (10 < iVar2 + 1) {
    *(undefined4 *)(puVar1 + 8) = 0;
    iVar2 = *(int *)(puVar1 + 0xc);
    iVar3 = iVar2 + 1;
    *(int *)(puVar1 + 0xc) = iVar3;
    if (iVar3 == *(int *)(puVar1 + 4)) {
      *(int *)(puVar1 + 0xc) = iVar2 + 2;
    }
    if (0xf < *(int *)(PTR_DAT_02322d24 + 0xc)) {
      *(undefined4 *)(PTR_DAT_02322d24 + 0xc) = 3;
    }
  }
  uStack_8 = in_r3;
  FUN_02334564(auStack_28,PTR_s_plt_number__d_02322d28,*(undefined4 *)(PTR_DAT_02322d24 + 0xc));
  FUN_02334564(auStack_28,PTR_s_init_plt_number__d_02322d2c,*(undefined4 *)(PTR_DAT_02322d24 + 4));
  return;
}

