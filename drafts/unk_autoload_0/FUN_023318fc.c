// decomp: module=unk_autoload_0 addr=0x023318fc name=FUN_023318fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x32 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=21  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023318fc --addr 0x023318fc --size 0x44 --module unk_autoload_0 --version 2.0/sp1


void FUN_023318fc(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *DAT_02331930;
  if ((uVar4 < 0x2600000) || (0x27fffff < uVar4)) {
    uVar4 = 0;
  }
  *DAT_02331934 = uVar4;
  uVar3 = DAT_0233193c;
  uVar2 = DAT_02331938;
  puVar1 = DAT_02331930;
  if (uVar4 == 0) {
    *DAT_02331930 = DAT_02331938;
    *(uint *)(uVar3 & (uint)puVar1) = uVar2;
  }
  DAT_02331934[2] = 0;
  return;
}

