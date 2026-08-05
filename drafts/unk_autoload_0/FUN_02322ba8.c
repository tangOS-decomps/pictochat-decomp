// decomp: module=unk_autoload_0 addr=0x02322ba8 name=FUN_02322ba8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=20
// verify:  python tools/match.py --c <file> --func FUN_02322ba8 --addr 0x02322ba8 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322ba8(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  int extraout_r1;
  
  pvVar2 = FUN_0232254c();
  FUN_02336018(*(undefined4 *)((int)pvVar2 + 4),0x14);
  if ((extraout_r1 == 0) &&
     (iVar3 = FUN_0233999c(DAT_02322bdc,DAT_02322be0), puVar1 = DAT_02322be4, iVar3 != 0)) {
    DAT_02322be4[3] = 0;
    puVar1[4] = 1;
    puVar1[5] = 1;
    puVar1[6] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  return;
}

