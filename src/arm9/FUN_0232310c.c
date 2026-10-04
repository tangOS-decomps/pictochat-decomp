// decomp: module=unk_autoload_0 addr=0x0232310c name=FUN_0232310c
// flags: -O4,s

// Hit test for the overlay at (px, py): returns the first rectangle of the
// overlay's table (shifted by the screen origin in G_0238ef0c) that contains
// the point, skipping group-2 rectangles while the overlay is locked. A locked
// overlay also checks the two fixed button rectangles at G_0233af1c. Returns 0
// on a miss.

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
    char pad04[0xa];
    u16 count;
} Table;

typedef struct Overlay {
    Rect *list;
    Rect *other;
    Table *table;
    char pad0c[0x28];
    int locked;
} Overlay;

struct Screen {
    int unused0;
    int x;
    int y;
};

extern struct Screen G_0238ef0c;
extern Rect G_0233af1c[2];

Rect *FUN_0232310c(Overlay *o, int px, int py)
{
    Rect *recs = o->table->recs;
    int count = o->table->count;
    int oy = G_0238ef0c.y;
    int ox = G_0238ef0c.x;
    int i;
    Rect *r;
    unsigned int j;

    for (i = 0; i < count; i++) {
        r = &recs[i];
        if (oy + r->y <= py && py < oy + (r->y + r->h) &&
            ox + r->x <= px && px < ox + (r->x + r->w)) {
            if (o->locked == 0 || r->id != 2)
                return r;
        }
    }
    if (o->locked != 0) {
        for (j = 0; j < 2; j++) {
            r = &G_0233af1c[j];
            if (oy + r->y <= py && py < oy + (r->y + r->h) &&
                ox + r->x <= px && px < ox + (r->x + r->w))
                return r;
        }
    }
    return 0;
}
