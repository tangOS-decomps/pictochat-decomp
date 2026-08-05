// decomp: module=unk_autoload_0 addr=0x02329144 name=FUN_02329144
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe4 (Ghidra's cache says 0xca - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=45
// verify:  python tools/match.py --c <file> --func FUN_02329144 --addr 0x02329144 --size 0xe4 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329144(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_0232b95c();
  puVar1 = PTR_DAT_02329210;
  if (iVar2 != 0) {
    FUN_0233746c(0,PTR_DAT_02329210,0x4000);
    uVar3 = FUN_02329994();
    FUN_02337584(uVar3,puVar1 + 2,6);
    *puVar1 = 3;
    puVar1[1] = 2;
    FUN_02337584(PTR_DAT_02329214,puVar1 + 8,0x1a);
    iVar2 = FUN_023212c8(0x200);
    if (iVar2 != 0) {
      iVar2 = FUN_023212c8(0x40);
      if (iVar2 == 0) {
        iVar2 = FUN_023212c8(0x20);
        if (iVar2 == 0) {
          iVar2 = FUN_023212c8(0x80);
          if (iVar2 == 0) {
            iVar2 = FUN_023212c8(0x10);
            if (iVar2 != 0) {
              FUN_02337584(PTR_DAT_02329224,puVar1 + 8,0x1a);
            }
          }
          else {
            FUN_02337584(PTR_DAT_02329220,puVar1 + 8,0x1a);
          }
        }
        else {
          FUN_02337584(PTR_DAT_0232921c,puVar1 + 8,0x1a);
        }
      }
      else {
        FUN_02337584(PTR_DAT_02329218,puVar1 + 8,0x1a);
      }
    }
    FUN_02337584(param_1,puVar1 + 0x24,param_2);
    FUN_023314e8(puVar1,0x4000);
    FUN_0232b984(puVar1,param_2 + 0x24);
  }
  return;
}

