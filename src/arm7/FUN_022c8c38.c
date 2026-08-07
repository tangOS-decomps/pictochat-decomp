// decomp: module=arm7 addr=0x022c8c38 name=FUN_022c8c38
// flags: -O4,s
//
// Pulls one operand out of a byte stream according to a five-way tag:
//   0 - a single byte
//   1 - a little-endian halfword
//   2 - a 7-bit-per-byte varint, high bit continues
//   4 - a byte used as a key into the table argument, yielding a signed word
//   3 - a signed halfword range [a,b], resolved to a random value inside it
// An unrecognised tag falls straight through to the shared epilogue, returning
// the still-uninitialised accumulator - that is the ROM's behaviour, not a
// transcription artefact. The case bodies sit in the order 0,1,2,4,3, which is
// the order the jump table's block offsets require.
//
// Stated size 0xae stops inside the case-3 block; the function really runs to
// 0x022c8cf0, i.e. 0xb8 bytes including the two-halfword-aligned jump table.

#pragma thumb on

typedef struct Stream Stream;

extern unsigned char FUN_022c88bc(Stream *s);
extern short *FUN_022c9764(void *tbl, int key);
extern int FUN_022c7af4(void);

int FUN_022c8c38(Stream *s, void *tbl, int tag)
{
    int v;
    int lo;
    int c;
    int a;
    int r;
    unsigned short b;
    short *p;

    switch (tag) {
    case 0:
        v = FUN_022c88bc(s);
        break;

    case 1:
        lo = FUN_022c88bc(s);
        v = (unsigned short)((FUN_022c88bc(s) << 8) | lo);
        break;

    case 2:
        v = 0;
        do {
            c = FUN_022c88bc(s);
            v = (v << 7) | (c & 0x7f);
        } while (c & 0x80);
        break;

    case 4:
        p = FUN_022c9764(tbl, FUN_022c88bc(s));
        if (p != 0)
            v = *p;
        break;

    case 3:
        lo = FUN_022c88bc(s);
        a = (short)(unsigned short)((FUN_022c88bc(s) << 8) | lo);
        lo = FUN_022c88bc(s);
        b = (unsigned short)((FUN_022c88bc(s) << 8) | lo);
        r = FUN_022c7af4();
        r = (((short)b - a + 1) * r) >> 16;
        v = r + a;
        break;
    }

    return v;
}
