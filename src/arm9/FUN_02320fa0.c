// decomp: module=unk_autoload_0 addr=0x02320fa0 name=FUN_02320fa0
// flags: -O4,s

// Appends one OAM entry (and optionally its affine parameter block) to a
// shadow OAM buffer. Fails (returns 0) when the entry table or, for affine
// sprites, the parameter table is full; otherwise copies the entry, points
// its affine index at the new parameter slot (0 when none) and returns 1.

typedef struct OamEntry {
    unsigned int lo : 25;
    unsigned int affine : 5;
    unsigned int size : 2;
    unsigned int attr2;
} OamEntry;

typedef struct OamAffine {
    int m[4];
} OamAffine;

typedef struct OamBuf {
    /* 0x000 */ OamEntry oam[128];
    /* 0x400 */ OamAffine affine[32];
    /* 0x600 */ int count;
    /* 0x604 */ int affineCount;
} OamBuf;

int FUN_02320fa0(OamBuf *buf, OamEntry *entry, OamAffine *affine)
{
    if (buf->count == 0x7f)
        return 0;
    if (affine != 0 && buf->affineCount == 0x1f)
        return 0;
    buf->oam[buf->count] = *entry;
    buf->oam[buf->count].affine = affine != 0 ? buf->affineCount : 0;
    if (affine != 0) {
        buf->affine[buf->affineCount] = *affine;
        buf->affineCount++;
    }
    buf->count++;
    return 1;
}
