// decomp: module=arm7 addr=0x022d7e6c name=FUN_022d7e6c
// flags: -O4,s -noThumb

// Sets the requested rate: 0xffff means "unlimited" and is stored verbatim,
// otherwise the rate is scaled by the per-unit cost and the resulting budget is
// rejected with code 5 when it overflows 0x10000.

typedef unsigned short u16;

typedef struct Req {
    char pad[0x1c];
    u16 f1c;
} Req;

typedef struct Rate {
    char pad[0x6e];
    u16 f6e;
    char pad2[0x8c - 0x70];
    u16 f8c;
} Rate;

typedef struct State {
    char pad[0x31c];
    Req req;
    char pad2[0x344 - 0x33a];
    Rate rate;
} State;

extern unsigned int FUN_037c8a00(unsigned int, unsigned int);

int FUN_022d7e6c(int v) {
    State *s = *(State **)0x0380fff4;
    Rate *rate = &s->rate;
    Req *req = &s->req;
    unsigned int budget;
    if (v == 0xffff) {
        req->f1c = 0xffff;
        rate->f8c = 0xffff;
    } else {
        budget = FUN_037c8a00(v * rate->f6e, 100);
        if (budget > 0x10000) return 5;
        req->f1c = v;
        rate->f8c = budget;
    }
    return 0;
}
