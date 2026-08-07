// decomp: module=arm7 addr=0x022cff10 name=FUN_022cff10
// flags: -noThumb

// Builds a fixed-format header (type=3, len=0x22, next=<param>), clears the
// tag byte, fills the trailing body with a caller-supplied fill value, then
// stamps a small trailer (a copy of the header type + a fixed opcode 5) at
// the offset the header's own "len" field points to, and queues the struct.

typedef struct {
    unsigned short f0, f2, f4, f6, f8, fA;  // +0x00-+0x0a, always zeroed
    unsigned short type;                     // +0x0c
    unsigned short len;                      // +0x0e
    unsigned short next;                     // +0x10
    unsigned short f12;                      // +0x12
} Hdr022cff10;

extern void FUN_037cb78c(int value, void *dest, unsigned int size);
extern void FUN_022ce1d8(void *conn);

void *FUN_022cff10(Hdr022cff10 *hdr, unsigned short next, int fillValue)
{
    hdr->f0 = 0;
    hdr->f2 = 0;
    hdr->f4 = 0;
    hdr->f6 = 0;
    hdr->f8 = 0;
    hdr->fA = 0;
    hdr->type = 3;
    hdr->len = 0x22;
    hdr->next = next;
    hdr->f12 = 0;

    FUN_037cb78c(fillValue, (unsigned char *)hdr + 0x14, 0x44);

    {
        unsigned short len = hdr->len;
        unsigned short type = hdr->type;
        unsigned char *trailer = (unsigned char *)hdr + (len << 1);
        *(unsigned short *)(trailer + 0x10) = type;
        *(unsigned short *)(trailer + 0x12) = 5;
        FUN_022ce1d8(hdr);
        return trailer + 0x10;
    }
}
