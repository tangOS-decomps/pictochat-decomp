// decomp: module=unk_autoload_0 addr=0x0232414c name=FUN_0232414c
// flags: -O4,s

// D-pad navigation for the key grid at G_0238ef0c: plays the move click,
// then from the edge of the current key facing the pressed direction probes
// a strip of points in 8-pixel steps, wrapping around the 200x106 grid area,
// and returns the first other key hit (or the current key if none).

typedef unsigned short u16;

typedef struct Item {
    u16 x : 8;
    u16 y : 8;
    u16 w : 8;
    u16 h : 8;
    u16 f4;
    u16 id;
} Item;

struct Grid {
    int f0;
    int x;
    int y;
};

extern struct Grid G_0238ef0c;
extern char G_0238ef18[];

extern void FUN_02320978(int se);
extern Item *FUN_0232310c(void *list, int x, int y);

Item *FUN_0232414c(int dir, Item *cur, void *keys)
{
    int x0;
    int xlim;
    int dx;
    int dy;
    int x;
    int y;
    int ylim;
    Item *hit;
    int ix;     /* the rectangle is read into locals first; the */
    int iy;     /* direct-field form schedules the loads differently */
    int iw;
    int ih;

    FUN_02320978(0x28);
    if (dir & 0x40) {
        dx = -8;
        dy = -8;
        ix = cur->x * 2;
        iy = cur->y;
        iw = cur->w;
        x0 = G_0238ef0c.x + (ix + iw) / 2;
        xlim = x0 - 0x10;
        y = G_0238ef0c.y + iy;
        ylim = y - 0x50;
    } else if (dir & 0x80) {
        dx = 8;
        dy = 8;
        ix = cur->x * 2;
        iy = cur->y;
        iw = cur->w;
        ih = cur->h;
        x0 = G_0238ef0c.x + (ix + iw) / 2;
        xlim = x0 + 0x10;
        y = G_0238ef0c.y + (iy + ih);
        ylim = y + 0x50;
    } else if (dir & 0x20) {
        dx = -8;
        dy = 8;
        ix = cur->x;
        iy = cur->y * 2;
        ih = cur->h;
        x0 = G_0238ef0c.x + ix;
        xlim = x0 - 0x50;
        y = G_0238ef0c.y + (iy + ih) / 2;
        ylim = y + 0x10;
    } else if (dir & 0x10) {
        dx = 8;
        dy = 8;
        ix = cur->x;
        iw = cur->w;
        iy = cur->y * 2;
        ih = cur->h;
        x0 = G_0238ef0c.x + (ix + iw);
        xlim = x0 + 0x50;
        y = G_0238ef0c.y + (iy + ih) / 2;
        ylim = y + 0x10;
    }
    for (; y != ylim; y += dy) {
        for (x = x0; x != xlim; x += dx) {
            int wx = x;
            int wy = y;
            if (x - G_0238ef0c.x < 0)
                wx += 0xc8;
            else if (x - G_0238ef0c.x > 0xc8)
                wx -= 0xc8;
            if (y - G_0238ef0c.y < 0)
                wy += 0x6a;
            else if (y - G_0238ef0c.y > 0x6a)
                wy -= 0x6a;
            hit = FUN_0232310c(G_0238ef18, wx, wy);
            if (hit != 0 && hit != cur)
                return hit;
        }
    }
    return cur;
}
