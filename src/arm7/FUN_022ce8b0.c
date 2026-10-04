// decomp: module=arm7 addr=0x022ce8b0 name=FUN_022ce8b0
// flags: -O4,s -noThumb
// arm7 wireless-message dispatcher. Byte-exact on mwccarm 2.0/sp2p2, sp2p3
// and sp2p4 ONLY - not on 2.0/sp1..sp2. The discriminator is case 0x182's
// (s64)(int)x * 0x82ea: sp2p2+ folds the constant's zero high word out of the
// 64-bit multiply (umull + asr + one mla, as the ROM has); sp1..sp2 emit an
// extra `mla` against a zero register. Size is the untruncated 0x1194 (Ghidra
// stops at 0x114c, before this function's 72-byte trailing pool).
//   python tools/match.py --c src/arm7/FUN_022ce8b0.c --func FUN_022ce8b0 \
//     --addr 0x022ce8b0 --size 0x1194 --module arm7 --version 2.0/sp2p2

typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned long long undefined8;
typedef unsigned char byte;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ulonglong;
typedef signed long long longlong;
typedef unsigned char bool;
#define false 0
#define true 1

#define DAT_022cf72c 0x023180dc
#define DAT_022cf730 0x023190dc
#define DAT_022cf734 0x00000182
#define DAT_022cf738 0x02318164
#define DAT_022cf73c ((ushort *)0x02ffff98)
#define DAT_022cf740 ((ushort *)0x00008002)
#define DAT_022cf744 0x000005e4
#define DAT_022cf748 0x038071d8
#define DAT_022cf74c 0x000082ea
#define DAT_022cf750 ((ushort *)0x02302e54)
#define DAT_022cf754 0x00008001
#define DAT_022cf758 0x0000ffff
#define DAT_022cf75c 0x03807204
#define DAT_022cf760 ((ushort *)0x02302dc0)
#define DAT_022cf764 ((volatile ushort *)0x048080f8)
#define DAT_022cfa38 ((ushort *)0x02302eec)
#define DAT_022cfa3c 0x00008003
#define DAT_022cfa40 0x00007ffe

extern byte G_023190dc[];
extern byte G_023180dc[];

extern int FUN_022ce2c4();
extern void FUN_022ce538();
extern short FUN_022ce5b4();
extern void FUN_022ce658(void);
extern undefined4 *FUN_022ce718(void);
extern void FUN_022ce784(void);
extern void FUN_022ce884(unsigned short v);
extern int FUN_022cfa44();
extern uint FUN_022cfa7c(int a);
extern void FUN_022cfa90(void);
extern void FUN_022cfb24();
extern void FUN_022cfc48();
extern int FUN_022d3bd4(void);
extern int FUN_022d5540(int a, unsigned short b);
extern void FUN_022d5870(unsigned short mask);
extern void FUN_022d5a64(unsigned short index, unsigned int a1, unsigned short *chunk, unsigned int len, void *ctx);

extern void func_037c9920();
extern int func_037c9e90();
extern void func_037c9f1c();
extern ulonglong func_037caa3c();
extern void func_037cacfc();
extern void func_037cade0();
extern int func_037cb520();
extern void func_037cb534();
extern void func_037cb774();
extern int func_037cb78c();
extern void func_037cb820();
extern void func_037cb8b4();
extern uint func_037d1464();
extern void *func_037d14bc();






void FUN_022ce8b0(void)

{
  ushort uVar1;
  ushort uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  unsigned long new_var;
  void *msg;
  int iVar5;
  undefined2 *puVar6;
  undefined4 uVar7;
  ushort *puVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  ushort uVar12;
  int extraout_r1;
  uint uVar13;
  undefined1 uVar14;
  uint uVar15;
  ushort *in_r3;
  void *ctx;
  int iVar16;
  ushort *puVar17;
  uint uVar18;
  ushort *unaff_r8;
  ushort *puVar19;
  uint uVar20;
  uint uVar21;
  bool bVar22;
  bool bVar23;
  undefined8 uVar24;
  void *local_2c;
  byte local_34[6];
  uint uVar8;
  byte *qbase;
  uint min184;

  qbase = G_023180dc;
  do {
    while( true ) {
        func_037c9f1c(qbase + 0x28,&local_2c,1);
        msg = local_2c;
        if (msg == (void *)0x0) {
          func_037c9920();
          goto exit;
        }
        uVar12 = *(ushort *)((int)msg + 0xc);
        uVar1 = uVar12 & 0xff00;
        uVar2 = uVar12 & 0xff;
        uVar21 = uVar2;
        if ((uVar1 == 0 || uVar1 == 0x100) && ((uVar21 & 0x80) != 0)) break;
        goto release;
    }
    if (*(int *)(G_023190dc + 0x54c) == 0) continue;
    unaff_r8 = *(ushort **)(G_023190dc + 0x550);
    if (*unaff_r8 == 1) continue;
    switch (*(volatile ushort *)((int)msg + 0xc)) {
        case 0x84:
          puVar6 = (undefined2 *)func_037d14bc();
          *puVar6 = 0x80;
          puVar6[1] = 0;
          puVar6[2] = 0x13;
          func_037d1464();
          break;
        case 0x85: {
          int i85;
          uint found85;
          int irq85;
          uint slot85;
          if (*unaff_r8 == 7 || *unaff_r8 == 9) {
            func_037cb8b4((int)msg + 0x10,local_34,6);
            found85 = 0;
            for (i85 = 0; i85 < 0xf; i85 = i85 + 1) {
              int offset85;

              irq85 = func_037cb520();
              slot85 = i85 + 1;
              if (((uint)unaff_r8[0xc1] & 1 << slot85) != 0) {
                offset85 = i85 * 6;
                if (local_34[0] == *(byte *)((int)unaff_r8 + offset85 + 0x128) &&
                    local_34[1] == *(byte *)((int)unaff_r8 + offset85 + 0x129) &&
                    local_34[2] == *(byte *)((int)unaff_r8 + offset85 + 0x12a) &&
                    local_34[3] == *(byte *)((int)unaff_r8 + offset85 + 0x12b) &&
                    local_34[4] == *(byte *)((int)unaff_r8 + offset85 + 0x12c) &&
                    local_34[5] == *(byte *)((int)unaff_r8 + offset85 + 0x12d)) {
                  found85 = slot85 & 0xffff;
                  uVar13 = ~(1 << found85);
                  unaff_r8[0xc1] = *(volatile ushort *)(unaff_r8 + 0xc1) & uVar13;
                  unaff_r8[0x43] = unaff_r8[0x43] & uVar13;
                  *(ulonglong *)(unaff_r8 + found85 * 4 + 0x39c) = 0;
                  func_037cb820((byte *)(unaff_r8 + 0x94) + offset85,0,6);
                  func_037cb534(irq85);
                  break;
                }
              }
              func_037cb534(irq85);
            }
            if (found85 != 0) {
              puVar6 = (undefined2 *)func_037d14bc();
              *puVar6 = 8;
              puVar6[1] = 0;
              puVar6[4] = 9;
              puVar6[9] = *(undefined2 *)((int)msg + 0x16);
              puVar6[8] = (short)found85;
              func_037cb8b4((int)msg + 0x10,puVar6 + 5,6);
              puVar6[0x16] = unaff_r8[0x18];
              puVar6[0x17] = unaff_r8[0x19];
              func_037d1464(puVar6);
              if (*(int *)(unaff_r8 + 6) == 1) {
                FUN_022d5870(1 << found85 & 0xffff);
              }
            }
          }
          else {
            i85 = 0;
            irq85 = func_037cb520();
            if (unaff_r8[0xc1] == 0) {
              func_037cb534(irq85);
            }
            else {
              if (*(int *)(unaff_r8 + 6) == 1) {
                *(int *)(unaff_r8 + 6) = 0;
                i85 = 1;
                FUN_022d3bd4();
                FUN_022ce658();
              }
              unaff_r8[0xc1] = 0;
              unaff_r8[0x43] = 0;
              *(int *)(unaff_r8 + 10) = 0;
              *(int *)(unaff_r8 + 8) = 0;
              *(int *)(unaff_r8 + 0xe) = 0;
              *(int *)(unaff_r8 + 0xcc) = 0;
              unaff_r8[0xcb] = 0;
              func_037cb820(unaff_r8 + 0xce,0,0x50);
              FUN_022ce784();
              unaff_r8[0x61] = 0;
              *unaff_r8 = 3;
              func_037cb534(irq85);
              puVar6 = (undefined2 *)func_037d14bc();
              *puVar6 = 0xc;
              puVar6[1] = 0;
              puVar6[4] = 9;
              puVar6[6] = *(undefined2 *)((int)msg + 0x16);
              puVar6[5] = unaff_r8[0xc4];
              func_037cb8b4(unaff_r8 + 0xc5,puVar6 + 8,6);
              puVar6[0xb] = unaff_r8[0x18];
              puVar6[0xc] = unaff_r8[0x19];
              func_037d1464(puVar6);
              if (i85 != 0) {
                FUN_022d5870(1);
              }
            }
          }
          break;
        }
        case 0x86:
          uVar12 = *(ushort *)((int)msg + 0x16);
          uVar15 = (uint)uVar12;
          if ((uVar15 != 0) && (uVar15 < 0x10)) {
            if (unaff_r8[0x7b] == 0) {
              puVar10 = FUN_022ce718();
              if (puVar10 == (undefined4 *)0x0) {
                iVar5 = 0;
              }
              else {
                in_r3 = (ushort *)0x22;
                *puVar10 = 0x22;
                func_037cb8b4((int)msg + 0x10,puVar10 + 1,6);
                iVar5 = func_037c9e90(DAT_022cf738,puVar10,0);
              }
              if (iVar5 == 0) {
                puVar6 = (undefined2 *)func_037d14bc();
                *puVar6 = 0x80;
                puVar6[1] = 8;
                puVar6[2] = 0x16;
                puVar6[3] = 0x22;
                func_037d1464();
              }
            }
            else {
              uVar7 = func_037cb520();
              unaff_r8[0xc1] = unaff_r8[0xc1] | (1 << uVar15);
              unaff_r8[0x43] = unaff_r8[0x43] & ~(1 << uVar15);
              uVar24 = func_037caa3c();
              in_r3 = unaff_r8 + 0x94;
              *(ulonglong *)(unaff_r8 + uVar15 * 4 + 0x39c) = uVar24 | 1;
              iVar16 = uVar15 - 1;
              func_037cb8b4((int)msg + 0x10,(byte *)in_r3 + iVar16 * 6,6);
              func_037cb534(uVar7);
              in_r3 = unaff_r8 + 0xfc;
              func_037cb774(1,in_r3 + uVar15 * 8,0x10);
              puVar6 = (undefined2 *)func_037d14bc();
              *puVar6 = 8;
              puVar6[1] = 0;
              puVar6[4] = 7;
              func_037cb8b4((int)msg + 0x10,puVar6 + 5,6);
              puVar6[8] = uVar12;
              func_037cb78c((int)msg + 0x22,puVar6 + 10,0x18);
              puVar6[0x16] = unaff_r8[0x18];
              puVar6[0x17] = unaff_r8[0x19];
              func_037d1464(puVar6);
            }
          }
          break;
        case 0x87:
          puVar6 = (undefined2 *)func_037d14bc();
          *puVar6 = 0x80;
          puVar6[1] = 0;
          puVar6[2] = 0x12;
          func_037d1464();
          break;
        case 0x88:
          puVar6 = (undefined2 *)func_037d14bc();
          *puVar6 = 0x80;
          puVar6[1] = 0;
          puVar6[2] = 0x11;
          func_037d1464();
          break;
        case 0x89:
          break;
        case 0x8a:
          break;
        case 0x8b:
          if (unaff_r8[0x61] != 0) {
            puVar6 = (undefined2 *)func_037d14bc();
            *puVar6 = 0xc;
            puVar6[1] = 0;
            puVar6[4] = 8;
            func_037d1464();
          }
          break;
        case 0x8c:
          if (unaff_r8[0x61] != 0) {
            puVar6 = (undefined2 *)func_037d14bc();
            *puVar6 = 8;
            puVar6[1] = 0;
            puVar6[4] = 2;
            func_037d1464();
          }
          break;
        case 0x8d:
          uVar15 = FUN_022cfa7c((uint)*(byte *)((int)msg + 0x1f));
          uVar15 = uVar15 ^ (uint)*DAT_022cf73c << 1;
          *DAT_022cf73c = uVar15 ^ (uVar15 >> 0x10);
          if (*unaff_r8 == 8 || *unaff_r8 == 10) {
            if (unaff_r8[0x5d] != *(ushort *)((int)msg + 0x44)) {
              puVar10 = FUN_022ce718();
              if (puVar10 == (undefined4 *)0x0) {
                iVar5 = 0;
              }
              else {
                *puVar10 = 0x25;
                in_r3 = DAT_022cf740;
                puVar10[1] = 1;
                uVar7 = DAT_022cf738;
                puVar10[2] = in_r3;
                iVar5 = func_037c9e90(uVar7,puVar10,0);
              }
              if (iVar5 == 0) {
                puVar6 = (undefined2 *)func_037d14bc();
                *puVar6 = 0x80;
                puVar6[1] = 8;
                puVar6[2] = 0x16;
                puVar6[3] = 0x25;
                func_037d1464();
              }
            }
            else {
              if (*(ushort *)(*(int *)(G_023190dc + 0x550) + 0xc2) != 0) {
                puVar6 = (undefined2 *)func_037d14bc();
                *puVar6 = 0x80;
                puVar6[1] = 0;
                puVar6[2] = 0x10;
                puVar6[3] = *(undefined2 *)((int)msg + 0x44);
                puVar6[4] = *unaff_r8;
                uVar12 = *(ushort *)((int)msg + 0x16);
                puVar6[5] = uVar12;
                if (uVar12 <= 0x80) {
                  func_037cb78c((int)msg + 0x3c,puVar6 + 6,uVar12 + 1 & 0xfffffffe);
                }
                func_037d1464(puVar6);
              }
            }
          }
          break;
        case 0x180:
          if (*(int *)(unaff_r8 + 8) != 0) {
        iVar5 = FUN_022cfa7c((uint)*(byte *)((int)msg + 0x1f));
        FUN_022ce538(iVar5);
        iVar5 = FUN_022ce5b4();
        unaff_r8[0x5e] = (ushort)iVar5;
        iVar5 = FUN_022ce2c4((uchar *)((int)msg + 0x2e));
        if ((iVar5 != 1) && (*(ushort *)((int)msg + 0x16) <= DAT_022cf744)) {
          unaff_r8[0x57] = unaff_r8[0x57] ^ 1;
          iVar5 = *(int *)(unaff_r8 + (uint)unaff_r8[0x57] * 2 + 0x58);
          func_037cb8b4((int)msg + 0x10,iVar5,*(ushort *)((int)msg + 0x16) + 0x2d & 0xfffffffe);
          func_037cb8b4((int)msg + 0x28,iVar5 + 0x18,6);
          func_037cb8b4((int)msg + 0x2e,iVar5 + 0x1e,6);
          puVar6 = (undefined2 *)func_037d14bc();
          *puVar6 = 0x11;
          puVar6[1] = 0;
          puVar6[2] = 0xf;
          *(int *)(puVar6 + 4) = iVar5;
          func_037d1464();
        }
          }
          break;
        case 0x182:
      uVar15 = FUN_022cfa7c((uint)*(byte *)((int)msg + 0x1f));
      if (unaff_r8[0x5f] > uVar15) {
        unaff_r8[0x5f] = (ushort)uVar15;
      }
      if (*(int *)(unaff_r8 + 6) != 0) {
        if (unaff_r8[0x30] == 1) {
          unaff_r8[0x30] = 0;
        }
        uVar12 = unaff_r8[0x47];
        unaff_r8[0x38] = unaff_r8[0x38] ^ 1;
        ctx = *(void **)(unaff_r8 + (uint)unaff_r8[0x38] * 2 + 0x3a);
        uVar15 = *(ushort *)((int)msg + 0x16) + 0x30;
        if (unaff_r8[0x39] < uVar15) {
          uVar15 = unaff_r8[0x39];
        }
        func_037cb8b4((int)msg + 0x10,ctx,uVar15);
        uVar7 = func_037cb520();
        uVar8 = 0;
        if (unaff_r8[0x42] == 1) {
          uVar8 = 1;
          func_037cade0(DAT_022cf748);
        }
        unaff_r8[0x42] = 1;
        unaff_r8[0x41] = ((ushort *)ctx)[0x5];
        uVar2 = ((ushort *)msg)[0xc];
        uVar18 = (uVar2 & 0x2000) != 0;
        unaff_r8[0x48] = (ushort)uVar18;
        uVar15 = DAT_022cf74c;
        uVar3 = (ulonglong)uVar15 *
                (longlong)(int)
                ((((uint)((ushort *)ctx)[0x5] -
                    (uint)((ushort *)ctx)[0x6] & 0xffff) + 0x80) * 0x10);
        uVar4 = uVar3 >> 6;
        in_r3 = DAT_022cf750;
        ((void (*)(void *, ulonglong, void *, void *))func_037cacfc)
          ((void *)DAT_022cf748,uVar4 >> 10,(void *)DAT_022cf750,0);
        iVar5 = (uVar2 & 0x2800) == 0x2800;
        iVar16 = (uVar2 & 0x6000) == 0x6000;
        if (iVar16 != 0) {
          unaff_r8[0x45] = 0;
        }
        unaff_r8[0x47] = (ushort)(iVar5 != 0);
        unaff_r8[0x46] = (ushort)(iVar16 != 0);
        if (uVar18 != 0) {
          iVar5 = ((ushort *)ctx)[0x16] - 0x66;
          iVar5 = (int)(iVar5 + ((uint)(iVar5 >> 1) >> 0x1e)) >> 2;
          iVar5 = iVar5 - 0x20;
          if (iVar5 >= 0) {
          if (0x200 < iVar5) {
            iVar5 = 0x200;
          }
          if (iVar5 != unaff_r8[0x19]) {
            FUN_022ce884(iVar5 & 0xffff);
          }
          }
        }
        func_037cb534(uVar7);
        if (uVar8 != 0) {
          if (uVar12 == 1) {
            FUN_022d5540(uVar8,0);
          }
          puVar6 = (undefined2 *)func_037d14bc();
          *puVar6 = 0xe;
          puVar6[1] = 9;
          puVar6[2] = 0xd;
          *(undefined4 *)(puVar6 + 4) = 0;
          func_037d1464();
        }
        if (uVar18 == 0) {
          if (((ushort *)ctx)[0x3] < 2) goto switchD_022ce940_default;
          unaff_r8[0x2f] = (ushort)((((ushort *)ctx)[0x18] & 0x8000) != 0);
        }
        else {
          func_037cb8b4((int)msg + 0x28,((ushort *)ctx + 0xc),6);
          func_037cb8b4((int)msg + 0x2e,((ushort *)ctx + 0xf),6);
          if ((uint)((ushort *)ctx)[0x3] < 2U) goto case182_small;
            ((ushort *)ctx)[0x3] = ((ushort *)ctx)[0x3] - 2;
            unaff_r8[0x2f] = (ushort)((((ushort *)ctx)[0x18] & 0x8000) != 0);
            puVar6 = (undefined2 *)func_037d14bc();
            *puVar6 = 0xe;
            puVar6[1] = 0;
            puVar6[2] = 0xc;
            *(void **)(puVar6 + 4) = ctx;
            func_037d1464();
            in_r3 = (ushort *)(uint)((ushort *)ctx)[0x3];
            if (in_r3 != (ushort *)0x0) {
              FUN_022d5a64(0,(uint)((ushort *)ctx)[0x18],((ushort *)ctx + 0x19),
                           (uint)in_r3,ctx);
            }
            goto case182_join;
case182_small:
            ((ushort *)ctx)[0x3] = 0;
            unaff_r8[0x2f] = 0;
            puVar6 = (undefined2 *)func_037d14bc();
            *puVar6 = 0xe;
            puVar6[1] = 0xe;
            puVar6[2] = 0xc;
            *(void **)(puVar6 + 4) = ctx;
            func_037d1464();
case182_join:
          uVar20 = *(uint *)(unaff_r8 + 0x3de);
          uVar21 = *(uint *)(unaff_r8 + 0x3dc);
          if (uVar20 != 0 || uVar21 != 0) {
            uVar24 = func_037caa3c();
            *(ulonglong *)(unaff_r8 + 0x39c) = uVar24 | 1;
          }
        }
      }
          break;
        case 0x184: {
          ushort *base184;
          int j184;
          ushort index184;
          uint mask184;
          ushort counter184;
          uint bits184;
          int flag184;
          ulonglong now184;
          int res184;
          iVar5 = *(int *)(unaff_r8 + 6);
          flag184 = 0;
          if (iVar5 == 0) break;
          if ((*(ushort *)((int)msg + 0x12) != 0) ||
             ((unaff_r8[0x33] == 1) && (*(ushort *)((int)msg + 0x10) != 0))) {
            FUN_022cfa90();
            break;
          }
            if (unaff_r8[0x33] != 0) {
              unaff_r8[0x33] = 0;
            }
            base184 = *(ushort **)(unaff_r8 + (uint)unaff_r8[0x38] * 2 + 0x3a);
            uVar15 = (uint)*(ushort *)((int)msg + 0x16) *
                     (uint)*(ushort *)((int)msg + 0x14) + 10;
            if (unaff_r8[0x39] < uVar15) {
              uVar15 = (uint)unaff_r8[0x39];
            }
            func_037cb8b4((int)msg + 0x10,base184,uVar15);
            ctx = *(void **)(G_023190dc + 0x550);
            min184 = ((ushort *)ctx)[0x5f];
            if ((*base184 == 0) && (*(ushort *)((int)msg + 0x14) >= 1)) {
              puVar9 = (ushort *)((byte *)msg + 0x1a);
              for (j184 = 0; j184 < (int)(uint)*(ushort *)((int)msg + 0x14); j184 = j184 + 1
                  ) {
                uVar8 = FUN_022cfa7c((uint)*((byte *)puVar9 +
                                             (uint)*(ushort *)((int)msg + 0x16) * j184 + 3));
                if (uVar8 < min184) {
                  min184 = uVar8;
                }
              }
              ((ushort *)ctx)[0x5f] = (ushort)min184;
            }
            now184 = func_037caa3c() | 1;
            bits184 = *base184;
            puVar19 = base184 + 5;
            counter184 = 0;
            for (; counter184 < base184[2];
                 counter184++,
                 puVar19 = (ushort *)((byte *)puVar19 + base184[3])) {
              index184 = puVar19[2];
              uVar13 = *puVar19;
              if (index184 < 1 || index184 > 0xf) continue;
              if (uVar13 >= 2 && uVar13 != 0xffff) {
                uVar13 = (ushort)(uVar13 - 2);
                *puVar19 = (ushort)uVar13;
                unaff_r8[0x43] = unaff_r8[0x43] | (1 << index184);
                *(ulonglong *)(unaff_r8 + index184 * 4 + 0x39c) = now184;
                if (uVar13 != 0) {
                  FUN_022d5a64(index184,(uint)puVar19[4],puVar19 + 5,uVar13,base184);
                }
              }
              else if (uVar13 == 0) {
                uVar4 = *(ulonglong *)(unaff_r8 + index184 * 4 + 0x39c);
                mask184 = 1 << index184;
                bits184 = bits184 | (1 << index184);
                uVar3 = *(ulonglong *)(unaff_r8 + 0x3dc);
                if (uVar3 != 0 && uVar4 != 0 && now184 - uVar4 > uVar3) {
                  puVar10 = FUN_022ce718();
                  ((ulonglong *)(unaff_r8 + 0x39c))[index184] = 0;
                  if (puVar10 != (undefined4 *)0x0) {
                    *puVar10 = 0x25;
                    puVar10[1] = mask184;
                    puVar10[2] = DAT_022cf754;
                    res184 = func_037c9e90(DAT_022cf738,puVar10,0);
                  } else {
                    res184 = 0;
                  }
                  if (res184 == 0) {
                  puVar6 = (undefined2 *)func_037d14bc();
                  *puVar6 = 0x80;
                  puVar6[1] = 8;
                  puVar6[2] = 0x16;
                  puVar6[3] = 0x25;
                  func_037d1464();
                  }
                }
              }
            }
            FUN_022d5540(0,(ushort)bits184);
            if (*base184 != 0) {
              flag184 = 1;
            }
            puVar6 = (undefined2 *)func_037d14bc();
            *puVar6 = 0xe;
            puVar6[1] = 0;
            puVar6[2] = 0xb;
            *(ushort **)(puVar6 + 4) = base184;
            func_037d1464();
            unaff_r8[0x38] = unaff_r8[0x38] ^ 1;
            uVar7 = func_037cb520();
            if (flag184 == 0) {
              *(short *)(unaff_r8 + 0x31) = *(short *)(unaff_r8 + 0x31) - 1;
            }
            if (0 < *(short *)(unaff_r8 + 0x32)) {
              *(short *)(unaff_r8 + 0x32) = *(short *)(unaff_r8 + 0x32) - 1;
            }
            iVar5 = (*(short *)(unaff_r8 + 0x31) > 0) &&
                    (*(short *)(unaff_r8 + 0x32) > 0);
            func_037cb534(uVar7);
            if (iVar5 != 0) {
              if (flag184 == 1) {
                uVar15 = (uint)*(ushort *)((int)msg + 0x10);
              }
              else {
                uVar15 = DAT_022cf758;
              }
              if (unaff_r8[0x22] != 0) {
                func_037cade0(DAT_022cf75c);
                in_r3 = DAT_022cf760;
                func_037cacfc(DAT_022cf75c,*(undefined4 *)(unaff_r8 + 0x24),
                                *(undefined4 *)(unaff_r8 + 0x26),DAT_022cf760,uVar15);
              }
              else {
                FUN_022cfb24(uVar15);
              }
            }
          break;
        }
        case 0x185:
        iVar16 = 0;
        if (*(int *)(unaff_r8 + 6) != 0) {
          if (*(ushort *)((int)msg + 0xe) == 0) {
            iVar5 = 1;
            uVar12 = DAT_022cf764[0];
            uVar1 = DAT_022cf764[1];
            uVar2 = DAT_022cf764[0];
            if (uVar12 > uVar2) {
              uVar1 = DAT_022cf764[1];
            }
            uVar15 = (uint)uVar1 << 0xc | (int)(uint)uVar2 >> 4;
            uVar12 = unaff_r8[0x41];
            if ((short)((ushort)uVar15 - uVar12) <= 0)
              goto switchD_022ce940_default;
          }
          else {
            iVar5 = 0;
          }
          uVar11 = func_037cb520();
          uVar7 = DAT_022cf748;
          if (unaff_r8[0x42] == 0) {
            func_037cb534(uVar11);
          }
          else {
            unaff_r8[0x42] = 0;
            uVar12 = unaff_r8[0x48];
            uVar8 = uVar12;
            func_037cade0(uVar7);
            func_037cb534(uVar11);
            in_r3 = (ushort *)(uint)unaff_r8[0x46];
            uVar14 = 1;
            if ((in_r3 != (ushort *)0x0) &&
               ((iVar5 != 0 ||
                (((uint)*(ushort *)((int)msg + 0x3e) & 1 << unaff_r8[0xc4]) == 0)))) {
              uVar14 = 0;
            }
            if (in_r3 != (ushort *)0x0) {
              unaff_r8[0x46] = 0;
            }
            if (unaff_r8[0x47] != 0) {
              unaff_r8[0x47] = 0;
              iVar16 = FUN_022d5540(iVar5,(ushort)(uVar14 != 0));
            }
            if (uVar8 != 0) {
              puVar6 = (undefined2 *)func_037d14bc();
              *puVar6 = 0xe;
              if (iVar5 != 0) {
                puVar6[1] = 9;
              }
              else if (((uint)*(ushort *)((int)msg + 0x3e) & 1 << unaff_r8[0xc4]) != 0) {
                puVar6[1] = 0xf;
              }
              else {
                puVar6[1] = 0;
              }
              puVar6[2] = 0xd;
              *(undefined4 *)(puVar6 + 4) = 0;
              if (iVar5 == 0) {
                puVar6[6] = *(undefined2 *)((int)msg + 0x1c);
                puVar6[7] = *(undefined2 *)((int)msg + 0x1e);
                func_037cb8b4((int)msg + 0x28,puVar6 + 8,6);
                func_037cb8b4((int)msg + 0x2e,puVar6 + 0xb,6);
                puVar6[0xe] = *(undefined2 *)((int)msg + 0x3a);
                puVar6[0xf] = *(undefined2 *)((int)msg + 0x3c);
                puVar6[0x10] = *(undefined2 *)((int)msg + 0x3e);
              }
              uVar15 = func_037d1464(puVar6);
              if (uVar12 != 0) {
                if (!(iVar16 != 1 && unaff_r8[0x2f] != 0)) {
                  if (unaff_r8[0x23] != 0) {
                  func_037cade0(DAT_022cf75c);
                  in_r3 = DAT_022cfa38;
                  func_037cacfc(DAT_022cf75c,*(undefined4 *)(unaff_r8 + 0x28),
                                  *(undefined4 *)(unaff_r8 + 0x2a),DAT_022cfa38,0);
                  }
                  else {
                  FUN_022cfc48();
                  }
                }
                else {
                  unaff_r8[0x2f] = 0;
                  unaff_r8[0x30] = 1;
                  unaff_r8[0x44] = 0;
                }
              }
            }
          }
        }
          break;
        case 0x186:
          if (unaff_r8[0x3e6] == 1 &&
              *(ushort *)((int)msg + 0x10) == 0x20) {
            uVar7 = func_037cb520();
            func_037cade0(DAT_022cf748);
            unaff_r8[0x42] = 0;
            func_037cb534(uVar7);
            unaff_r8[0x45] = 0;
            FUN_022d5540(1,0);
            puVar6 = (undefined2 *)func_037d14bc();
            *puVar6 = 0x80;
            puVar6[1] = 0;
            puVar6[2] = 0x17;
            puVar6[3] = 1;
            func_037d1464();
          }
          else {
            puVar10 = FUN_022ce718();
            uVar7 = DAT_022cfa3c;
            if (puVar10 == (undefined4 *)0x0) {
              iVar5 = 0;
            }
            else {
              *puVar10 = 0x25;
              puVar10[2] = uVar7;
              uVar12 = *unaff_r8;
              if (uVar12 == 9 || uVar12 == 7) {
                puVar10[1] = DAT_022cfa40;
              }
              else if (uVar12 == 10 || uVar12 == 8) {
                puVar10[1] = 1;
              }
              iVar5 = func_037c9e90(DAT_022cf738,puVar10,0);
            }
            if (iVar5 == 0) {
              puVar6 = (undefined2 *)func_037d14bc();
              *puVar6 = 0x80;
              puVar6[1] = 8;
              puVar6[2] = 0x16;
              puVar6[3] = 0x25;
              func_037d1464();
            }
          }
          break;
        default:
          break;
    }
switchD_022ce940_default:
    FUN_022cfa44(msg);
    continue;
release:
    func_037c9e90(qbase + 0x58,msg,1);
  } while( true );
exit:
  return;
}
