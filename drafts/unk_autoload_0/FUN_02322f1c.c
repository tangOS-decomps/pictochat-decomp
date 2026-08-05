// decomp: module=unk_autoload_0 addr=0x02322f1c name=FUN_02322f1c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x124 (Ghidra's cache says 0x11a - it excludes this function's trailing literal pool), thumb
// triage: noise=8 statements=68
// verify:  python tools/match.py --c <file> --func FUN_02322f1c --addr 0x02322f1c --size 0x124 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322f1c(void)

{
  byte bVar1;
  undefined *puVar2;
  uint extraout_r1;
  undefined4 in_r3;
  int iVar3;
  int *p;
  uint uVar4;
  
  puVar2 = PTR_DAT_02323038;
  uVar4 = 0;
  do {
    p = (int *)(puVar2 + uVar4 * 0x30);
    if (p[9] != 0) {
      if ((short)p[10] == 0) {
        if ((char)p[0xb] == '\0') {
          *(ushort *)((int)p + 0x2a) = (ushort)*(byte *)((int)p + 5);
        }
        bVar1 = *(byte *)(p + 0xb);
        if (bVar1 < 0x11) {
          *(char *)(p + 0xb) = (char)p[0xb] + '\x01';
          iVar3 = (int)*(char *)((int)p + bVar1 + 10);
        }
        else {
          iVar3 = 0x1b;
        }
        if (iVar3 < 0x19) {
          FUN_02323040(uVar4);
          FUN_0232e94c(p);
          FUN_0232fe40(p,uVar4,0,0x60,0,0,in_r3);
          if ((*(byte *)(p + 2) & 1) != 0) {
            FUN_02336018(*(undefined4 *)(PTR_DAT_0232303c + 4),*(undefined1 *)((int)p + 0x2d));
            *(char *)((int)p + 0x2d) = *(char *)((int)p + 0x2d) + '\x01';
            iVar3 = (iVar3 + ((int)(((extraout_r1 & 3) - 2) * 0x1000000) >> 0x18)) * 0x1000000 >>
                    0x18;
            if (iVar3 < 0) {
              iVar3 = 0;
            }
            else if (0x18 < iVar3) {
              iVar3 = 0x18;
            }
          }
          FUN_0232e9ec(p,1,iVar3 << 6);
          if ((*(byte *)(p + 2) & 4) != 0) {
            FUN_0232ea00(p,1,0x28);
          }
        }
        else if (iVar3 == 0x1a) {
          FUN_02323040(uVar4);
          FUN_0232e94c(p);
        }
        else if (iVar3 == 0x19) {
          FUN_02323040(uVar4);
        }
        else if (iVar3 == 0x1b) {
          p[9] = 0;
          FUN_0232e94c(p);
        }
      }
      else {
        *(short *)(p + 10) = (short)p[10] + -1;
      }
    }
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 4);
  *(int *)(PTR_DAT_0232303c + 4) = *(int *)(PTR_DAT_0232303c + 4) + 1;
  return;
}

