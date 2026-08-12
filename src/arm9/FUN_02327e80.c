// decomp: module=unk_autoload_0 addr=0x02327e80 name=FUN_02327e80
#pragma thumb on
#pragma optimize_for_size on

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

struct Coord {
    s16 v : 12;
    u16 a : 2;
    u16 b : 2;
};

struct Vec {
    struct Coord x;
    struct Coord y;
};

struct View {
    struct Vec v[2];
    s16 w;
    s16 h;
    s16 pt[8];
};

struct Nibbles {
    u16 lo : 4;
    u16 hi : 4;
    u16 rest : 8;
};

struct Nibbles8 {
    u8 lo : 4;
    u8 hi : 4;
};

struct Bits3 {
    u16 lo : 3;
    u16 rest : 13;
};

struct Triple {
    int a;
    int b;
    int c;
};

struct Ctx {
    /* 0x00 */ int dir;
    /* 0x04 */ int hold;
    /* 0x08 */ int repeat;
    /* 0x0c */ int timer;
    /* 0x10 */ int state;
    /* 0x14 */ int next;
    /* 0x18 */ int unk18;
    /* 0x1c */ int unk1c;
    /* 0x20 */ int sel;
    /* 0x24 */ void *unk24;
    /* 0x28 */ u16 *unk28;
    /* 0x2c */ int unk2c;
};

struct App {
    /* 0x000 */ u8 pad000[0x10];
    /* 0x010 */ void *f10;
    /* 0x014 */ u8 pad014[0x10];
    /* 0x024 */ void *f24;
    /* 0x028 */ u8 pad028[0x10];
    /* 0x038 */ void *f38;
    /* 0x03c */ void *f3c;
    /* 0x040 */ void *f40;
    /* 0x044 */ int f44;
    /* 0x048 */ struct Nibbles mode;
    /* 0x04a */ u8 pad04a[0x520];
    /* 0x56a */ u16 page;
    /* 0x56c */ u8 pad56c[4];
    /* 0x570 */ u8 f570;
};

struct Slot {
    u8 pad000[0x156];
    /* 0x156 */ u16 f156;
};

struct Entry {
    u8 pad000[0x4c];
    /* 0x4c */ u16 f4c;
};

struct Bits8 {
    u8 pad000[8];
    /* 0x08 */ struct Nibbles mode;
};

struct Sel {
    u8 pad000[0x10];
    /* 0x10 */ u8 f10;
};

struct Menu {
    u8 pad000[0xc];
    /* 0x0c */ u16 f0c;
};

extern struct Ctx G_0239fe68;
extern struct App G_023a0098;
extern struct Bits8 G_023a00d8;
extern struct Sel G_023a05f8;
extern struct Menu G_023a060c;
extern struct Triple G_0233a0f0;
extern int G_0239fe80[];
extern int G_0239fe98[];
extern int G_023a00c0[];
extern int G_023a064c[];
extern int G_023a068c[];
extern int G_023a06cc[];
extern int G_0233b4d8[];
extern int G_0233b5cc[];
extern int G_0235ed70[];
extern int G_02348944[];
extern int G_02348ac4[];
extern int G_02348d44[];
extern u8 G_023490e4[];

extern void FUN_02320978(int);
extern int FUN_02320c7c(void);
extern void FUN_02320e14(int, void *, void *, int, int, int);
extern void FUN_02320e3c(int, void *, void *, int, int);
extern void FUN_02320e60(int, void *, void *, int, int, int, int);
extern void FUN_02320e88(int, void *, void *, int, int);
extern void FUN_02320f4c(int, void *, void *, int, int, int);
extern void FUN_023210c8(void *, int, int, int, int);
extern int FUN_023212bc(int);
extern int FUN_023212c8(int);
extern int FUN_023212d4(int);
extern int FUN_023212e0(void);
extern int FUN_023212ec(void);
extern int FUN_023212f8(void);
extern int FUN_02321304(void);
extern void FUN_023216e0(void *, void *);
extern int FUN_02321c60(void);
extern int FUN_02321d04(int);
extern void FUN_02321fbc(int, int, void *);
extern void FUN_02321fd4(void);
extern int FUN_02321fe0(void);
extern int FUN_02321fec(void);
extern int FUN_02322104(void);
extern void FUN_023221b0(void);
extern void *FUN_02322820(void);
extern void *FUN_02322844(void);
extern int FUN_02322870(void);
extern void FUN_02322cd8(void);
extern void FUN_02322d30(void);
extern void FUN_02322d68(void);
extern void FUN_02322d70(int);
extern int FUN_023234b4(void);
extern void FUN_023234c0(void);
extern void FUN_02323798(int);
extern void FUN_023237e4(void);
extern int FUN_02323834(void);
extern void FUN_02323840(void);
extern int FUN_02323c84(void);
extern int FUN_02323d14(void);
extern void FUN_02323d44(void *);
extern void FUN_02323f74(void);
extern void FUN_0232519c(void *);
extern void FUN_023251c4(void *);
extern int FUN_023251cc(void *);
extern int FUN_02325250(void);
extern int FUN_02325278(void);
extern void FUN_023253ec(void *);
extern void FUN_02325408(void *, int);
extern void FUN_023257b4(void *, void *, int);
extern void FUN_02325804(void *);
extern void FUN_02325a54(void *, int);
extern void FUN_02325ce0(void *);
extern void FUN_023260a4(void);
extern int FUN_023260b0(void);
extern int *FUN_023260bc(void);
extern int FUN_023260c4(void);
extern void FUN_023276d8(void);
extern struct Entry *FUN_023277ec(int);
extern int FUN_023279a4(int, int);
extern void FUN_02327bfc(void *);
extern void FUN_02327c54(void *);
extern void FUN_02327c70(void *);
extern void FUN_02327c9c(void);
extern void FUN_02327ce0(void);
extern void FUN_02327d24(void);
extern void FUN_02327d68(void);
extern void FUN_02327dac(void);
extern int FUN_02327e20(int, int);
extern void FUN_02328d08(int);
extern void FUN_02328d60(int, int);
extern void FUN_02328d80(int, int);
extern void FUN_02328da8(int);
extern void FUN_02328e74(int);
extern int FUN_02329124(void);
extern int FUN_02329228(void);
extern void FUN_02329650(u16 *, int);
extern void FUN_0232965c(void *, int);
extern int FUN_0232996c(void);
extern void FUN_0232dd40(int, void *, struct Coord, struct Coord, int, int, u16 *, int);
extern int FUN_0232e004(void *, int, int);
extern void FUN_02334610(u16 *, int);
extern void FUN_02334628(u16 *, u16 *, int);
extern void FUN_0233621c(void *, int);
extern void FUN_0233746c(int, void *, int);
extern void FUN_023374b8(void *, void *, int);
extern void FUN_02336880(void *, int, int);
extern void FUN_023393e0(void);

void FUN_02327e80(void)
{
    u16 line0[14];
    u16 names[27];
    struct Triple tbl1;
    struct Triple tbl0;
    struct View view;
    u16 line1[256];
    struct App *app;
    u16 *src;
    u16 *dst;
    struct Entry *entry;
    struct Triple *tbl;
    int id;
    int sel;
    int limit;
    int frame;
    int keys;
    int held;
    int value;

    app = &G_023a0098;
    if (G_0239fe68.state != 2) {
        switch (G_0239fe68.state - 4) {
        case 0:
            FUN_02320978(0x28);
            FUN_02328da8(G_0239fe68.unk2c);
            view.v[0].y.a = view.v[0].x.a = view.v[0].y.b = view.v[0].x.b = 0;
            FUN_0233746c(0, G_023a0098.f38, G_023a0098.f44);
            line0[13] = 0;
            FUN_0233746c(0, names, 0x1b);
            src = G_0239fe68.unk28;
            dst = names;
            FUN_0233746c(0, names, 0x36);
            while (*src != 0 && src < G_0239fe68.unk28 + 26) {
                *dst = *src;
                src++;
                dst++;
            }
            view.v[0].y.v = 0x1a;
            view.v[0].x.v = 0x12;
            FUN_02334628(line0, names, 0xd);
            FUN_0232dd40(FUN_02321c60(), G_023a00c0, view.v[0].y, view.v[0].x, 1, 3, line0, 1);
            view.v[0].x.v += 0x10;
            FUN_02334628(line0, &names[13], 0xd);
            FUN_0232dd40(FUN_02321c60(), G_023a00c0, view.v[0].y, view.v[0].x, 1, 3, line0, 1);
            FUN_023216e0(&G_023a060c, G_0239fe68.unk24);
            G_0239fe68.sel = -1;
            FUN_02328d08(1);
            G_0239fe68.state = 5;
            break;
        case 2:
            FUN_02320978(0x28);
            FUN_02328da8(FUN_02322870());
            FUN_023216e0(&G_023a060c, FUN_02322820());
            FUN_0233746c(0, G_023a0098.f38, G_023a0098.f44);
            G_0239fe68.sel = -1;
            FUN_02328d60(0x1f, 1);
            FUN_02328d80(0x1f, 1);
            *(u16 *)0x04001050 = 0;
            FUN_023260a4();
            G_0239fe68.state = 7;
            break;
        case 3:
            if (FUN_023260b0() != 0) {
                G_0239fe68.state = 0;
            }
            break;
        case 4:
            view.v[1].y.a = view.v[1].x.a = view.v[1].y.b = view.v[1].x.b = 0;
            FUN_0233746c(0, app->f38, app->f44);
            view.v[1].y.v = 0x1a;
            view.v[1].x.v = 2;
            switch (FUN_0232996c()) {
            case 0xc:
                FUN_02334610(line1, FUN_02321d04(0x33));
                break;
            case 0xd:
                FUN_02329650(line1, *FUN_023260bc());
                break;
            case 0xe:
                FUN_02334610(line1, FUN_02321d04(0x35));
                break;
            default:
                FUN_02334610(line1, FUN_02321d04(0x33));
                break;
            }
            FUN_0232dd40(FUN_02321c60(), G_023a00c0, view.v[1].y, view.v[1].x, 1, 4, line1, 1);
            G_0239fe68.sel = -1;
            FUN_02320978(0x23);
            FUN_02328d08(1);
            G_0239fe68.state = 9;
            break;
        case 6:
            G_0239fe68.sel = -1;
            FUN_0233746c(0, app->f38, app->f44);
            FUN_02328d60(0x1f, 1);
            FUN_02328d80(0x1f, 1);
            *(u16 *)0x04001050 = 0;
            G_0239fe68.state = 1;
            break;
        }
    }

    if (FUN_023260c4() != 0 && G_0239fe68.state == 0 && FUN_02329124() != 0) {
        G_0239fe68.state = 8;
    }

    switch (G_0239fe68.state) {
    case 0:
        FUN_02325ce0(app);
        sel = FUN_0232e004(G_0233b4d8, FUN_023212f8(), FUN_02321304());
        if (FUN_023212ec() == 1) {
            switch (sel) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
                G_0239fe68.sel = sel;
                break;
            case 15:
                limit = FUN_023279a4(G_023a060c.f0c, 2) + 0x37;
                if (FUN_023212f8() <= limit + 0x17) {
                    G_0239fe68.sel = sel;
                }
                break;
            }
            switch (sel) {
            case 5:
                if (app->mode.hi == 2) {
                    frame = app->f570 + 1;
                    if (frame >= 2) {
                        frame = 0;
                    } else {
                        FUN_023253ec(app);
                        FUN_02322d68();
                    }
                    app->f570 = (u8)frame;
                }
                app->mode.hi = 2;
                FUN_02320978(0x10);
                break;
            case 6:
                app->mode.hi = 3;
                FUN_02320978(0x11);
                break;
            case 8:
                app->mode.lo = 0;
                FUN_02320978(0x12);
                break;
            case 7:
                app->mode.lo = 1;
                FUN_02320978(0x13);
                break;
            case 3:
                FUN_02327c9c();
                break;
            case 4:
                FUN_02327d24();
                break;
            case 18:
                entry = FUN_023277ec(FUN_023212f8());
                if (entry != 0) {
                    G_0239fe68.unk24 = entry;
                    G_0239fe68.unk28 = (u16 *)((u8 *)entry + 0x16);
                    G_0239fe68.unk2c = entry->f4c;
                    G_0239fe68.state = 4;
                }
                break;
            }
        } else if (FUN_023251cc(G_0239fe80) != 0 && sel == G_0239fe68.sel) {
            switch (sel) {
            case 3:
                FUN_02327c9c();
                break;
            case 4:
                FUN_02327d24();
                break;
            }
            FUN_0232519c(G_0239fe80);
        } else if (FUN_023212e0() != 0 && sel != G_0239fe68.sel) {
            FUN_023251c4(G_0239fe80);
        } else if (FUN_023212e0() != 0 && sel == G_0239fe68.sel) {
            FUN_0232519c(G_0239fe80);
        } else if (FUN_023212ec() == 3 && sel == G_0239fe68.sel) {
            switch (sel) {
            case 0:
                FUN_02327bfc(app);
                break;
            case 1:
                FUN_02327c54(app);
                break;
            case 2:
                FUN_02327c70(app);
                break;
            case 9:
                FUN_02323798(0);
                break;
            case 10:
                FUN_02323798(1);
                break;
            case 11:
                FUN_02323798(2);
                break;
            case 12:
                FUN_02323798(3);
                break;
            case 13:
                FUN_02323798(4);
                break;
            case 14:
                G_0239fe68.state = 1;
                break;
            case 15:
                G_0239fe68.unk24 = FUN_02322820();
                G_0239fe68.unk28 = FUN_02322844();
                G_0239fe68.unk2c = FUN_02322870();
                G_0239fe68.state = 4;
                break;
            }
        }
        if (FUN_023212ec() == 3) {
            G_0239fe68.sel = -1;
            FUN_023251c4(G_0239fe80);
        }
        keys = FUN_02325278();
        held = (u16)FUN_023212c8(0x300);
        if (keys & 1) {
            FUN_02323f74();
        } else if (!(FUN_02325250() & 2) && FUN_023212bc(2) != 0 && app->page == 0 &&
                   ((struct Slot *)((u8 *)app + app->page * 0x104))->f156 == 0 &&
                   FUN_023212e0() == 0) {
            FUN_023234c0();
            FUN_023221b0();
            FUN_0232965c(G_0239fe98, *FUN_023260bc());
            FUN_02321fbc(0x39, 2, G_0239fe98);
            FUN_02336880(G_02348d44, 0x60, 0x20);
            FUN_02336880(&G_023490e4[((struct Nibbles8 *)0x02FFFC82)->lo * 0x20], 0x1e0, 0x20);
            G_0239fe68.state = 2;
            FUN_02320978(0x1a);
        } else if (keys & 0x400) {
            if (FUN_02323834() == 1) {
                FUN_02325804(&G_023a0098);
            }
        } else if (keys & 0x800) {
            FUN_023237e4();
        } else if (held != 0) {
            if (G_0239fe68.dir == 0) {
                if ((held & 0x200) && !(held & 0x100)) {
                    G_0239fe68.dir = 1;
                } else if ((held & 0x100) && !(held & 0x200)) {
                    G_0239fe68.dir = 2;
                }
            } else if (G_0239fe68.dir == 1 || G_0239fe68.dir == 3) {
                if (held & 0x100) {
                    G_0239fe68.dir = 3;
                    G_0239fe68.repeat = (G_0239fe68.repeat + 1) % 10;
                    if (G_0239fe68.repeat == 0) {
                        FUN_02327d68();
                    }
                }
                if (!(held & 0x200)) {
                    G_0239fe68.dir = 0;
                }
            } else if (G_0239fe68.dir == 2 || G_0239fe68.dir == 4) {
                if (held & 0x200) {
                    G_0239fe68.dir = 4;
                    G_0239fe68.repeat = (G_0239fe68.repeat + 1) % 10;
                    if (G_0239fe68.repeat == 0) {
                        FUN_02327ce0();
                    }
                }
                if (!(held & 0x100)) {
                    G_0239fe68.dir = 0;
                }
            }
            if ((unsigned int)G_0239fe68.dir <= 2) {
                if (keys & 0x200) {
                    FUN_02327d24();
                } else if (keys & 0x100) {
                    FUN_02327c9c();
                }
            }
        } else if (keys & 8) {
            FUN_02327bfc(&G_023a0098);
        } else if (held == 0) {
            G_0239fe68.dir = 0;
            G_0239fe68.repeat = 0;
        }
        if (FUN_023212bc(4) != 0) {
            G_0239fe68.hold = 0;
        } else if (FUN_023212c8(4) != 0) {
            if (G_0239fe68.hold < 0x1e) {
                G_0239fe68.hold = G_0239fe68.hold + 1;
                if (G_0239fe68.hold == 0x1e) {
                    FUN_02327c70(&G_023a0098);
                }
            }
        } else if (FUN_023212d4(4) != 0 && G_0239fe68.hold < 0x1e) {
            FUN_02327c54(&G_023a0098);
        }
        if (G_0239fe68.state != 2) {
            FUN_02323840();
        }
        FUN_02325a54(app, FUN_02323c84());
        break;
    case 5:
        id = FUN_0232e004(G_0233b4d8, FUN_023212f8(), FUN_02321304());
        switch (FUN_023212ec()) {
        case 1:
            if (id == 0x10) {
                G_0239fe68.sel = id;
            }
            break;
        case 3:
            if (id == G_0239fe68.sel && id == 0x10) {
                G_0239fe68.state = 6;
            }
            G_0239fe68.sel = -1;
            break;
        }
        if (FUN_023212bc(1) != 0) {
            G_0239fe68.state = 6;
        }
        FUN_023210c8(G_023a068c, 0, 0, 0, 0);
        FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0x1a, FUN_02327e20(0x10, 1));
        FUN_02327dac();
        break;
    case 9:
        id = FUN_0232e004(G_0233b4d8, FUN_023212f8(), FUN_02321304());
        switch (FUN_023212ec()) {
        case 1:
            if (id == 0x10) {
                G_0239fe68.sel = id;
            }
            break;
        case 3:
            if (id == G_0239fe68.sel && id == 0x10) {
                if (FUN_02329124() == 2) {
                    FUN_023393e0();
                } else {
                    G_0239fe68.state = 10;
                }
            }
            G_0239fe68.sel = -1;
            break;
        }
        if (FUN_023212bc(1) != 0) {
            if (FUN_02329124() == 2) {
                FUN_023393e0();
            } else {
                G_0239fe68.state = 10;
            }
        }
        FUN_023210c8(G_023a064c, 0, 0, 0, 0);
        FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0x1a, FUN_02327e20(0x10, 1));
        if (G_0239fe68.state == 10) {
            FUN_02328e74(1);
        }
        break;
    case 2:
        if (FUN_02321fec() == 0) {
            G_0239fe68.timer = G_0239fe68.timer + 1;
            if (G_0239fe68.timer > 0x16) {
                G_0239fe68.state = G_0239fe68.next;
                FUN_02336880(G_02348944, 0x60, 0x20);
                FUN_02336880(G_02348ac4, 0x1e0, 0x20);
                break;
            }
        }
        if (FUN_02321fe0() != 0) {
            break;
        }
        switch (FUN_02322104()) {
        case 1:
            FUN_02320978(0x1b);
            G_0239fe68.next = 3;
            FUN_02321fd4();
            G_0239fe68.timer = 0;
            break;
        case 0:
            FUN_02320978(0x20);
            G_0239fe68.next = 0;
            FUN_02321fd4();
            G_0239fe68.timer = 0x16;
            break;
        }
        break;
    case 3:
        G_0239fe68.state = 1;
        break;
    }

    if (G_0239fe68.state == 0 || G_0239fe68.state == 2 || G_0239fe68.state == 3 ||
        G_0239fe68.state == 7) {
        FUN_02327dac();
    }
    if (G_0239fe68.state != 2) {
        FUN_023276d8();
    }
    FUN_02323d44(view.pt);
    if (FUN_023234b4() != 0) {
        view.w = (s16)FUN_023234b4();
        view.h = 0;
        FUN_023216e0(G_023a06cc, &view.w);
        FUN_023210c8(G_023a06cc, FUN_023212f8(), FUN_02321304(), 0, 0);
    }
    FUN_02320e14(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0x1e, view.pt[0], view.pt[1]);
    FUN_02320e14(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0x1f, view.pt[2], view.pt[3]);
    FUN_02320e14(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0x20, view.pt[4], view.pt[5]);
    FUN_02320e14(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0x21, view.pt[6], view.pt[7]);
    if (FUN_02329228() != 0) {
        FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 1, FUN_02327e20(0, 0));
        FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 2, FUN_02327e20(0, 0));
    }
    FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0, FUN_02327e20(0, 0));
    FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 3, FUN_02327e20(1, 0));
    FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 4, FUN_02327e20(2, 0));
    value = FUN_02327e20(0xe, 0);
    if (value == 7) {
        id = 0x12;
    } else {
        id = 0x11;
    }
    FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, id, value);
    FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 5, FUN_02327e20(3, 0));
    FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 6, FUN_02327e20(4, 0));
    id = 0;
    if (G_023a00d8.mode.hi == 2) {
        switch (G_023a05f8.f10) {
        case 3:
            id = 8;
            break;
        case 4:
            id = 9;
            break;
        case 1:
            id = 5;
            FUN_02322d30();
            FUN_02322cd8();
            break;
        case 0:
        case 2:
        default:
            FUN_02322d70(6);
            id = 6;
            break;
        }
    } else {
        FUN_02322d70(6);
    }
    FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 7, id);
    if (G_023a00d8.mode.hi == 3) {
        id = 6;
    } else {
        id = 0;
    }
    FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 8, id);
    if (G_023a00d8.mode.lo == 0) {
        id = 6;
    } else {
        id = 0;
    }
    FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0xa, id);
    if (G_023a00d8.mode.lo == 1) {
        id = 6;
    } else {
        id = 0;
    }
    FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 9, id);
    tbl0 = G_0233a0f0;
    FUN_0233621c(&tbl1, 0xc);
    if (((struct Bits3 *)0x02FFFCE4)->lo == 0) {
        tbl = &tbl0;
    } else {
        tbl = &tbl1;
    }
    if (FUN_02323834() == 0) {
        value = 6;
    } else {
        value = 0;
    }
    FUN_02320e60(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0xb, 0, tbl->a, value);
    if (FUN_02323834() == 2) {
        value = 6;
    } else {
        value = 0;
    }
    FUN_02320e60(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0xc, 0, tbl->b, value);
    if (FUN_02323834() == 1) {
        value = 6;
    } else {
        value = 0;
    }
    FUN_02320e60(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0xd, 0, tbl->c, value);
    if (FUN_02323834() == 3) {
        id = 6;
    } else {
        id = 0;
    }
    FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0xe, id);
    if (FUN_02323834() == 4) {
        id = 6;
    } else {
        id = 0;
    }
    FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0xf, id);
    FUN_02320f4c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0x10, 6, 3);
    FUN_02320e88(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0x10, 2);
    FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0x1c, 0);
    FUN_02320e3c(FUN_02320c7c(), G_0235ed70, G_0233b5cc, 0x1d, 0);
    if ((G_0239fe68.state == 0 || G_0239fe68.state == 7) && G_0239fe68.sel == -1 &&
        FUN_02323d14() == 0) {
        FUN_02325408(app, 0);
    }
    if (G_0239fe68.state == 0 || G_0239fe68.state == 7) {
        FUN_023374b8(app->f10, app->f3c, app->f44);
        FUN_023257b4(app->f3c, app->f24, app->f44);
        FUN_023374b8(app->f3c, app->f40, app->f44);
    } else if (G_0239fe68.state != 2) {
        FUN_023374b8(app->f38, app->f40, app->f44);
    }
}
