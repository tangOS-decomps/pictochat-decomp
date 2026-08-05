// decomp: module=unk_autoload_0 addr=0x02329c14 name=FUN_02329c14
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x70 - it excludes this function's trailing literal pool), thumb
// triage: noise=12 statements=37
// verify:  python tools/match.py --c <file> --func FUN_02329c14 --addr 0x02329c14 --size 0x80 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329c14(byte param_1,byte param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  code *pcVar4;
  uint uVar5;
  
  pbVar1 = DAT_02329c84;
  DAT_02329c84[1] = param_2;
  *pbVar1 = param_1;
  pbVar1[4] = 8;
  pbVar1[5] = 0;
  pbVar1[2] = 0;
  pcVar4 = (code *)*DAT_02329c88;
  if (pcVar4 != (code *)0x0) {
    uVar3 = (*pcVar4)(0x20,0x20,pcVar4,param_4,param_4);
    pcVar4 = (code *)*DAT_02329c88;
    *(undefined4 *)(DAT_02329c84 + 0x18) = uVar3;
    uVar3 = (*pcVar4)(0xc0,0x20);
    puVar2 = DAT_02329c88;
    pbVar1 = DAT_02329c84;
    *(undefined4 *)(DAT_02329c84 + 0x24) = uVar3;
    uVar3 = (*(code *)*puVar2)((uint)*pbVar1 << 4,4);
    pbVar1 = DAT_02329c84;
    uVar5 = 0;
    *(undefined4 *)(DAT_02329c84 + 0x30) = uVar3;
    if (*pbVar1 != 0) {
      do {
        FUN_0232b380(*(int *)(pbVar1 + 0x30) + uVar5 * 0x10,uVar5,pbVar1[1]);
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 < *pbVar1);
    }
    FUN_02331dd4(DAT_02329c8c);
    FUN_02331dd4(DAT_02329c90);
  }
  return;
}

