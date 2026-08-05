// decomp: module=arm7 addr=0x022c1a40 name=FUN_022c1a40
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa0 (Ghidra's cache says 0x90 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=29
// verify:  python tools/match.py --c <file> --func FUN_022c1a40 --addr 0x022c1a40 --size 0xa0 --module arm7 --version 2.0/sp1


void FUN_022c1a40(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int iVar3;
  
  iVar3 = *DAT_022c1ad0;
  FUN_022c6600(iVar3 + 0x608);
  FUN_022c6600(*DAT_022c1ad0 + 0x634);
  FUN_022c1ae0(0x20);
  *(undefined2 *)(iVar3 + 1000) = 0;
  puVar2 = DAT_022c1ad4;
  *(undefined2 *)(iVar3 + 0x356) = 0;
  *puVar2 = 0;
  puVar2[-7] = 0;
  puVar2[0x6c] = 0;
  puVar2[0x6b] = 0;
  puVar2[-5] = 0;
  puVar2[-4] = 0;
  if (*(short *)(iVar3 + 0x350) == 1) {
    func_0x00ddaa18();
  }
  puVar2 = DAT_022c1adc;
  uVar1 = (undefined2)DAT_022c1ad8;
  *DAT_022c1adc = uVar1;
  puVar2[4] = uVar1;
  func_0x00dda744();
  func_0x00dd25a0();
  return;
}

