// decomp: module=unk_autoload_0 addr=0x0232ba40 name=FUN_0232ba40
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=19
// verify:  python tools/match.py --c <file> --func FUN_0232ba40 --addr 0x0232ba40 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ba40(int param_1)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = FUN_0232a4e8();
  if (uVar1 == 0) {
    iVar2 = FUN_0232b794(DAT_0232ba74,*(undefined4 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 0x10)
                        );
    if (iVar2 == 0) {
      FUN_0232a480();
      FUN_02329bd8(0xc);
      return;
    }
    if (*(int *)(DAT_0232ba78 + 0x38) == 0) {
      FUN_0232bd8c();
    }
  }
  return;
}

