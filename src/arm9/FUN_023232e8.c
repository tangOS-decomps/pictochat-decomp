// decomp: module=unk_autoload_0 addr=0x023232e8 name=FUN_023232e8
// flags: -O4,s

// Redraws the selection overlay on the 200-wide canvas at G_02393450: restores
// the canvas from the saved copy at G_023956d0, fills the rectangle of the
// current entry (1-based index at +0x26), then walks the circular rectangle
// list. If the list belongs to the same group as the other list it is filled
// solid, otherwise each rectangle gets a 1-pixel outline.

typedef unsigned short u16;
typedef short s16;

typedef struct Rect {
    u16 x : 8;
    u16 y : 8;
    u16 w : 8;
    u16 h : 8;
    s16 next;
    u16 id;
} Rect;

typedef struct Table {
    Rect *recs;
} Table;

typedef struct Overlay {
    Rect *list;
    Rect *other;
    Table *table;
    char pad[0x1a];
    u16 sel;
} Overlay;

extern char G_02393450[];
extern char G_023956d0[];

void FUN_023374b8(const void *src, void *dst, int len);
void FUN_02323f80(void *buf, int stride, int color, int x0, int y0, int x1, int y1);

void FUN_023232e8(Overlay *o)
{
    Table *table = o->table;
    Rect *r;

    FUN_023374b8(G_023956d0, G_02393450, 0x2280);
    if (o->sel != 0) {
        r = &table->recs[o->sel - 1];
        FUN_02323f80(G_02393450, 200, 8, r->x, r->y, r->x + r->w, r->y + r->h);
    }
    r = o->list;
    if (r != 0 && o->other != 0 && o->other->id != o->sel) {
        if (r->id != o->sel && r->id != 0) {
            if (r->id == o->other->id) {
                do {
                    FUN_02323f80(G_02393450, 200, 8, r->x, r->y, r->x + r->w, r->y + r->h);
                    r += r->next;
                } while (r != o->list);
            } else {
                do {
                    FUN_02323f80(G_02393450, 200, 8, r->x, r->y, r->x + r->w, r->y + 1);
                    FUN_02323f80(G_02393450, 200, 8, r->x, r->y + r->h - 1, r->x + r->w, r->y + r->h);
                    FUN_02323f80(G_02393450, 200, 8, r->x, r->y + 1, r->x + 1, r->y + r->h - 1);
                    FUN_02323f80(G_02393450, 200, 8, r->x + r->w - 1, r->y + 1, r->x + r->w, r->y + r->h - 1);
                    r += r->next;
                } while (r != o->list);
            }
        }
    }
}
