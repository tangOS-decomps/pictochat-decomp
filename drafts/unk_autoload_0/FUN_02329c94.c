// decomp: module=unk_autoload_0 addr=0x02329c94 name=FUN_02329c94
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x78 (Ghidra's cache says 0x68 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=43
// verify:  python tools/match.py --c <file> --func FUN_02329c94 --addr 0x02329c94 --size 0x78 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329c94(void)

{
  byte *pbVar1;
  uint uVar2;
  
  pbVar1 = DAT_02329d00;
  if (*DAT_02329cfc != 0) {
    uVar2 = 0;
    if (*DAT_02329d00 != 0) {
      do {
        FUN_0232b3e4(*(int *)(pbVar1 + 0x30) + uVar2 * 0x10);
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < *pbVar1);
    }
    (*(code *)*DAT_02329cfc)(*(undefined4 *)(DAT_02329d00 + 0x30));
    (*(code *)*DAT_02329cfc)(*(undefined4 *)(DAT_02329d00 + 0x18));
    (*(code *)*DAT_02329cfc)(*(undefined4 *)(DAT_02329d00 + 0x24));
  }
  pbVar1 = DAT_02329d00;
  pbVar1[0x20] = 0;
  pbVar1[0x21] = 0;
  pbVar1[0x22] = 0;
  pbVar1[0x23] = 0;
  pbVar1[0x1c] = 0;
  pbVar1[0x1d] = 0;
  pbVar1[0x1e] = 0;
  pbVar1[0x1f] = 0;
  pbVar1[0x14] = 0;
  pbVar1[0x15] = 0;
  pbVar1[0x16] = 0;
  pbVar1[0x17] = 0;
  FUN_02331ef0(DAT_02329d04);
  pbVar1 = DAT_02329d00;
  pbVar1[8] = 0;
  pbVar1[9] = 0;
  pbVar1[10] = 0;
  pbVar1[0xb] = 0;
  pbVar1[0x28] = 0;
  pbVar1[0x29] = 0;
  pbVar1[0x2a] = 0;
  pbVar1[0x2b] = 0;
  FUN_02331ef0(DAT_02329d08);
  return;
}

