// decomp: module=unk_autoload_0 addr=0x02325654 name=FUN_02325654
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc8 (Ghidra's cache says 0xc4 - it excludes this function's trailing literal pool), thumb
// triage: noise=10 statements=27
// verify:  python tools/match.py --c <file> --func FUN_02325654 --addr 0x02325654 --size 0xc8 --module unk_autoload_0 --version 2.0/sp1


void FUN_02325654(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  FUN_023374f0(param_1,0,DAT_02325718);
  uVar1 = FUN_023230cc(0x2800);
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = FUN_023230cc(0x2800);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = FUN_023230cc(0x2800);
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  piVar2 = FUN_02321c60();
  FUN_0232db10(param_1,*(undefined4 *)(param_1 + 0x10),0x100,0x50,0,piVar2);
  piVar2 = FUN_02321c60();
  FUN_0232db10(param_1 + 0x14,*(undefined4 *)(param_1 + 0x24),0x100,0x50,0,piVar2);
  piVar2 = FUN_02321c60();
  FUN_0232db10(param_1 + 0x28,*(undefined4 *)(param_1 + 0x38),0x100,0x50,0,piVar2);
  uVar1 = FUN_023230cc(0x2800);
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  uVar1 = FUN_023230cc(0x2800);
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  *(undefined4 *)(param_1 + 0x44) = 0x2800;
  *(ushort *)(param_1 + 0x48) = *(ushort *)(param_1 + 0x48) & 0xfff0 | 1;
  *(ushort *)(param_1 + 0x48) = *(ushort *)(param_1 + 0x48) & 0xff0f | 0x20;
  FUN_0232571c(param_1);
  return;
}

