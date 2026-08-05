// decomp: module=unk_autoload_0 addr=0x02327dac name=FUN_02327dac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x62 - it excludes this function's trailing literal pool), thumb
// triage: noise=13 statements=24
// verify:  python tools/match.py --c <file> --func FUN_02327dac --addr 0x02327dac --size 0x74 --module unk_autoload_0 --version 2.0/sp1


void FUN_02327dac(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 in_r3;
  uint uVar5;
  undefined4 local_24 [4];
  
  puVar1 = PTR_DAT_02327e14;
  local_24[0] = *(undefined4 *)PTR_DAT_02327e10;
  local_24[1] = *(undefined4 *)(PTR_DAT_02327e10 + 4);
  local_24[2] = *(undefined4 *)(PTR_DAT_02327e10 + 8);
  *(undefined2 *)(PTR_DAT_02327e14 + 0x16) = 6;
  local_24[3] = in_r3;
  FUN_023210c8(puVar1,0,0,0,0);
  for (uVar5 = 0; uVar5 < 3; uVar5 = uVar5 + 1) {
    uVar2 = FUN_02320c7c();
    uVar3 = FUN_023279a4(*(undefined2 *)(PTR_DAT_02327e14 + 0xc),uVar5);
    uVar4 = FUN_02327e20(0xf,1);
    FUN_02320e60(uVar2,PTR_DAT_02327e18,PTR_DAT_02327e1c,local_24[uVar5],uVar3,0,uVar4);
  }
  return;
}

