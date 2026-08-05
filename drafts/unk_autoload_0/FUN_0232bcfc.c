// decomp: module=unk_autoload_0 addr=0x0232bcfc name=FUN_0232bcfc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x90 (Ghidra's cache says 0x80 - it excludes this function's trailing literal pool), thumb
// triage: noise=16 statements=38
// verify:  python tools/match.py --c <file> --func FUN_0232bcfc --addr 0x0232bcfc --size 0x90 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232bcfc(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 in_r3;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined1 local_18;
  undefined2 local_16;
  undefined4 local_14;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_1c = 0;
  local_1a = 0x14;
  uStack_8 = in_r3;
  uVar1 = FUN_0232a4e8();
  local_18 = (undefined1)uVar1;
  local_16 = (undefined2)DAT_0232bd7c;
  local_14 = *(undefined4 *)(PTR_DAT_0232bd80 + 0x28);
  local_c = FUN_0232a4c8();
  *(undefined4 *)(PTR_DAT_0232bd80 + 4) = local_c;
  uVar1 = FUN_0232a4e8();
  if (uVar1 != 0) {
    FUN_02337584(&local_1c,*(undefined4 *)(PTR_DAT_0232bd80 + 0x34),0x14);
    FUN_0232c100(0xd,*(undefined4 *)(PTR_DAT_0232bd80 + 0x34),0x14,1,PTR_FUN_0232bf8c_1_0232bd84);
    return;
  }
  iVar2 = FUN_0232b794(PTR_DAT_0232bd88,&local_1c,0x14);
  if (iVar2 == 0) {
    FUN_0232a480();
    FUN_02329bd8(0xc);
    return;
  }
  if (*(int *)(PTR_DAT_0232bd80 + 0x38) == 0) {
    FUN_0232bd8c();
  }
  return;
}

