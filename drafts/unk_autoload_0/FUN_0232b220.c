// decomp: module=unk_autoload_0 addr=0x0232b220 name=FUN_0232b220
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x3e - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=19
// verify:  python tools/match.py --c <file> --func FUN_0232b220 --addr 0x0232b220 --size 0x50 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232b220(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 1;
  iVar2 = 0;
  iVar3 = DAT_0232b264;
  do {
    if (CONCAT22(*(undefined2 *)(DAT_0232b268 + (uint)*(ushort *)(DAT_0232b260 + 0xc) * 6),
                 *(undefined2 *)(DAT_0232b26c + (uint)*(ushort *)(DAT_0232b260 + 0xc) * 6)) <
        CONCAT22(*(undefined2 *)(iVar3 + 2),*(undefined2 *)(iVar3 + 4))) {
      iVar1 = iVar1 + 1;
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 6;
  } while (iVar2 < 0x10);
  return iVar1;
}

