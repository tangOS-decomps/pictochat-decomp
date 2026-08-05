// decomp: module=unk_autoload_0 addr=0x02329fac name=FUN_02329fac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7c (Ghidra's cache says 0x70 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=35
// verify:  python tools/match.py --c <file> --func FUN_02329fac --addr 0x02329fac --size 0x7c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02329fac(void)

{
  uint uVar1;
  int iVar2;
  short *psVar3;
  uint idx;
  short *psVar4;
  short *psVar5;
  
  iVar2 = DAT_0232a020;
  uVar1 = DAT_0232a01c;
  idx = 0;
  psVar4 = (short *)0x0;
  do {
    psVar3 = FUN_0232b690((undefined4 *)(*(int *)(iVar2 + 0x30) + (uint)*(byte *)(iVar2 + 2) * 0x10)
                          ,idx);
    psVar5 = psVar4;
    if (*psVar3 != 0) {
      if ((ushort)psVar3[4] == uVar1) break;
      if ((((ushort)psVar3[4] == DAT_0232a024) && (psVar5 = psVar3, psVar4 != (short *)0x0)) &&
         (psVar5 = psVar4,
         CONCAT22(psVar4[2],psVar4[3]) <
         ((uint)(ushort)psVar3[2] * 0x10000 | (uint)(ushort)psVar3[3]))) {
        psVar5 = psVar3;
      }
    }
    idx = idx + 1 & 0xff;
    psVar3 = psVar5;
    psVar4 = psVar5;
  } while (idx < 8);
  if (psVar3 == (short *)0x0) {
    return 0;
  }
  FUN_0232a620(psVar3,1);
  return 1;
}

