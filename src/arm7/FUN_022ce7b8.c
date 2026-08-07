// decomp: module=arm7 addr=0x022ce7b8 name=FUN_022ce7b8
// flags: -O4,s -noThumb

// Programs the horizontal size of the active capture/scaler descriptor hanging
// off G_023190dc+0x550: the request is clamped to 0x200, stored into the two
// "width" fields, then the +4 padded stride is written into either the first or
// the second field pair depending on the mode flag at +0x188.

typedef struct Capture {
    char pad00[0x30];
    unsigned short f30;
    unsigned short f32;
    unsigned short f34;
    unsigned short f36;
    unsigned short f38;
    unsigned short f3a;
    unsigned short f3c;
    unsigned short f3e;
    char pad40[0x188 - 0x40];
    unsigned short f188;
} Capture;

typedef struct CaptureMgr {
    char pad[0x550];
    Capture *cap;
} CaptureMgr;

extern CaptureMgr G_023190dc;

void FUN_022ce7b8(unsigned short w)
{
    Capture *cap = G_023190dc.cap;

    if (w > 0x200) {
        w = 0x200;
    }
    cap->f30 = w;
    cap->f34 = w;
    if (cap->f188 == 0) {
        cap->f3c = (unsigned short)(w + 4);
        cap->f38 = (unsigned short)(w + 4);
    } else {
        cap->f3e = (unsigned short)(w + 4);
        cap->f3a = (unsigned short)(w + 4);
    }
}
