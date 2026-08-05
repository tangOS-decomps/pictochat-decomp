// decomp: module=arm7 addr=0x022dc0f4 name=FUN_022dc0f4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xec (Ghidra's cache says 0xe8 - it excludes this function's trailing literal pool), arm
// triage: noise=13 statements=42
// verify:  python tools/match.py --c <file> --func FUN_022dc0f4 --addr 0x022dc0f4 --size 0xec --module arm7 --version 2.0/sp1


uint FUN_022dc0f4(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  
  piVar1 = DAT_022dc1dc;
  uVar2 = 1;
  *(undefined2 *)(param_2 + 2) = 1;
  if (*(short *)(*piVar1 + 0x34c) == 0x10) {
    uVar3 = FUN_022d6e98(param_1 + 0x10);
    uVar4 = FUN_022d6ef8(*(undefined2 *)(param_1 + 0x16));
    uVar5 = FUN_022d6f2c(*(undefined2 *)(param_1 + 0x18));
    uVar6 = FUN_022d6f6c(*(undefined2 *)(param_1 + 0x1c));
    uVar7 = FUN_022d6fec(*(undefined2 *)(param_1 + 0x1e));
    uVar8 = FUN_022d7020(*(undefined2 *)(param_1 + 0x20));
    uVar9 = FUN_022d70c0(*(undefined2 *)(param_1 + 0x22));
    uVar10 = FUN_022d70e4(param_1 + 0x24);
    uVar11 = FUN_022d7144(*(undefined2 *)(param_1 + 0x74));
    uVar12 = FUN_022d717c(*(undefined2 *)(param_1 + 0x76));
    uVar13 = FUN_022d71b4(*(undefined2 *)(param_1 + 0x78));
    uVar14 = FUN_022d71ec(*(undefined2 *)(param_1 + 0x7a),0);
    uVar15 = FUN_022d729c(param_1 + 0x7c);
    uVar16 = FUN_022d72cc(*(undefined2 *)(param_1 + 0x9c));
    uVar2 = FUN_022d7374(*(undefined2 *)(param_1 + 0x9e));
    uVar2 = uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 | uVar12 |
            uVar13 | uVar14 | uVar15 | uVar16 | uVar2;
  }
  return uVar2;
}

