// decomp: module=arm7 addr=0x022d9b60 name=FUN_022d9b60
// flags: -O4,s -noThumb
// size: 0x90 - 0x8c of code plus the trailing pool word for 0x0380fff4.

// Takes the 0x01000000 lock around a bump of the per-channel entry selected by
// the caller's id (16-bit field at +2): if the state block's +0x350 word says 1
// and the entry has never been used, the pool is (re)initialised for that id
// first. After releasing the lock, entries whose bit is clear in the +0x534
// mask get their +0x18 slot refreshed from +0x1a.

extern int FUN_037c9084(int lock);
extern void FUN_037c904c(int token);
extern void FUN_022da128(int id);

typedef struct Entry {
    char pad[0x16];
    unsigned short uses; /* +0x16 */
    unsigned short cur;  /* +0x18 */
    unsigned short def;  /* +0x1a */
} Entry;                 /* 0x1c bytes */

void FUN_022d9b60(unsigned short *req)
{
    int token;
    int id;
    Entry *e;

    id = req[1];
    e = &(*(Entry **)(*(int *)0x0380fff4 + 0x31c))[id];
    token = FUN_037c9084(0x01000000);

    if (*(unsigned short *)(*(int *)0x0380fff4 + 0x350) == 1 && e->uses == 0) {
        FUN_022da128(id);
    }
    e->uses++;
    FUN_037c904c(token);

    if ((*(unsigned short *)(*(int *)0x0380fff4 + 0x534) & (1 << id)) == 0) {
        e->cur = e->def;
    }
}
