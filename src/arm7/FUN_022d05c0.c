// decomp: module=arm7 addr=0x022d05c0 name=FUN_022d05c0
// flags: -O4,s -noThumb
typedef struct Frame05c0 {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short f6;
    unsigned short f8;
    unsigned short fa;
    unsigned short type;
    unsigned short count;
    unsigned short body[1];
} Frame05c0;

extern void FUN_022ce1d8(Frame05c0 *frame);

unsigned short *FUN_022d05c0(Frame05c0 *frame, unsigned short arg) {
    unsigned short *p;
    frame->f0 = 0;
    frame->f2 = 0;
    frame->f4 = 0;
    frame->f6 = 0;
    frame->f8 = 0;
    frame->fa = 0;
    frame->type = 0x20e;
    frame->count = 1;
    frame->body[0] = arg;
    p = (unsigned short *)frame + frame->count;
    p[8] = frame->type;
    p[9] = 1;
    FUN_022ce1d8(frame);
    return p + 8;
}
