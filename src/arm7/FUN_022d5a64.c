// decomp: module=arm7 addr=0x022d5a64 name=FUN_022d5a64
// flags: -O4,s -noThumb
// Matches on the 2.0/* family (all 7 builds), NOT the dsi/* canonical.
// Verify with the UNTRUNCATED size 0x204, not funcs.json's 0x1fc: Ghidra's
// size stops at the last instruction and excludes this function's own two
// literal-pool words (0x022d5c60 = &G_023190dc, 0x022d5c64 = 0xffff), which
// the compiler emits as part of the function. See notes/mwccarm-codegen.md 3m.
//   python tools/match.py --c src/arm7/FUN_022d5a64.c --func FUN_022d5a64 //     --addr 0x022d5a64 --size 0x204 --module arm7 --version 2.0/base
typedef struct ConnMgr5a64 {
    char pad[0x550];
    char *conn;
} ConnMgr5a64;

extern ConnMgr5a64 G_023190dc;
extern void *func_037d14bc(void);
extern void func_037d1464(void *pkt);

void FUN_022d5a64(unsigned short index, unsigned int a1, unsigned short *chunk,
                   unsigned int len, void *ctx) {
    char *typeFlagBase;
    char *conn;
    unsigned int chunkLen;
    unsigned int val;
    unsigned short *p;
    unsigned short hdr;
    char *slot;
    int hasLenField;
    int hasMaskField;
    unsigned int consumed;
    unsigned int subIndex;
    struct { unsigned short *cur; unsigned short *pktSrc; int first; } L;
    unsigned int maskOff;
    unsigned short *pkt;
    unsigned short v30;
    unsigned short v32;

    L.cur = chunk;
    conn = G_023190dc.conn;

    if (len == 0 || len > 0x204 || index == *(unsigned short *)(conn + 0x100 + 0x88) ||
        index >= 0x10 || (len & 1) != 0) {
        return;
    }
    typeFlagBase = conn + 0x100;

    slot = conn + 0x1f8 + index * 0x10;
    L.first = 1;

    while ((int)len > 0) {
        val = 0xFFFF;
        if (L.first == 1) {
            p = (unsigned short *)&a1;
            L.first = 0;
        } else {
            p = L.cur;
            L.cur = p + 1;
            len -= 2;
        }
        hdr = *p;

        chunkLen = ((unsigned int)hdr << 24) >> 23;
        if (chunkLen == 0) {
            chunkLen = 0x200;
        }
        hasLenField = (hdr & 0x1000) != 0;
        hasMaskField = (hdr & 0x800) != 0;

        consumed = chunkLen + (hasMaskField ? 2 : 0) + (hasLenField ? 2 : 0);
        len -= consumed;
        if ((int)len < 0) {
            return;
        }

        subIndex = ((unsigned int)(hdr & 0xf00) << 8) >> 16;
        L.pktSrc = L.cur;
        p = (unsigned short *)((char *)L.cur + chunkLen);
        L.cur = (unsigned short *)((char *)L.cur + consumed);

        if (hasMaskField == 1) {
            maskOff = (subIndex & 7) * 2;
            val = *p;
            p += 1;
            if ((*(unsigned short *)(slot + maskOff) & 1) != 0) {
                *(unsigned short *)(slot + maskOff) = val << 1;
                goto notify;
            }
            val = val << 1;
            if ((unsigned short)(*(unsigned short *)(slot + maskOff) - val) < 0x100) {
                continue;
            }
            *(unsigned short *)(slot + maskOff) = val;
        }

    notify:
        if (hasLenField == 1) {
            if ((*p & (1 << *(unsigned short *)(typeFlagBase + 0x88))) == 0) {
                continue;
            }
        }
        if ((int)chunkLen > 0) {
            pkt = (unsigned short *)func_037d14bc();
            pkt[0] = 0x82;
            pkt[1] = 0;
            pkt[2] = 0x15;
            pkt[3] = subIndex;
            *(void **)(pkt + 4) = ctx;
            *(unsigned short **)(pkt + 6) = L.pktSrc;
            pkt[8] = chunkLen;
            pkt[9] = index;
            pkt[0x10] = *(unsigned short *)(typeFlagBase + 0x88);
            pkt[0xd] = val;

            v30 = *(unsigned short *)(conn + 0x30);
            v32 = *(unsigned short *)(conn + 0x32);
            pkt[0x20] = *(unsigned short *)(typeFlagBase + 0x88) == 0 ? v30 : v32;
            pkt[0x21] = *(unsigned short *)(typeFlagBase + 0x88) == 0 ? v32 : v30;
            func_037d1464(pkt);
        }
    }
}
