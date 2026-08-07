// decomp: module=arm7 addr=0x022ce25c name=FUN_022ce25c
// flags: -O4,s -noThumb

// Posts a message to the 0x02318164 queue when the caller's status word is
// clear, and if the post fails while a connection is live, pushes an
// indication packet (id = first halfword of the message, length 8) instead.

typedef struct ConnMgr2 {
    char pad[0x54c];
    int f54c;
} ConnMgr2;

extern ConnMgr2 G_023190dc;

extern int FUN_037c9e90(void *q, void *msg, int block);
extern void *FUN_037d14bc(void);
extern void FUN_037d1464(void *ind);

void FUN_022ce25c(void *unused, unsigned short *msg, int status)
{
    unsigned short *ind;

    if (status == 0) {
        if (FUN_037c9e90((void *)0x02318164, msg, 0) == 0) {
            if (G_023190dc.f54c != 0) {
                ind = (unsigned short *)FUN_037d14bc();
                ind[0] = msg[0];
                ind[1] = 8;
                ind[2] = 0;
                ind[3] = 0;
                FUN_037d1464(ind);
            }
        }
    }
}
