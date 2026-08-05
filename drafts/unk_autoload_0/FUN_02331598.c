// decomp: module=unk_autoload_0 addr=0x02331598 name=FUN_02331598
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb0 (Ghidra's cache says 0xac - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=30
// verify:  python tools/match.py --c <file> --func FUN_02331598 --addr 0x02331598 --size 0xb0 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331598(void)

{
  undefined4 uVar1;
  
  if (*DAT_02331644 == 0) {
    *DAT_02331644 = 1;
    uVar1 = FUN_02331678(0);
    FUN_0233178c(0,uVar1);
    uVar1 = FUN_02331718(0);
    FUN_02331798(0,uVar1);
    FUN_02331798(2,0);
    FUN_0233178c(2,0);
    uVar1 = FUN_02331678(3);
    FUN_0233178c(3,uVar1);
    uVar1 = FUN_02331718(3);
    FUN_02331798(3,uVar1);
    uVar1 = FUN_02331678(4);
    FUN_0233178c(4,uVar1);
    uVar1 = FUN_02331718(4);
    FUN_02331798(4,uVar1);
    uVar1 = FUN_02331678(5);
    FUN_0233178c(5,uVar1);
    uVar1 = FUN_02331718(5);
    FUN_02331798(5,uVar1);
    uVar1 = FUN_02331678(6);
    FUN_0233178c(6,uVar1);
    uVar1 = FUN_02331718(6);
    FUN_02331798(6,uVar1);
  }
  return;
}

