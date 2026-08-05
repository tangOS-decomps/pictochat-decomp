// decomp: module=arm7 addr=0x022c5bd8 name=FUN_022c5bd8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa8, arm
// triage: noise=0 statements=37  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c5bd8 --addr 0x022c5bd8 --size 0xa8 --module arm7 --version 2.0/sp1


uint * FUN_022c5bd8(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = (uint *)0x0;
  for (puVar3 = param_1; (puVar3 != (uint *)0x0 && (puVar3 < param_2)); puVar3 = (uint *)puVar3[1])
  {
    puVar2 = puVar3;
  }
  *param_2 = (uint)puVar2;
  param_2[1] = (uint)puVar3;
  if (puVar3 != (uint *)0x0) {
    *puVar3 = (uint)param_2;
    if ((uint *)((int)param_2 + param_2[2]) == puVar3) {
      param_2[2] = param_2[2] + puVar3[2];
      puVar3 = (uint *)puVar3[1];
      param_2[1] = (uint)puVar3;
      if (puVar3 != (uint *)0x0) {
        *puVar3 = (uint)param_2;
      }
    }
  }
  puVar1 = param_2;
  if (puVar2 != (uint *)0x0) {
    puVar2[1] = (uint)param_2;
    puVar1 = param_1;
    if ((uint *)((int)puVar2 + puVar2[2]) == param_2) {
      puVar2[2] = puVar2[2] + param_2[2];
      puVar2[1] = (uint)puVar3;
      if (puVar3 != (uint *)0x0) {
        *puVar3 = (uint)puVar2;
      }
    }
  }
  return puVar1;
}

