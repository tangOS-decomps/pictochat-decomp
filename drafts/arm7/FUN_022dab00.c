// decomp: module=arm7 addr=0x022dab00 name=FUN_022dab00
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xd4 (Ghidra's cache says 0xd0 - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=44
// verify:  python tools/match.py --c <file> --func FUN_022dab00 --addr 0x022dab00 --size 0xd4 --module arm7 --version 2.0/sp1


undefined4 FUN_022dab00(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *DAT_022dabd0;
  *(undefined2 *)(param_2 + 2) = 6;
  if (*(short *)(iVar2 + 0x32e) == 3 || *(short *)(iVar2 + 0x32e) == 2) {
    if (*(ushort *)(iVar2 + 0x34c) < 0x20) {
      uVar1 = 1;
    }
    else if ((*(ushort *)(param_1 + 0x10) & 1) == 0) {
      if (*(ushort *)(param_1 + 0x16) < 2) {
        if (*(ushort *)(param_1 + 0x18) < 0x7d1) {
          if (*(ushort *)(param_1 + 0x18) < 10) {
            uVar1 = 5;
          }
          else {
            func_0x037c62c0(0x20);
            *(int *)(iVar2 + 0x41c) = param_1;
            *(int *)(iVar2 + 0x420) = param_2;
            *(undefined2 *)(iVar2 + 0x404) = 0x30;
            *(undefined2 *)(param_2 + 0xe) = *(undefined2 *)(*(int *)(iVar2 + 0x41c) + 0x16);
            FUN_022d811c((ushort *)(param_2 + 8),(ushort *)(*(int *)(iVar2 + 0x41c) + 0x10));
            FUN_022db560();
            uVar1 = 0x80;
          }
        }
        else {
          uVar1 = 5;
        }
      }
      else {
        uVar1 = 5;
      }
    }
    else {
      uVar1 = 5;
    }
  }
  else {
    uVar1 = 0xb;
  }
  return uVar1;
}

