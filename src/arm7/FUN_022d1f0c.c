// decomp: module=arm7 addr=0x022d1f0c name=FUN_022d1f0c
// flags: -O4,s -noThumb
//
// Wireless connect request handler (ARM7 side). Validates the connection
// state block at G_023190dc+0x550 and the target BSS descriptor copied into
// +0x54c, acknowledges the request (opcode 0xc), then runs the
// join/auth/assoc helper chain (FUN_022d073c, FUN_022d04f0, FUN_022d08ec,
// FUN_022cfdf8, FUN_022cff10, FUN_022cff88, FUN_022d0080), reporting each
// failure through FUN_022d24b8 or an opcode-0xc indication. On success it
// records the AID and timing parameters, arms the beacon timers and posts
// the "connected" indication (state code 7).
//
// Size is the untruncated 0x5ac (Ghidra's 0x598 omits the trailing pool).
//
// Phrasing that the bytes depend on:
//  - FUN_037c87f4 sits in ARM7 WRAM outside arm7.bin, so its signature is
//    inferred: at its only call site the ROM holds the +0x42 value in r1, so
//    it is passed as a second argument;
//  - the 1-or-random count is a single ternary, so both paths share the u16
//    truncation before the 0xff clamp;
//  - the declaration order of the pointer locals sets the r4-r8 assignment.

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U64(p, o) (*(u64 *)((u8 *)(p) + (o)))

typedef struct ConnMgrD1f0c {
    char pad[0x54c];
    u8 *bss;
    u8 *st;
} ConnMgrD1f0c;

extern ConnMgrD1f0c G_023190dc;

typedef struct Result {
    u16 f0;
    u16 f2;
    u16 err;
    u16 code;
    u16 f8;
} Result;

typedef struct Blk {
    u8 pad0[0x0a];
    u16 fa;
    u16 fc;
    u16 fe;
    u16 f10;
    u16 f12;
    u8 f14[0x18];
    u8 pad2c[0x18];
} Blk;

extern u16 *FUN_037d14bc(void);
extern void FUN_037d1464(u16 *cb);
extern void FUN_037cb8b4(const void *src, void *dst, u32 len);
extern void FUN_037cb774(u16 value, void *dst, u32 len);
extern u32 FUN_037cb520(void);
extern void FUN_037cb534(u32 e);
extern u64 FUN_037caa3c(void);
extern u16 FUN_037c87f4(u32 max, u16 seed);
extern int FUN_022ce3e8(int id, void *buf);
extern Result *FUN_022d073c(void *buf, int a);
extern Result *FUN_022d04f0(void *buf, u16 n);
extern Result *FUN_022d08ec(void *buf);
extern Result *FUN_022cfdf8(void *buf, u16 a, int b, int c);
extern Result *FUN_022cff10(void *buf, int timeout, Blk *blk);
extern Result *FUN_022cff88(void *buf, u8 *mac, u16 a, int timeout);
extern Result *FUN_022d0080(void *buf, u8 *mac, int a, int timeout);
extern u16 FUN_022ce5f0(u8 rate);
extern void FUN_022ce57c(u8 rate);
extern void FUN_022ce7b8(u16 v);
extern void FUN_022ce808(u16 v);
extern void FUN_022d24b8(u16 a, u16 b, u16 c);

void FUN_022d1f0c(u8 *req)
{
    u8 buf[0x200];
    Blk blk;
    u8 mac[6];
    u8 mac2[6];
    u16 *cb;
    Result *res;
    u8 *p = buf;
    u8 *bss;
    u32 e;
    u8 *st;
    u32 e2;
    u32 mask;
    u16 power;

    st = G_023190dc.st;
    bss = G_023190dc.bss;
    if (U16(st, 0) != 2 || (U32(st, 0xc8) & 1)) {
        cb = FUN_037d14bc();
        cb[0] = 0xc;
        cb[1] = 3;
        cb[4] = 6;
        FUN_037d1464(cb);
        return;
    }

    FUN_037cb8b4(*(void **)(req + 4), bss + 0x10, 0xc0);

    if (U16(bss, 0x4c) >= 0x10 && !(bss[0x5b] & 1)) {
        cb = FUN_037d14bc();
        cb[0] = 0xc;
        cb[1] = 0xb;
        cb[4] = 6;
        FUN_037d1464(cb);
        return;
    }

    mask = 1 << U16(bss, 0x46);
    if (!(mask & U16(st, 0x1f4)) || !(((int)mask >> 1) & 0x1fff)) {
        cb = FUN_037d14bc();
        cb[0] = 0xc;
        cb[1] = 6;
        cb[4] = 6;
        FUN_037d1464(cb);
        return;
    }

    cb = FUN_037d14bc();
    cb[0] = 0xc;
    cb[1] = 0;
    cb[4] = 6;
    FUN_037d1464(cb);

    if (U16(st, 0x1ec) == 1) {
        if (U16(bss, 0x3e) & 1)
            U16(st, 0x1ec) = 1;
        else
            U16(st, 0x1ec) = 2;
    } else {
        if (U16(bss, 0x3e) & 2)
            U16(st, 0x1ec) = 2;
        else
            U16(st, 0x1ec) = 1;
    }
    if (U16(bss, 0x3c) & 0x20)
        U16(st, 0x1ee) = 1;
    else
        U16(st, 0x1ee) = 0;
    if (U16(bss, 0x4c) == 0)
        U16(st, 0xe6) = 3;
    else
        U16(st, 0xe6) = 2;

    if (!FUN_022ce3e8(0xc, p))
        return;

    res = FUN_022d073c(p, 0);
    if (res->err != 0) {
        FUN_022d24b8(0x216, res->err, 0);
        return;
    }

    if (U16(bss, 0x4c) < 0x10) {
        u16 seed = U16(bss, 0x42);
        u16 n = seed == 0 ? 1 : FUN_037c87f4(10000, seed) + 1;
        res = FUN_022d04f0(p, n > 0xff ? 0xff : n);
        if (res->err != 0) {
            FUN_022d24b8(0x20b, res->err, 0);
            return;
        }
    }

    res = FUN_022d08ec(p);
    if (res->err != 0) {
        FUN_022d24b8(0x303, res->err, 0);
        return;
    }

    U16(st, 0) = 3;
    power = *(u32 *)(req + 0x20) != 0;
    res = FUN_022cfdf8(p, power, 0, 1);
    if (res->err != 0) {
        FUN_022d24b8(1, res->err, 0);
        return;
    }
    U16(st, 0xc6) = power;

    FUN_037cb8b4(bss + 0x10, &blk, 0x40);
    if (U16(st, 0xe6) == 2) {
        blk.fa = 0x20;
        blk.fc = U32(bss, 0x54);
        blk.fe = U32(bss, 0x54) >> 16;
        blk.f10 = U16(bss, 0x58);
        blk.f12 = 0;
        FUN_037cb8b4(req + 8, blk.f14, 0x18);
    }

    res = FUN_022cff10(p, 2000, &blk);
    if (res->err != 0 || res->code != 0) {
        FUN_022d24b8(3, res->err, res->code);
        return;
    }

    FUN_037cb8b4((u8 *)res + 8, st + 0x18a, 6);
    FUN_037cb8b4(st + 0x18a, mac, 6);
    res = FUN_022cff88(p, mac, U16(req, 0x26), 2000);
    if (res->err == 0xc && res->code == 0x13) {
        cb = FUN_037d14bc();
        cb[0] = 0xc;
        cb[1] = 0xc;
        cb[4] = 6;
        FUN_037d1464(cb);
        return;
    }
    if (res->err != 0 || res->code != 0) {
        FUN_022d24b8(4, res->err, res->code);
        return;
    }

    FUN_037cb8b4(st + 0x18a, mac2, 6);
    res = FUN_022d0080(p, mac2, 1, 2000);
    e = FUN_037cb520();
    if (res->err == 0xc && res->code == 0x13) {
        FUN_037cb534(e);
        cb = FUN_037d14bc();
        cb[0] = 0xc;
        cb[1] = 0xc;
        cb[4] = 6;
        FUN_037d1464(cb);
        return;
    }
    if (res->err != 0 || res->code != 0) {
        FUN_037cb534(e);
        FUN_022d24b8(6, res->err, res->code);
        return;
    }

    U16(st, 0x188) = res->f8;
    U16(st, 0xba) = U16(bss, 0x58);
    FUN_037cb774(1, st + 0x1f8, 0x10);
    {
        int v = U16(bss, 0x12) & 0xff;
        int r = v >> 2;
        u8 rate;
        if (!(v & 2))
            r += 0x19;
        rate = r;
        U16(st, 0xbc) = FUN_022ce5f0(rate);
        FUN_022ce57c(rate);
    }

    e2 = FUN_037cb520();
    U16(st, 0x182) = 1;
    U16(st, 0x86) = 1;
    if (U64(st, 0x7b8) != 0)
        U64(st, 0x738) = FUN_037caa3c() | 1;
    U16(st, 0) = 8;
    FUN_022ce7b8(U16(bss, 0x5c) + ((bss[0x5b] & 4) ? 0x2a : 0));
    FUN_022ce808(U16(bss, 0x5e) + ((bss[0x5b] & 4) ? 6 : 0));
    FUN_037cb534(e2);

    U16(st, 0xc2) = 1;
    cb = FUN_037d14bc();
    cb[0] = 0xc;
    cb[1] = 0;
    cb[4] = 7;
    cb[5] = U16(st, 0x188);
    FUN_037cb8b4(st + 0x18a, cb + 8, 6);
    cb[0xb] = U16(st, 0x30);
    cb[0xc] = U16(st, 0x32);
    FUN_037d1464(cb);
    FUN_037cb534(e);
}
