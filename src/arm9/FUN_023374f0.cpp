//cpp
// decomp: module=unk_autoload_0 addr=0x023374f0 name=FUN_023374f0
// NONMATCHING: the ARM fill algorithm and size are correct, but mwcc schedules the odd-byte and halfword paths differently and uses different temporary registers for the end pointer and tail merge. (div=14). Logic verified correct vs ROM; not byte-exact.
// flags: -noThumb

extern "C" {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void FUN_023374f0(u8 *dst, u32 value, u32 size)
{
    if (size == 0) return;

    if ((u32)dst & 1) {
        *(u16 *)(dst - 1) = (*(u16 *)(dst - 1) & 0xff) | (value << 8);
        dst++;
        size--;
        if (size == 0) return;
    }

    if (size >= 2) {
        value |= value << 8;
        if ((u32)dst & 2) {
            *(u16 *)dst = value;
            dst += 2;
            size -= 2;
            if (size == 0) return;
        }

        value |= value << 16;
        {
            u32 count = size & ~3;
            if (count != 0) {
                size -= count;
                u8 *end = dst + count;
                do {
                    *(u32 *)dst = value;
                    dst += 4;
                } while (dst < end);
            }
        }
        if (size & 2) {
            *(u16 *)dst = value;
            dst += 2;
        }
    }

    if (size & 1) {
        *(u16 *)dst = (*(u16 *)dst & 0xff00) | (value & 0xff);
    }
}
}
