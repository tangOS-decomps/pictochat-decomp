// decomp: module=arm7 addr=0x022d99c4 name=FUN_022d99c4
// flags: -O4,s -noThumb
// size: 0x140 - the nominal 0x13c excludes the trailing pool word (0x0380fff4).

// Finds the peer-table slot to use for the MAC address `mac`.
//
// Group/multicast addresses are rejected outright. When more than one peer is
// currently registered the table is walked from slot 1: an exact MAC hit wins
// immediately, otherwise the first empty slot is remembered and the walk stops
// once every registered peer has been seen. If the chosen slot is past the
// table's high-water mark at +0x322 the table is instead scanned for the
// weakest reclaimable entry (state < 0x30, +0x16 clear, smallest +0x18), and
// 0xff is returned when nothing can be reclaimed. The winning slot is bound to
// the MAC by FUN_022da5b4.
//
// The block base is re-read from the global at every use (it is reloaded after
// the FUN_022d84b0 call), while the +0x31c table header is cached in a local -
// that split is what puts the header in r6 and keeps the base in r0.

#define G_0380fff4 (*(unsigned char **)0x0380fff4)

typedef struct Entry {
    unsigned short state;  /* +0x00 */
    unsigned short f02;
    unsigned char mac[6];  /* +0x04 */
    unsigned char pad[0x16 - 0x0a];
    unsigned short f16;    /* +0x16 */
    unsigned short f18;    /* +0x18 */
    unsigned short f1a;
} Entry;

typedef struct Tbl {
    Entry *entries;       /* +0x31c */
    unsigned short f320;  /* +0x320 */
    unsigned short count; /* +0x322 */
} Tbl;

extern int FUN_022d84b0(const unsigned char *a, const unsigned char *b);
extern void FUN_022da5b4(unsigned int slot, const unsigned char *mac);

int FUN_022d99c4(const unsigned char *mac)
{
    Tbl *tbl;
    Entry *e;
    unsigned int slot;
    unsigned int seen;
    unsigned int freeSlot;
    unsigned int best;
    unsigned int count;
    unsigned int j;

    tbl = (Tbl *)(G_0380fff4 + 0x31c);
    if ((*(const unsigned short *)mac & 1) != 0) {
        return 0;
    }

    slot = 1;
    if (*(unsigned short *)(G_0380fff4 + 0x52c) > 1) {
        e = tbl->entries + 1;
        freeSlot = 0;
        seen = 0;
        for (; slot < tbl->count; slot++, e++) {
            if (e->state != 0) {
                if (FUN_022d84b0(e->mac, mac) != 0) {
                    return slot;
                }
                seen++;
                if (seen >= *(unsigned short *)(G_0380fff4 + 0x52c)) {
                    break;
                }
            } else {
                if (freeSlot == 0) {
                    freeSlot = slot;
                }
            }
        }
        if (freeSlot != 0) {
            slot = freeSlot;
        }
    }

    if (slot >= *(unsigned short *)(G_0380fff4 + 0x322)) {
        e = tbl->entries;
        count = tbl->count;
        best = 0x10000;
        j = 1;
        slot = 0;
        for (; j < count; j++) {
            if (e[j].state < 0x30 && e[j].f16 == 0) {
                if (best > e[j].f18) {
                    best = e[j].f18;
                    slot = j;
                }
            }
        }
        if (slot == 0) {
            return 0xff;
        }
    }

    FUN_022da5b4(slot, mac);
    return slot;
}
