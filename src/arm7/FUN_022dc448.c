// decomp: module=arm7 addr=0x022dc448 name=FUN_022dc448
// flags: -O4,s -noThumb

// Applies a per-entry value to the AID table at (*(0x0380fff4))->tbl.
// req->idx == 0xffff broadcasts to every entry from 1 up to the current entry
// count; otherwise a single (non-zero) entry is updated. Rejects an out-of-range
// index or an out-of-range level with 5, otherwise returns 0.

typedef struct Ent {
    unsigned char pad0[0x18];
    unsigned short cur;     /* +0x18 */
    unsigned short want;    /* +0x1a */
} Ent;                      /* sizeof == 0x1c */

typedef struct St {
    unsigned char pad0[0x31c];
    Ent *tbl;               /* +0x31c */
    unsigned char pad1[2];
    unsigned short count;   /* +0x322 */
} St;

typedef struct Req {
    unsigned char pad0[0x10];
    unsigned short idx;     /* +0x10 */
    unsigned short val;     /* +0x12 */
    unsigned short level;   /* +0x14 */
} Req;

extern void FUN_022d7e6c(int level);

int FUN_022dc448(Req *req, unsigned short *out)
{
    Ent *tbl = (*(St **)0x0380fff4)->tbl;

    out[1] = 1;

    if (req->idx >= (*(St **)0x0380fff4)->count && req->idx != 0xffff) {
        return 5;
    }
    if (req->level > 0x3f && req->level != 0xffff) {
        return 5;
    }

    if (req->idx == 0xffff) {
        unsigned int i;
        for (i = 1; i < (*(St **)0x0380fff4)->count; i++) {
            tbl[i].want = req->val;
            if (tbl[i].cur != 0) {
                tbl[i].cur = req->val;
            }
        }
    } else if (req->idx != 0) {
        tbl[req->idx].want = req->val;
        if (tbl[req->idx].cur != 0) {
            tbl[req->idx].cur = req->val;
        }
    }

    if (req->level != 0) {
        FUN_022d7e6c(req->level);
    }
    return 0;
}
