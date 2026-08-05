// decomp: module=unk_autoload_0 addr=0x02320000 name=FUN_02320000
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x190 (Ghidra's cache says 0x166 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=77
// verify:  python tools/match.py --c <file> --func FUN_02320000 --addr 0x02320000 --size 0x190 --module unk_autoload_0 --version 2.0/sp1


void FUN_02320000(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_1c [8];
  
  FUN_0232d108(DAT_02320168);
  FUN_02331554();
  FUN_02331c10();
  FUN_02331d84();
  FUN_02322d8c();
  FUN_02331dd4(DAT_0232016c);
  FUN_02336234();
  FUN_02331ea8(DAT_0232016c,DAT_02320170,0,DAT_02320174,0);
  FUN_02338c74();
  FUN_0233702c(DAT_02320178);
  FUN_0233746c(0,0x6800000,0xa4000);
  FUN_02337194();
  FUN_0233746c(0xc0,0x7000000,0x400);
  FUN_0233746c(0,0x5000000,0x400);
  FUN_02330728(1,DAT_0232017c);
  FUN_023307d4(1);
  *DAT_02320180 = 1;
  FUN_0233206c();
  FUN_02336310(1);
  FUN_02339908();
  FUN_02322530();
  FUN_0232d3c8();
  FUN_02322554();
  FUN_0232270c();
  FUN_0232d260(0x10000);
  FUN_02331ef0(DAT_0232016c);
  FUN_02322c18();
  FUN_0232d168();
  FUN_02322940();
  FUN_02321be0();
  FUN_02321c70();
  FUN_02320938();
  FUN_023202b0(0);
  *(undefined4 *)(DAT_02320184 + 4) = 0;
  iVar4 = 2;
  bVar1 = true;
  FUN_0233219c(DAT_02320188);
  FUN_02322c1c();
  FUN_02338df8(auStack_1c,*DAT_0232018c,DAT_0232018c[1],*(undefined1 *)(DAT_0232018c + 2),
               *(undefined1 *)((int)DAT_0232018c + 5),DAT_0232018c[3],DAT_0232018c[4],
               *(undefined1 *)(DAT_0232018c + 5),*(undefined1 *)((int)DAT_0232018c + 0xb));
  FUN_02338cbc(auStack_1c);
  FUN_02321310();
  while( true ) {
    piVar2 = (int *)FUN_02320b9c();
    FUN_023215d0();
    FUN_02321770(piVar2);
    piVar2 = FUN_023215e4();
    FUN_02321770(piVar2);
    FUN_02322b90();
    iVar3 = FUN_0232d168();
    if (iVar3 == 1) break;
    if (1 < iVar3) {
      FUN_023202b0();
      bVar1 = true;
      iVar4 = 0;
    }
    if ((bVar1) && (iVar4 != 0)) {
      if (iVar4 == 2) {
        FUN_0232d250();
      }
      bVar1 = false;
    }
    if (((iVar4 == 1) || (iVar4 == 2)) || (iVar4 == 3)) {
      FUN_0232d238();
    }
    thunk_FUN_0232e7b0();
  }
  return;
}

