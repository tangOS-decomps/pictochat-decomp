// decomp: module=arm7 addr=0x022da128 name=FUN_022da128
// flags: -O4,s -noThumb

// Sets this port's bit in the hardware key map at 0x0480425c + the base offset
// held at +0x3d8, under the usual 0x01000000 critical section, but only while
// the port is idle (state 0x40) and not already masked out by +0x534. Port 0
// owns the low byte on its own; other ports index by translated association id.

extern unsigned char *G_0380fff4;

extern int FUN_022d9ffc(int port);
extern unsigned int FUN_022da0e8(int port);
extern unsigned char FUN_022d8d6c(unsigned char *addr);
extern void FUN_022d8d40(unsigned char *addr, unsigned char value);
extern int FUN_037c9084(int lock);
extern void FUN_037c904c(int token);

void FUN_022da128(int port)
{
    unsigned char *map;
    int token;
    unsigned int bit;

    if (FUN_022d9ffc(port) != 0x40) {
        return;
    }
    if ((*(unsigned short *)(G_0380fff4 + 0x534) & (1 << port)) != 0) {
        return;
    }

    map = (unsigned char *)0x0480425c + *(unsigned short *)(G_0380fff4 + 0x3d8);
    token = FUN_037c9084(0x01000000);
    if (port == 0) {
        FUN_022d8d40(map + 4, (unsigned char)(FUN_022d8d6c(map + 4) | 1));
    } else {
        bit = FUN_022da0e8(port);
        map = map + 5 + (bit >> 3);
        FUN_022d8d40(map, (unsigned char)(FUN_022d8d6c(map) | (1 << (bit & 7))));
    }
    FUN_037c904c(token);
}
