// decomp: module=arm7 addr=0x022dded8 name=FUN_022dded8
// flags: -O4,s -noThumb
//
// Rewrites the trailer that sits `count` halfwords past the start of command
// block `p` (the same overlay FUN_022d0684 builds): lifts the trailer's first
// halfword back into the block's opcode field, then stamps the trailer with
// status 2, a zero, and the block's +0x18 halfword, before forwarding the
// block to func_037c5de8.

typedef struct CmdBlock {
    unsigned short f00;
    unsigned short f02;
    unsigned short f04;
    unsigned short f06;
    unsigned short f08;
    unsigned short f0a;
    unsigned short op;
    unsigned short count;
    unsigned short data[8];
} CmdBlock;

extern void func_037c5de8(void *a, CmdBlock *p);

void FUN_022dded8(void *a, CmdBlock *p)
{
    CmdBlock *tail = (CmdBlock *)((unsigned short *)p + p->count);

    p->op = tail->data[0];
    tail->data[1] = 2;
    tail->data[2] = 0;
    tail->data[3] = p->data[4];

    func_037c5de8(a, p);
}
