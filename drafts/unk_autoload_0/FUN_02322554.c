// decomp: module=unk_autoload_0 addr=0x02322554 name=FUN_02322554
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x180 (Ghidra's cache says 0x16c - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=52  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02322554 --addr 0x02322554 --size 0x180 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322554(void)

{
  bool bVar1;
  ushort *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  puVar3 = FUN_0232254c();
  uVar4 = FUN_023226d4();
  puVar2 = DAT_023226c0;
  *puVar3 = *puVar3 & 0xfffffffb | ((*DAT_023226c0 & 0x3ff) >> 9) << 2;
  uVar6 = (uint)*puVar2;
  uVar7 = (uint)(((uVar6 & 0x3fff) >> 0xd & (uint)(*puVar2 >> 0xf) & (uVar6 & 0xfff) >> 0xb &
                  (uVar6 & 0x7fff) >> 0xe & (uVar6 & 0x7ff) >> 10) == 0);
  uVar6 = *puVar3;
  *puVar3 = uVar7 | uVar6 & 0xfffffffe;
  *puVar3 = DAT_023226c4 & (uVar7 | uVar6 & 0xfffffffc | ((*DAT_023226c0 & 0x3fff) >> 0xd) << 1) |
            ((uVar6 & 4) >> 2 | uVar7) << 8;
  *puVar3 = (uint)((uVar4 & 8) != 0) << 3 | *puVar3 & 0xfffffff7;
  iVar5 = 0;
  bVar1 = false;
  if (((*DAT_023226c8 & 2) != 0) && ((int)(*puVar3 << 0x17) < 0)) {
    bVar1 = true;
  }
  if ((bVar1) && ((uVar4 & DAT_023226cc) == DAT_023226cc)) {
    iVar5 = 1;
  }
  *puVar3 = iVar5 << 6 | *puVar3 & 0xffffffbf;
  uVar4 = 0;
  if ((*DAT_023226c8 & 2) != 0) {
    bVar1 = false;
    if (((*DAT_023226c8 & 2) != 0) && ((int)((uint)*DAT_023226d0 << 0x1d) < 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      uVar4 = 1;
    }
  }
  *puVar3 = *puVar3 & 0xffffffbf | (uVar4 | (*puVar3 & 0x7f) >> 6) << 6;
  iVar5 = 0;
  bVar1 = false;
  if (((int)((uint)*DAT_023226c0 << 0x19) < 0) && ((*DAT_023226c8 & 2) != 0)) {
    bVar1 = true;
  }
  if ((bVar1) && (-1 < (int)(*puVar3 << 0x1c))) {
    iVar5 = 1;
  }
  *puVar3 = iVar5 << 5 | *puVar3 & 0xffffffdf;
  return;
}

