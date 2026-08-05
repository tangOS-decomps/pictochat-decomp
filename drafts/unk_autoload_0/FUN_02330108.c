// decomp: module=unk_autoload_0 addr=0x02330108 name=FUN_02330108
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44, thumb
// triage: noise=1 statements=17
// verify:  python tools/match.py --c <file> --func FUN_02330108 --addr 0x02330108 --size 0x44 --module unk_autoload_0 --version 2.0/sp1


void FUN_02330108(int *param_1,int param_2)

{
  void *obj;
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = FUN_02332080();
  pvVar2 = (void *)FUN_0232e178(param_1,0);
  while (obj = pvVar2, obj != (void *)0x0) {
    pvVar2 = (void *)FUN_0232e178(param_1,(int)obj);
    if (*(int *)((int)obj + 8) == param_2) {
      FUN_0232e13c(param_1,obj);
      FUN_0233014c(obj);
    }
  }
  FUN_02332094(uVar1);
  return;
}

