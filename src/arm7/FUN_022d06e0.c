// decomp: module=arm7 addr=0x022d06e0 name=FUN_022d06e0
// flags: -O4,s -noThumb
//
// Sibling of FUN_022d0684 - same command-block prologue, opcode 0x215.

typedef struct CmdBlock {
    unsigned short f00;
    unsigned short f02;
    unsigned short f04;
    unsigned short f06;
    unsigned short f08;
    unsigned short f0a;
    unsigned short op;
    unsigned short count;
    unsigned short data[2];
} CmdBlock;

extern void FUN_022ce1d8(CmdBlock *p);

unsigned short *FUN_022d06e0(CmdBlock *p, unsigned short a)
{
    CmdBlock *tail;

    p->f00 = 0;
    p->f02 = 0;
    p->f04 = 0;
    p->f06 = 0;
    p->f08 = 0;
    p->f0a = 0;
    p->op = 0x215;
    p->count = 1;
    p->data[0] = a;

    tail = (CmdBlock *)((unsigned short *)p + p->count);
    tail->data[0] = p->op;
    tail->data[1] = 1;

    FUN_022ce1d8(p);
    return tail->data;
}
