// decomp: module=unk_autoload_0 addr=0x02334f14 name=FUN_02334f14
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x66 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=22  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02334f14 --addr 0x02334f14 --size 0x74 --module unk_autoload_0 --version 2.0/sp1


uint FUN_02334f14(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = DAT_02334f7c & (param_1 >> 1 | param_2 << 0x1f);
  uVar4 = param_1 - uVar2;
  uVar1 = (param_2 - (param_2 >> 1 & DAT_02334f7c)) - (uint)(param_1 < uVar2);
  uVar2 = uVar4 & DAT_02334f80;
  uVar4 = (uVar4 >> 2 | uVar1 * 0x40000000) & DAT_02334f80;
  uVar3 = uVar2 + uVar4;
  uVar1 = (uVar1 & DAT_02334f80) + (uVar1 >> 2 & DAT_02334f80) + (uint)CARRY4(uVar2,uVar4);
  uVar2 = uVar3 >> 4 | uVar1 * 0x10000000;
  uVar4 = uVar3 + uVar2 & DAT_02334f84;
  uVar2 = uVar1 + (uVar1 >> 4) + (uint)CARRY4(uVar3,uVar2) & DAT_02334f84;
  uVar1 = uVar4 >> 8 | uVar2 << 0x18;
  uVar3 = uVar4 + uVar1;
  uVar2 = uVar2 + (uVar2 >> 8) + (uint)CARRY4(uVar4,uVar1);
  uVar1 = uVar3 >> 0x10 | uVar2 * 0x10000;
  return uVar3 + uVar1 + uVar2 + (uVar2 >> 0x10) + (uint)CARRY4(uVar3,uVar1) & 0xff;
}

