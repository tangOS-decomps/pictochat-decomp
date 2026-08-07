// decomp: module=arm7 addr=0x022d991c name=FUN_022d991c
// flags: -O4,s -noThumb

// Looks up the peer slot whose address block matches `mac`, skipping slot 0 and
// any empty slot, and giving up early once as many live slots as the table at
// +0x52c claims have been walked. Returns the slot index, 0 when the caller's
// entry is flagged, and 0xff when nothing matched.

typedef struct Peer {
    unsigned short used;        /* 0x00 */
    unsigned short pad02;
    unsigned char addr[6];      /* 0x04 */
    unsigned char pad0a[0x12];
} Peer;

extern unsigned char *G_0380fff4;

extern int FUN_022d84b0(const unsigned char *a, const unsigned short *b);

int FUN_022d991c(unsigned short *mac)
{
    Peer *p;
    unsigned int i;
    unsigned int seen;

    if ((*mac & 1) != 0) {
        return 0;
    }
    if (*(unsigned short *)(G_0380fff4 + 0x52c) > 1) {
        p = (Peer *)(*(unsigned char **)(G_0380fff4 + 0x31c) + sizeof(Peer));
        seen = 0;
        for (i = 1; i < *(unsigned short *)(G_0380fff4 + 0x322); i++, p++) {
            if (p->used != 0) {
                if (FUN_022d84b0(p->addr, mac) != 0) {
                    return i;
                }
                seen++;
                if (seen >= *(unsigned short *)(G_0380fff4 + 0x52c)) {
                    break;
                }
            }
        }
    }
    return 0xff;
}
