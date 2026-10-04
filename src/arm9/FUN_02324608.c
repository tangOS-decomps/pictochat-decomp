// decomp: module=unk_autoload_0 addr=0x02324608 name=FUN_02324608
// flags: -O4,s

// Screen setup for the four-slot picker: loads the base palette plus the
// user's favourite-colour row, places the title, registers the screen's
// handlers, then lays out the four slot widgets (frame + label each, with
// their own row/column) before resetting the picker state.

typedef unsigned char u8;

struct Nibbles8 {
    u8 lo : 4;
    u8 hi : 4;
};

struct Picker {
    char pad00[8];
    int f08;
    char pad0c[4];
    int f10;
    char pad14[0xc];
    int f20;
    char pad24[8];
    int f2c;
    int f30;
    int f34;
};

struct Slot {
    char frame[0x40];
    char label[0x40];
    int row;
    int col;
    int state;
};

extern struct Picker G_0239be54;
extern char G_0239be68[];
extern char G_0239be84[];
extern char G_0239be8c[];
extern char G_0239be98[];
extern struct Slot G_0239bed8[4];
extern char G_02348ce4[];      /* start of the palette */
extern char G_end_02348ee4[];  /* one past its end */
extern u8 G_023490e4[];
extern char G_02349a1c[];
extern char G_0233b9d4[];
extern char G_0233b498[];

extern void FUN_02336880(void *, int, int);
extern void FUN_02321df4(void);
extern void FUN_023221d4(int, int, int);
extern void FUN_023224a4(void);
extern void *FUN_02320c7c(void);
extern void FUN_02320ac8(void *);
extern void FUN_02320afc(void *, void *);
extern void *FUN_023215e4(void);
extern void FUN_02321600(void *, int);
extern void FUN_02322244(void *);
extern void FUN_02321e24(void *);
extern void FUN_02321634(void *, void *, void *, int);
extern void FUN_02321664(void *, void *, void *, int);
extern void FUN_023216e0(void *, void *);
extern void FUN_023374f0(void *, int, int);
extern int *FUN_023260bc(void);
extern void FUN_0232131c(void *);

void FUN_02324608(int alt)
{
    int i;
    int v;

    G_0239be54.f08 = 0;
    FUN_02336880(G_02348ce4, 0, G_end_02348ee4 - G_02348ce4);
    FUN_02336880(&G_023490e4[((struct Nibbles8 *)0x02FFFC82)->lo * 0x20], 0x1e0, 0x20);
    FUN_02321df4();
    if (alt)
        FUN_023221d4(0x1f, 0x22, 6);
    else
        FUN_023221d4(0x1a, 0x23, 6);
    FUN_023224a4();
    FUN_02320ac8(FUN_02320c7c());
    FUN_02320afc(FUN_02320c7c(), G_02349a1c);
    FUN_02321600(FUN_023215e4(), *(int *)((char *)FUN_02320c7c() + 0x62c));
    FUN_02322244(FUN_023215e4());
    FUN_02321e24(FUN_023215e4());
    FUN_02321634(FUN_023215e4(), G_0239be98, G_0233b9d4, 0xc);
    {
        int frames[4] = {8, 9, 10, 11};
        int labels[4] = {1, 3, 5, 7};
        int rows[4] = {0, 1, 2, 3};
        int cols[4] = {1, 3, 5, 7};
        FUN_023374f0(G_0239bed8, 0, sizeof(G_0239bed8));
        for (i = 0; i < 4; i++) {
            FUN_02321634(FUN_023215e4(), G_0239bed8[i].frame, G_0233b9d4, frames[i]);
            FUN_02321664(FUN_023215e4(), G_0239bed8[i].label, G_0233b9d4, labels[i]);
            FUN_023216e0(G_0239bed8[i].label, G_0233b498);
            G_0239bed8[i].row = rows[i];
            G_0239bed8[i].col = cols[i];
            G_0239bed8[i].state = 0;
        }
    }
    FUN_023374f0(G_0239be68, 0, 0x30);
    FUN_023374f0(G_0239be84, 0, 8);
    v = *FUN_023260bc();
    G_0239be54.f20 = v;
    G_0239be54.f30 = v << 17;
    G_0239be54.f34 = v << 17;
    FUN_0232131c(G_0239be8c);
    G_0239be54.f2c = 0;
    G_0239be54.f10 = 0;
}
