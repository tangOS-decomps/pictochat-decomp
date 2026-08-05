// decomp: module=unk_autoload_0 addr=0x0232a064 name=FUN_0232a064
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=27
// verify:  python tools/match.py --c <file> --func FUN_0232a064 --addr 0x0232a064 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


short * FUN_0232a064(int param_1)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  uint idx;
  uint uVar4;
  
  iVar1 = DAT_0232a0b4;
  uVar4 = DAT_0232a0b0;
  idx = 0;
  while ((psVar3 = FUN_0232b690((undefined4 *)(*(int *)(iVar1 + 0x30) + param_1 * 0x10),idx),
         iVar2 = DAT_0232a0b4, *psVar3 == 0 || ((ushort)psVar3[4] != uVar4))) {
    idx = idx + 1 & 0xff;
    if (7 < idx) {
      uVar4 = 0;
      do {
        psVar3 = FUN_0232b690((undefined4 *)(*(int *)(iVar2 + 0x30) + param_1 * 0x10),uVar4);
        if (*psVar3 != 0) {
          return psVar3;
        }
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < 8);
      return (short *)0x0;
    }
  }
  return psVar3;
}

