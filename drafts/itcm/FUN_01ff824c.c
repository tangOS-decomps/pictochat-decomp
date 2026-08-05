// decomp: module=itcm addr=0x01ff824c name=FUN_01ff824c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1e, thumb
// triage: noise=2 statements=12
// verify:  python tools/match.py --c <file> --func FUN_01ff824c --addr 0x01ff824c --size 0x1e --module itcm --version 2.0/sp1


undefined4 FUN_01ff824c(void)

{
  int iVar1;
  
  iVar1 = FUN_02339250(0x15,0,0,0,0);
  if (iVar1 == 0) {
    FUN_02332080();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return 1;
}

