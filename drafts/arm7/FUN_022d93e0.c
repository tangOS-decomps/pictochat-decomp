// decomp: module=arm7 addr=0x022d93e0 name=FUN_022d93e0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18c (Ghidra's cache says 0x178 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=69  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d93e0 --addr 0x022d93e0 --size 0x18c --module arm7 --version 2.0/sp1


void FUN_022d93e0(void)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = 0;
  uVar4 = DAT_022d955c;
  puVar3 = DAT_022d9558;
  do {
    uVar2 = uVar2 + 2;
    *puVar3 = (ushort)uVar4;
    uVar4 = uVar4 - 1 & 0xffff;
    puVar3 = puVar3 + 1;
  } while (uVar2 < 0x2000);
  uVar2 = 0;
  puVar3 = DAT_022d9558;
  uVar4 = DAT_022d955c;
  for (uVar5 = 0; uVar5 < 0x2000; uVar5 = uVar5 + 2) {
    uVar1 = uVar2;
    if ((*puVar3 != uVar4) && (uVar1 = uVar2 + 1, 0x20 < uVar2)) goto LAB_022d9530;
    puVar3 = puVar3 + 1;
    uVar4 = uVar4 - 1 & 0xffff;
    uVar2 = uVar1;
  }
  uVar5 = 0;
  puVar3 = DAT_022d9558;
  uVar4 = DAT_022d9560;
  do {
    uVar5 = uVar5 + 2;
    *puVar3 = (ushort)uVar4;
    uVar4 = ~uVar4 & 0xffff;
    puVar3 = puVar3 + 1;
  } while (uVar5 < 0x2000);
  puVar3 = DAT_022d9558;
  uVar4 = DAT_022d9560;
  for (uVar5 = 0; uVar5 < 0x2000; uVar5 = uVar5 + 2) {
    uVar1 = uVar2;
    if ((*puVar3 != uVar4) && (uVar1 = uVar2 + 1, 0x20 < uVar2)) goto LAB_022d9530;
    puVar3 = puVar3 + 1;
    uVar4 = ~uVar4 & 0xffff;
    uVar2 = uVar1;
  }
  uVar5 = 0;
  puVar3 = DAT_022d9558;
  uVar4 = DAT_022d9564;
  do {
    uVar5 = uVar5 + 2;
    *puVar3 = (ushort)uVar4;
    uVar4 = ~uVar4 & 0xffff;
    puVar3 = puVar3 + 1;
  } while (uVar5 < 0x2000);
  uVar5 = 0;
  puVar3 = DAT_022d9558;
  uVar4 = DAT_022d9564;
  while ((uVar1 = uVar2, uVar5 < 0x2000 && ((*puVar3 == uVar4 || (uVar1 = uVar2 + 1, uVar2 < 0x21)))
         )) {
    uVar5 = uVar5 + 2;
    puVar3 = puVar3 + 1;
    uVar4 = ~uVar4 & 0xffff;
    uVar2 = uVar1;
  }
LAB_022d9530:
  if (uVar1 != 0) {
    *(ushort *)(*DAT_022d9568 + 0x33e) = *(ushort *)(*DAT_022d9568 + 0x33e) | 2;
  }
  return;
}

