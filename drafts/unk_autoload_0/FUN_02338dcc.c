// decomp: module=unk_autoload_0 addr=0x02338dcc name=FUN_02338dcc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x28 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=15
// verify:  python tools/match.py --c <file> --func FUN_02338dcc --addr 0x02338dcc --size 0x2c --module unk_autoload_0 --version 2.0/sp1


bool FUN_02338dcc(undefined2 *param_1)

{
  int iVar1;
  bool bVar2;
  
  FUN_02339024(1);
  iVar1 = DAT_02338df4;
  bVar2 = (*(ushort *)(DAT_02338df4 + 0x38) & 1) != 0;
  if (!bVar2) {
    *param_1 = *(undefined2 *)(DAT_02338df4 + 8);
    param_1[1] = *(undefined2 *)(iVar1 + 10);
    param_1[2] = *(undefined2 *)(iVar1 + 0xc);
    param_1[3] = *(undefined2 *)(iVar1 + 0xe);
  }
  return bVar2;
}

