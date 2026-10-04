//cpp
// decomp: module=unk_autoload_0 addr=0x0232fc94 name=FUN_0232fc94
// size: 0x90 - the nominal 0x8c excludes the trailing pool word.
// The offset table is indexed off `(int *)arc + count + idx` with the 0x3c
// header folded into the loads; spelling it as &arc->offs[...] costs an add.
//
// Loads member `idx` of an archive into the slot cache at +0x3c (FUN_023381cc
// answers non-zero when it is already resident). The member's extent comes
// from the offset table that follows the `count` slots, its last entry ending
// at the archive end (+0x8). A buffer of len+0x20 is allocated through
// FUN_0232f84c, the member is read into it from `src`, flushed, and published
// in the slot. Returns 1 when the member is resident, 0 on any failure.

extern "C" {

typedef struct Arc {
    char pad00[8];
    int end;        /* +0x08 */
    char pad0c[0x2c];
    int count;      /* +0x38 */
    int offs[1];    /* +0x3c */
} Arc;

extern int FUN_023381cc(Arc *arc, unsigned int idx);
extern int FUN_023381a8(Arc *arc);
extern void FUN_0232fc68(void);
extern void *FUN_0232f84c(void *heap, int size, void (*cb)(void), Arc *arc, unsigned int idx);
extern int FUN_0232f6a8(void *src, void *dst, int len, int off);
extern void FUN_023314e8(void *p, int len);
extern void FUN_023381ac(Arc *arc, unsigned int idx, void *data);

int FUN_0232fc94(Arc *arc, unsigned int idx, void *src, void *heap)
{
    unsigned int last;
    int *e;
    int off;
    int len;
    void *buf;

    if (FUN_023381cc(arc, idx) != 0) {
        return 1;
    }
    last = FUN_023381a8(arc) - 1;
    e = (int *)arc + (arc->count + idx);
    off = e[15];
    len = ((idx < last) ? e[16] : arc->end) - off;
    if (heap == 0) {
        return 0;
    }
    buf = FUN_0232f84c(heap, len + 0x20, FUN_0232fc68, arc, idx);
    if (buf == 0) {
        return 0;
    }
    if (len != FUN_0232f6a8(src, buf, len, off)) {
        return 0;
    }
    FUN_023314e8(buf, len);
    FUN_023381ac(arc, idx, buf);
    return 1;
}

}
