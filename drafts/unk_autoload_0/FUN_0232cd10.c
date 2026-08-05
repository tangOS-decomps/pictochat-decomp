// decomp: module=unk_autoload_0 addr=0x0232cd10 name=FUN_0232cd10
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x82, thumb
// triage: noise=9 statements=38
// verify:  python tools/match.py --c <file> --func FUN_0232cd10 --addr 0x0232cd10 --size 0x82 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232cd10(int param_1,ushort *param_2,int param_3,undefined4 param_4,undefined2 param_5)

{
  int iVar1;
  void *pvVar2;
  undefined2 local_40 [2];
  ushort *local_3c;
  undefined1 auStack_38 [24];
  undefined4 local_20;
  undefined2 local_1a;
  undefined4 uStack_18;
  
  uStack_18 = param_4;
  iVar1 = FUN_0232c520(1,2);
  if (iVar1 == 0) {
    if (param_2 == (ushort *)0x0) {
      return 6;
    }
    FUN_023314e8(param_2,(uint)*param_2 << 1);
    pvVar2 = FUN_0232c4d0();
    *(undefined2 *)((int)pvVar2 + 0x150) = 0;
    *(undefined4 *)((int)pvVar2 + 0x14c) = 0;
    FUN_0232c3bc(0xc,param_1);
    local_40[0] = 0xc;
    local_3c = param_2;
    if (param_3 == 0) {
      FUN_023374f0(auStack_38,0,0x18);
    }
    else {
      FUN_02337584(param_3,auStack_38,0x18);
    }
    local_1a = param_5;
    local_20 = param_4;
    iVar1 = FUN_0232c484(local_40,0x28);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
  }
  return iVar1;
}

