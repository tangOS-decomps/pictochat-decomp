// decomp: module=unk_autoload_0 addr=0x0232f7dc name=FUN_0232f7dc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x70, thumb
// triage: noise=7 statements=26
// verify:  python tools/match.py --c <file> --func FUN_0232f7dc --addr 0x0232f7dc --size 0x70 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232f7dc(undefined4 *param_1)

{
  bool bVar1;
  ushort *o;
  char *t;
  
  bVar1 = false;
  o = (ushort *)FUN_0232e188((ushort *)(param_1 + 1),(char *)0x0);
  while (o != (ushort *)0x0) {
    for (t = (char *)FUN_0232e188(o,(char *)0x0); t != (char *)0x0; t = (char *)FUN_0232e188(o,t)) {
      if (*(code **)(t + 0xc) != (code *)0x0) {
        (**(code **)(t + 0xc))
                  (t + 0x20,*(undefined4 *)(t + 8),*(undefined4 *)(t + 0x10),
                   *(undefined4 *)(t + 0x14));
        bVar1 = true;
      }
    }
    FUN_0232e13c(param_1 + 1,o);
    o = (ushort *)FUN_0232e188((ushort *)(param_1 + 1),(char *)0x0);
  }
  FUN_0232e734(*param_1,3);
  if (bVar1) {
    FUN_0232f8e8();
  }
  FUN_0232f8c0(param_1);
  return;
}

