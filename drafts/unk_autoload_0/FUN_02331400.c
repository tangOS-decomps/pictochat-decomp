// decomp: module=unk_autoload_0 addr=0x02331400 name=FUN_02331400
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c, thumb
// triage: noise=2 statements=13
// verify:  python tools/match.py --c <file> --func FUN_02331400 --addr 0x02331400 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_02331400(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x88) != 0) {
    do {
      iVar1 = FUN_02330bcc(param_1 + 0x88);
      *(undefined4 *)(iVar1 + 0xc) = 0;
      *(undefined4 *)(iVar1 + 8) = 0;
      FUN_02330f6c();
    } while (*(int *)(param_1 + 0x88) != 0);
  }
  return;
}

