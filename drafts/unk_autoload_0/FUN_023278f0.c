// decomp: module=unk_autoload_0 addr=0x023278f0 name=FUN_023278f0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x70 (Ghidra's cache says 0x62 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=29
// verify:  python tools/match.py --c <file> --func FUN_023278f0 --addr 0x023278f0 --size 0x70 --module unk_autoload_0 --version 2.0/sp1


void FUN_023278f0(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  *(int *)(PTR_DAT_02327954 + 4) = *(int *)(PTR_DAT_02327954 + 4) + 1;
  if (0x18 < param_1) {
    param_1 = 0x18;
  }
  if ((param_1 < 3) && (2 < *(int *)(PTR_DAT_02327954 + 4))) {
    iVar3 = 0;
  }
  else {
    iVar3 = (param_1 + -3) * 3 + 0x40;
  }
  FUN_0232e9b8(PTR_DAT_02327958,iVar3,0);
  puVar1 = PTR_DAT_02327954;
  iVar3 = (param_1 + -0xc) * 5 * *(int *)(PTR_DAT_02327954 + 8);
  *(int *)(PTR_DAT_02327954 + 0x10) = iVar3;
  uVar2 = DAT_0232795c;
  if (1 < *(int *)(puVar1 + 4)) {
    iVar4 = *(int *)(puVar1 + 0xc);
    iVar3 = iVar4 + (iVar3 - iVar4) / 2;
  }
  *(int *)(PTR_DAT_02327954 + 0xc) = iVar3;
  FUN_0232e9ec(PTR_DAT_02327958,uVar2);
  return;
}

