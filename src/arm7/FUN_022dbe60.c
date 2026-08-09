// decomp: module=arm7 addr=0x022dbe60 name=FUN_022dbe60
#pragma thumb off
#pragma optimize_for_size on

extern void *FUN_037c58fc(void *heap, int size);
extern void FUN_037c5de8(void *heap, void *block);
extern void FUN_022d9088(int bits);
extern void FUN_022d811c(unsigned short *dst, const unsigned short *src);

typedef struct Cmd {
    char pad[0xc];
    unsigned short type;
    unsigned short len;
    unsigned short mac[3];
    unsigned short arg;
} Cmd;

int FUN_022dbe60(const unsigned short *mac, unsigned short arg)
{
    Cmd *c = (Cmd *)FUN_037c58fc((char *)*(void **)0x0380fff4 + 0x188, 0x18);
    int result;

    if (c == 0) {
        FUN_022d9088(1);
        result = 0;
    } else {
        c->type = 0x88;
        c->len = 4;
        FUN_022d811c(c->mac, mac);
        c->arg = arg;
        FUN_037c5de8((char *)*(void **)0x0380fff4 + 0x188, c);
        result = 1;
    }

    return result;
}
