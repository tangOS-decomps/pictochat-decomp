//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232def4 name=FUN_0232def4
// Text layout helper: walks a null-terminated u16 string `s`, and for each
// '\n' (0xa) encountered after the first character, adds a fixed increment
// (the struct's 5-bit `field` plus the caller-supplied `extra`) to a running
// total that starts at `field` itself. Returns that total. `field` is a
// packed bitfield at byte offset 0x16 of `st` (bits 5-9 of the u16 there) -
// likely a per-line height/advance value, with `extra` presumably an
// inter-line gap, used somewhere in PictoChat's chat-bubble text rendering.
typedef unsigned short u16;
struct Layout {
    unsigned short pad0 : 5;
    unsigned short field : 5;
    unsigned short pad1 : 6;
};
int FUN_0232def4(void *st, u16 *s, int extra)
{
    int field = ((struct Layout *)((char *)st + 0x16))->field;
    u16 c = *s;
    if (c != 0) {
        extra += field;
        do {
            if (c == 10) field += extra;
            s++;
            c = *s;
        } while (c != 0);
    }
    return field;
}

}
