// decomp: module=arm7 addr=0x022c5f78 name=FUN_022c5f78
// flags: -noThumb

// Picks up the handoff pointer left at 0x02fffd9c, keeping it only when it
// points inside the 0x02600000-0x02800000 window; otherwise falls back to the
// built-in handler. Clears the ready flag on the way out.

extern unsigned int G_0380518c[];
extern void FUN_037fda5c(void);

void FUN_022c5f78(void)
{
    unsigned int v;

    v = *(unsigned int *)0x02fffd9c;
    if (v < 0x2600000 || v >= 0x2800000) {
        v = 0;
    }
    G_0380518c[2] = v;
    if (v == 0) {
        *(void **)0x0380ffdc = (void *)FUN_037fda5c;
    }
    G_0380518c[0] = 0;
}
