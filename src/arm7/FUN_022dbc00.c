// decomp: module=arm7 addr=0x022dbc00 name=FUN_022dbc00
#pragma thumb off
#pragma optimize_for_size on

extern void *FUN_037c58fc(void *heap, int size);
extern void FUN_037c5de8(void *heap, void *block);
extern void FUN_022d9088(int bits);
extern void FUN_022d811c(unsigned short *dst, const unsigned short *src);

typedef struct Cmd {
    char pad[0xc];
    unsigned short type;   /* 0x0c */
    unsigned short len;    /* 0x0e */
    unsigned short mac[3]; /* 0x10 */
    unsigned short arg;    /* 0x16 */
} Cmd;

int FUN_022dbc00(const unsigned short *mac, unsigned short arg)
{
    Cmd *c = (Cmd *)FUN_037c58fc((char *)*(void **)0x0380fff4 + 0x188, 0x18);
    int result;

    if (c == 0) {
        FUN_022d9088(1);
        result = 0;
    } else {
        c->type = 0x85;
        c->len = 4;
        FUN_022d811c(c->mac, mac);
        c->arg = arg;
        FUN_037c5de8((char *)*(void **)0x0380fff4 + 0x188, c);
        result = 1;
    }

    return result;
}
