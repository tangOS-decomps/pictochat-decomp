// decomp: module=unk_autoload_0 addr=0x0233946c name=FUN_0233946c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x78 (Ghidra's cache says 0x70 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=33  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0233946c --addr 0x0233946c --size 0x78 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233946c(void)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *local_18;
  
  uVar2 = 0;
  local_18 = DAT_023394e0;
  puVar4 = DAT_023394dc + 0x3b;
  puVar3 = DAT_023394dc;
  do {
    *local_18 = *puVar3;
    uVar1 = *puVar3 & 0x38000000;
    if ((uVar1 == 0x18000000) || (uVar1 == 0x20000000)) {
      FUN_0233731c(uVar2);
    }
    else if (uVar1 == 0x28000000) {
      do {
      } while ((*puVar4 & 0x80000000) != 0);
    }
    else if ((*puVar3 & 0x2000000) == 0) {
      FUN_0233731c(uVar2);
    }
    else {
      FUN_02337358(uVar2);
    }
    uVar2 = uVar2 + 1;
    local_18 = local_18 + 1;
    puVar3 = puVar3 + 3;
  } while (uVar2 < 4);
  return;
}

