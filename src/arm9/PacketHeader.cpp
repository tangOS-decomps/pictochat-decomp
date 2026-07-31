//cpp
extern "C" {
// ==========================================================
// C++ Class Implementation: PacketHeader
// ==========================================================

// --- SetPacketHeader.cpp ---
// decomp: module=unk_autoload_0 addr=0x02336444 name=SetPacketHeader
// Contributed by opie-x (TangOS Discord): AI-assisted candidate (local
// checkpoints/final-v1 model), verified byte-exact via tools/match.py.
void SetPacketHeader(unsigned short *p, int a, int b)
{
    if (b < 0) {
        p[0] = 0xc0 | a;
        p[2] = -b;
    } else {
        p[0] = 0x80 | a;
        p[2] = b;
    }
}


}
