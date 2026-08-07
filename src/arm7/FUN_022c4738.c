// decomp: module=arm7 addr=0x022c4738 name=FUN_022c4738
// flags: -O4,s -noThumb

// Installs `handler` into every slot named by `mask`, walking bits 0..0x18.
// The bit number is not the slot number: bits 8..0xb map to slots 0..3, bits
// 3..6 map to slots 4..7, bit 0 maps to slot 8, and every other set bit only
// writes the word table at 0x038048e0 without touching a slot.
//
// Here the table is one struct base rather than three column symbols: the slot
// is written as a whole (handler / live / arg) and that is what fuses into the
// single `stm`, while `&G_03804ef4[8]` folds to a plain pool word.

typedef struct {
    void *handler;
    int live;
    int arg;
} Slot022c4738;

extern Slot022c4738 G_03804ef4[];
extern Slot022c4738 G_03804f54; /* == G_03804ef4[8] */
extern void *G_038048e0[];

void FUN_022c4738(unsigned int mask, void *handler)
{
    int i;

    for (i = 0; i < 0x19; i++) {
        if (mask & 1) {
            Slot022c4738 *slot = 0;

            if (i >= 8 && i <= 0xb) {
                slot = &G_03804ef4[i - 8];
            } else if (i >= 3 && i <= 6) {
                slot = &G_03804ef4[i + 1];
            } else if (i == 0) {
                slot = &G_03804f54;
            } else {
                G_038048e0[i] = handler;
            }
            if (slot != 0) {
                slot->handler = handler;
                slot->arg = 0;
                slot->live = 1;
            }
        }
        mask >>= 1;
    }
}
