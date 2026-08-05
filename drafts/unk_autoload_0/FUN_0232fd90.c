// decomp: module=unk_autoload_0 addr=0x0232fd90 name=FUN_0232fd90
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5a, thumb
// triage: noise=2 statements=27
// verify:  python tools/match.py --c <file> --func FUN_0232fd90 --addr 0x0232fd90 --size 0x5a --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232fd90(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int i;
  
  FUN_0232f54c();
  i = 0;
  do {
    pbVar1 = (byte *)FUN_0232f63c(i);
    if (pbVar1 != (byte *)0x0) {
      FUN_0232e8c8(i,*pbVar1);
      FUN_0232e8dc(i,(uint)*(ushort *)(pbVar1 + 2));
      if (((*(int *)(pbVar1 + 4) != 0) && (param_1 != 0)) && (iVar3 = 0, *pbVar1 != 0)) {
        do {
          iVar2 = FUN_0232e8ec(i,param_1,*(undefined4 *)(pbVar1 + 4));
          if (iVar2 == 0) {
            return 0;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)*pbVar1);
      }
    }
    i = i + 1;
  } while (i < 0x20);
  return 1;
}

