// decomp: module=arm7 addr=0x022c88bc name=FUN_022c88bc
// flags: -O4,s

// Reads the next byte out of the windowed cache at G_03805828: if the cursor
// has fallen outside the currently-loaded [start, end) window the window is
// refilled first, then the byte is fetched relative to the window start and the
// cursor advances.

#pragma thumb on

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Window {
    u32 f0;
    u32 start;
    u32 end;
} Window;

typedef struct Reader {
    char pad[0x28];
    u32 pos;
} Reader;

extern Window G_0380581c;
extern u8 G_03805828[];
extern void func_022c8bf0(u32 pos);

u8 FUN_022c88bc(Reader *r)
{
    u32 pos = r->pos;
    u8 v;

    if (pos < G_0380581c.start || pos >= G_0380581c.end) {
        func_022c8bf0(pos);
    }
    v = G_03805828[pos - G_0380581c.start];
    r->pos++;
    return v;
}
