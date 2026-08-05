// decomp: module=unk_autoload_0 addr=0x02329524 name=FUN_02329524
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x40 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=23
// verify:  python tools/match.py --c <file> --func FUN_02329524 --addr 0x02329524 --size 0x4c --module unk_autoload_0 --version 2.0/sp1


void FUN_02329524(void)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_02329564;
  iVar3 = 0;
  do {
    iVar4 = DAT_02329568 * iVar3;
    FUN_0233746c(0,iVar1 + iVar4,0x4000);
    iVar4 = iVar1 + iVar4;
    *(undefined4 *)(iVar4 + 0x4000) = 0;
    FUN_023314e8(iVar4,0x4000);
    puVar2 = DAT_0232956c;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 6);
  *DAT_0232956c = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  return;
}

