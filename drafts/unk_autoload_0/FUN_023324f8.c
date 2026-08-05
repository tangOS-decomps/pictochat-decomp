// decomp: module=unk_autoload_0 addr=0x023324f8 name=FUN_023324f8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x68 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=14  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023324f8 --addr 0x023324f8 --size 0x74 --module unk_autoload_0 --version 2.0/sp1


void FUN_023324f8(uint param_1,uint param_2)

{
  ushort *puVar1;
  uint uVar2;
  
  puVar1 = DAT_02332564;
  uVar2 = param_2 >> 8;
  do {
  } while ((*DAT_02332560 & 0x80000000) != 0);
  *DAT_02332564 = *DAT_02332564 & (ushort)DAT_02332568 | 0xc000;
  *(uint *)(puVar1 + 4) =
       param_1 & 0xff | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  *(uint *)(puVar1 + 6) = param_2 & 0xff;
  return;
}

