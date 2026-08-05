// decomp: module=unk_autoload_0 addr=0x02334eb4 name=FUN_02334eb4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5e, thumb
// triage: noise=3 statements=30
// verify:  python tools/match.py --c <file> --func FUN_02334eb4 --addr 0x02334eb4 --size 0x5e --module unk_autoload_0 --version 2.0/sp1


void FUN_02334eb4(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (int)*(short *)(param_1 + 2);
  FUN_02334dbc(param_4);
  if (*(byte *)(param_4 + 5) < 10) {
    if (0x20 < iVar3) {
      iVar3 = 0x20;
    }
    FUN_02334980(param_4,iVar3);
    bVar1 = *(byte *)(param_4 + 4);
    while ((int)(uint)bVar1 < iVar3) {
      *(char *)(param_4 + 4) = *(char *)(param_4 + 4) + '\x01';
      *(undefined1 *)(param_4 + (uint)bVar1 + 5) = 0;
      bVar1 = *(byte *)(param_4 + 4);
    }
    iVar3 = 0;
    *(ushort *)(param_4 + 2) = *(short *)(param_4 + 2) - (bVar1 - 1);
    if (*(char *)(param_4 + 4) != '\0') {
      do {
        iVar2 = param_4 + iVar3;
        iVar3 = iVar3 + 1;
        *(char *)(iVar2 + 5) = *(char *)(iVar2 + 5) + '0';
      } while (iVar3 < (int)(uint)*(byte *)(param_4 + 4));
    }
  }
  return;
}

