// decomp: module=unk_autoload_0 addr=0x0232a264 name=FUN_0232a264
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa0 (Ghidra's cache says 0x90 - it excludes this function's trailing literal pool), thumb
// triage: noise=26 statements=41
// verify:  python tools/match.py --c <file> --func FUN_0232a264 --addr 0x0232a264 --size 0xa0 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a264(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 in_r3;
  
  pcVar4 = (code *)*DAT_0232a2f4;
  if (pcVar4 != (code *)0x0) {
    uVar3 = (*pcVar4)(0x40,0x20,pcVar4,in_r3,in_r3);
    pcVar4 = (code *)*DAT_0232a2f4;
    *(undefined4 *)(DAT_0232a2f8 + 0x50) = uVar3;
    uVar3 = (*pcVar4)(0x70,0x20);
    iVar2 = DAT_0232a2f8;
    puVar1 = DAT_0232a2f4;
    *(undefined4 *)(DAT_0232a2f8 + 0x34) = uVar3;
    *(undefined2 *)(iVar2 + 2) = 0x1840;
    uVar3 = (*(code *)*puVar1)(*(undefined2 *)(iVar2 + 2),0x20);
    iVar2 = DAT_0232a2f8;
    puVar1 = DAT_0232a2f4;
    *(undefined4 *)(DAT_0232a2f8 + 0x18) = uVar3;
    *(undefined2 *)(iVar2 + 10) = 0xe0;
    uVar3 = (*(code *)*puVar1)(*(undefined2 *)(iVar2 + 10),0x20);
    pcVar4 = (code *)*DAT_0232a2f4;
    *(undefined4 *)(DAT_0232a2f8 + 0x28) = uVar3;
    uVar3 = (*pcVar4)(0xc0,0x20);
    pcVar4 = (code *)*DAT_0232a2f4;
    *(undefined4 *)(DAT_0232a2f8 + 0x44) = uVar3;
    uVar3 = (*pcVar4)(0xc0,0x20);
    *(undefined4 *)(DAT_0232a2f8 + 0x3c) = uVar3;
    FUN_0232b85c(0x4000);
    FUN_0232c098();
  }
  FUN_02331dd4(DAT_0232a2fc);
  *(undefined4 *)(DAT_0232a2f8 + 0x54) = 0;
  FUN_02331dd4(DAT_0232a300);
  uVar3 = FUN_02331ca8();
  *(undefined4 *)(DAT_0232a2f8 + 0x4c) = uVar3;
  FUN_0232a1e4();
  return;
}

