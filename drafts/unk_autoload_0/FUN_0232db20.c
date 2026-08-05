// decomp: module=unk_autoload_0 addr=0x0232db20 name=FUN_0232db20
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3a - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=21  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232db20 --addr 0x0232db20 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


uint FUN_0232db20(uint param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 <= param_3) {
    do {
      iVar1 = param_2 + (param_3 - param_2 >> 1);
      uVar2 = (uint)*(ushort *)(param_4 + iVar1 * 2);
      if (param_1 < uVar2) {
        param_3 = iVar1 + -1;
      }
      else {
        if (param_1 <= uVar2) {
          return (uint)*(ushort *)(&stack0x00000008 + DAT_0232db5c) + iVar1;
        }
        param_2 = iVar1 + 1;
      }
    } while (param_2 <= param_3);
  }
  return (uint)*(ushort *)(&stack0x0000000c + DAT_0232db5c);
}

