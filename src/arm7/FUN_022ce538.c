// decomp: module=arm7 addr=0x022ce538 name=FUN_022ce538
// NONMATCHING: 3 base-pointer registers live simultaneously -> spills to push/pop{r3,lr} the target doesn't need; tried 3 phrasings (div=999). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
// decomp: module=arm7 addr=0x022ce538 name=FUN_022ce538
// NONMATCHING: logs the low byte of `v` into a 32-entry ring buffer at a
// wrapping index, then folds `v` into a running 16-bit checksum global
// (v ^ (checksum<<1), then XOR-folded by 16). Logic-correct and same
// instruction shapes/count, but the candidate needs 3 base-pointer registers
// (ConnMgr conn-struct base, ring-buffer base, checksum address) live at
// overlapping points and spills to a `push {r3,lr}`/`pop {r3,lr}` frame the
// target doesn't have; target avoids this by reusing r1 (conn base -> the
// checksum value itself) and r3 (ring-buffer base -> the reloaded index)
// after their last use, needing only 5 registers total (r0-r3,ip), never 6.
// Tried 3 phrasings (direct struct-field style, checksum as a pointer local,
// statement reordering) - the base-pointer overlap didn't change; not a
// logic issue (div counted via size mismatch, candidate compiles 4 bytes
// larger from the extra push/pop pair). Counts as decompiled, not matched.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct ConnMgr2 {
    char pad[0x574];
    u32 f574;
} ConnMgr2;

extern ConnMgr2 G_023190dc;
extern u8 G_02319630[];
extern u16 G_02ffff98;

void FUN_022ce538(u32 v) {
    G_02319630[G_023190dc.f574] = (u8)v;
    G_023190dc.f574 = (G_023190dc.f574 + 1) & 0x1f;
    u32 r = v ^ (u32)(G_02ffff98 << 1);
    G_02ffff98 = (u16)(r ^ (r >> 16));
}
