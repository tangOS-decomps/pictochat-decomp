//cpp
// decomp: module=unk_autoload_0 addr=0x023374f0 name=FUN_023374f0
// verify: python tools/match.py --c src/arm9/FUN_023374f0.cpp --func FUN_023374f0 --addr 0x023374f0 --size 0x94 --module unk_autoload_0 --version 2.0/sp1
// flags: -noThumb

extern "C" {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void FUN_023374f0(u8 *dst, u32 value, u32 size)
{
    u16 half;
    u32 word;
    u8 *end;

    if (size == 0) return;

    if ((u32)dst & 1) {
        *(u16 *)(dst - 1) = (*(u16 *)(dst - 1) & 0xff) | (value << 8);
        dst++;
        if (--size == 0) return;
    }

    if (size >= 2) {
        half = (u16)(value | value << 8);
        if ((u32)dst & 2) {
            *(u16 *)dst = half;
            dst += 2;
            size -= 2;
            if (size == 0) return;
        }

        word = half | (half << 16);
        end = dst + (size & ~3);
        size &= 3;
        while (dst < end) {
            *(u32 *)dst = word;
            dst += 4;
        }
        if (size & 2) {
            *(u16 *)dst = half;
            dst += 2;
        }
    }

    if (size & 1) {
        *(u16 *)dst = (*(u16 *)dst & 0xff00) | (value & 0xff);
    }
}
}
