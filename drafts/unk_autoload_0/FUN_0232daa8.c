// decomp: module=unk_autoload_0 addr=0x0232daa8 name=FUN_0232daa8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68, thumb
// triage: noise=9 statements=17
// verify:  python tools/match.py --c <file> --func FUN_0232daa8 --addr 0x0232daa8 --size 0x68 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232daa8(int *param_1,int param_2,int param_3)

{
  *(undefined2 *)(param_1 + 4) = *(undefined2 *)(param_2 + 6);
  *(undefined2 *)((int)param_1 + 0x16) = *(undefined2 *)(param_2 + 8);
  param_1[3] = param_2 + 10;
  *param_1 = param_2 + 10 + (uint)*(ushort *)(param_1 + 4) * 2;
  *(short *)(param_1 + 5) =
       (short)((int)((*(ushort *)((int)param_1 + 0x16) & 0x1f) *
                     ((*(ushort *)((int)param_1 + 0x16) & 0x3ff) >> 5) + 0xf) >> 4);
  *(undefined2 *)((int)param_1 + 0x12) = 0;
  param_1[7] = param_1[7] & 0xfffffffeU | 3;
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_3 + *(int *)(param_3 + 0xc) + 8);
  param_1[1] = param_3 + 0xc + *(int *)(param_3 + 0xc);
  *(undefined2 *)((int)param_1 + 0x1a) = *(undefined2 *)(param_3 + *(int *)(param_3 + 8) + 8);
  param_1[2] = param_3 + 10 + *(int *)(param_3 + 8);
  return;
}

