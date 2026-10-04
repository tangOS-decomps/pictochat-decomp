// decomp: module=unk_autoload_0 addr=0x0232234c name=FUN_0232234c
// flags: -O4,s

// Per-frame animation of the top bar (G_0238e11c): slides the bar in or out
// two pixels at a time depending on flag bit 0, then steps each of the two
// buttons in G_0238e134. A busy button slides out; once fully out it latches
// its flag bit, applies any pending label change and turns idle, and an idle
// button slides back in. Finally refreshes the bar's touch area.

typedef unsigned int u32;

struct Bar {
    u32 flags;
    int slide;
};

struct Entry {
    int value;
    int pending;
    int anim;
    int lit;
    int busy;
    char obj[0x40];
};

extern struct Bar G_0238e11c;
extern char G_0238e128[];
extern struct Entry G_0238e134[2];
extern u32 G_0233a004[2];
extern char G_0233b80c[];
extern char G_0233b4b0[];

extern void FUN_02321684(void *, void *, int);
extern void FUN_02321328(void *, void *);

void FUN_0232234c(void)
{
    int i;
    struct Entry *e;
    int p;

    if (G_0238e11c.flags & 1) {
        if (G_0238e11c.slide != 0)
            G_0238e11c.slide -= 2;
    } else {
        if (G_0238e11c.slide != 0x18)
            G_0238e11c.slide += 2;
    }
    for (i = 0; i < 2; i++) {
        e = &G_0238e134[i];
        if (e->busy != 0) {
            if (e->anim != 0x18) {
                e->anim += 2;
            } else {
                e->lit = (G_0238e11c.flags & G_0233a004[i]) ? 1 : 0;
                p = e->pending;
                if (p != -1) {
                    e->value = p;
                    FUN_02321684(e->obj, G_0233b80c, p);
                    e->pending = -1;
                }
                e->busy = 0;
            }
        } else {
            if (e->anim != 0)
                e->anim -= 2;
        }
    }
    FUN_02321328(G_0238e128, G_0233b4b0);
}
