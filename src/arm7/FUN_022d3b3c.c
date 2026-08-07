// decomp: module=arm7 addr=0x022d3b3c name=FUN_022d3b3c
// flags: -O4,s -noThumb

typedef struct Src {
    unsigned char pad0[4];
    unsigned short stat;      /* +0x04 */
    unsigned short pad1;
    unsigned char body[0xb4]; /* +0x08 */
} Src;

typedef struct Pkt {
    unsigned short kind;      /* +0x00 */
    unsigned short ok;        /* +0x02 */
    unsigned short code;      /* +0x04 */
    unsigned short err;       /* +0x06 */
    unsigned char body[0xb4]; /* +0x08 */
} Pkt;

extern Src *FUN_022d0948(void *work);
extern Pkt *AllocReply(void);
extern void SendReply(Pkt *);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned int size);

void FUN_022d3b3c(void)
{
    unsigned short stat;
    Src *src;
    unsigned char work[0x200];

    src = FUN_022d0948(work);
    stat = src->stat;

    if (stat != 0) {
        Pkt *p = AllocReply();
        p->kind = 0x20;
        p->ok = 1;
        p->code = 0x307;
        p->err = stat;
        SendReply(p);
    } else {
        Pkt *p = AllocReply();
        p->kind = 0x20;
        p->ok = 0;
        MI_CpuCopy8(src->body, p->body, 0xb4);
        SendReply(p);
    }
}
