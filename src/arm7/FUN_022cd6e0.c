// decomp: module=arm7 addr=0x022cd6e0 name=FUN_022cd6e0
// flags: -O4,s
// THUMB (size 0xce is not a multiple of 4).
#pragma thumb on

// Sets bit 1 of the PMIC/codec register at device 0x86 offset 0x00 to the low
// bit of the caller's request, and - only when that bit actually changes -
// re-programs the two 3-byte parameter blocks at offsets 0x10 and 0x50 through
// the "on" (FUN_022cdbfc) or "off" (FUN_022cdb44) transform.
//
// Every write goes out as the fixed FUN_022cd6b0 / FUN_022cd6bc(6, offset) /
// FUN_022cd6c8(buf, len) / FUN_022cd6d4 sequence, with FUN_022cd194(0x8000)
// gating the bus first.  If the bit already has the requested value the
// function returns without touching anything.
//
// The `lsl #30 / lsr #31` read and `bic #2 / orr (v & 1) << 1` write of the
// status byte are a 1-bit bitfield at bit 1, not hand-written shifts.
// The trailing `reserved` halfword and the params-before-reg declaration order
// are what put reg at sp+0 and params at sp+4 (mwcc lays the two 8-byte frame
// slots out in reverse declaration order once Reg is 4 bytes wide).

typedef struct Reg {
    unsigned short unused0 : 1;
    unsigned short enable : 1;
    unsigned short rest : 14;
    unsigned short reserved;
} Reg;

extern void FUN_022cd194(int mask);
extern void FUN_022cdca8(int dev, int offset, void *buf, int len);
extern void FUN_022cd6b0(void);
extern void FUN_022cd6bc(int cmd, int offset);
extern void FUN_022cd6c8(void *buf, int len);
extern void FUN_022cd6d4(void);
extern void FUN_022cdb44(unsigned char *buf);
extern void FUN_022cdbfc(unsigned char *buf);

void FUN_022cd6e0(unsigned short mode)
{
    unsigned char params[3];
    Reg reg;

    mode &= 1;
    if (mode != 1) {
        return;
    }

    FUN_022cd194(0x8000);
    FUN_022cdca8(0x86, 0, &reg, 1);
    if (reg.enable == mode) {
        return;
    }

    reg.enable = mode;
    FUN_022cd194(0x8000);
    FUN_022cd6b0();
    FUN_022cd6bc(6, 0);
    FUN_022cd6c8(&reg, 1);
    FUN_022cd6d4();

    FUN_022cdca8(0x86, 0x10, params, 3);
    if (mode == 0) {
        FUN_022cdb44(params);
    } else {
        FUN_022cdbfc(params);
    }
    FUN_022cd6b0();
    FUN_022cd6bc(6, 0x10);
    FUN_022cd6c8(params, 3);
    FUN_022cd6d4();

    FUN_022cdca8(0x86, 0x50, params, 3);
    if (mode == 0) {
        FUN_022cdb44(params);
    } else {
        FUN_022cdbfc(params);
    }
    FUN_022cd6b0();
    FUN_022cd6bc(6, 0x50);
    FUN_022cd6c8(params, 3);
    FUN_022cd6d4();
}
