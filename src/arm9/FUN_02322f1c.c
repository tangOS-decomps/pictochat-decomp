// decomp: module=unk_autoload_0 addr=0x02322f1c name=FUN_02322f1c
// flags: -O4,s

// Ticks the four jingle voices at G_0238ee44: an active voice waits out its
// delay, then reads its next note from its sequence (0x1b past the end).
// Notes up to 0x18 retrigger the voice (optionally detuned by -2..+1 from the
// tick counter and clamped to 0..0x18); 0x1a stops and rests, 0x19 rests,
// 0x1b ends the voice. Finally bumps the shared tick counter.

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Voice {
    char obj[4];
    u8 f04;
    u8 base;
    char pad06[2];
    u8 flags;
    char pad09;
    s8 seq[0x11];
    char pad1b[9];
    int active;
    u16 delay;
    u16 period;
    u8 idx;
    u8 rnd;
    char pad2e[2];
} Voice;

struct Player {
    void (*fn)(void);
    u32 tick;
};

extern struct Player G_0238ee3c;
extern Voice G_0238ee44[4];

extern void FUN_02323040(int);
extern void FUN_0232e94c(void *, int);
extern void FUN_0232fe40(void *, int, int, int, int, int);
extern void FUN_0232e9ec(void *, int, int);
extern void FUN_0232ea00(void *, int, int);

void FUN_02322f1c(void)
{
    u8 i;
    s8 note;
    s8 d;
    Voice *v;

    for (i = 0; i < 4; i++) {
        v = &G_0238ee44[i];
        if (v->active == 0)
            continue;
        if (v->delay == 0) {
            if (v->idx == 0)
                v->period = v->base;
            if (v->idx >= 0x11)
                note = 0x1b;
            else
                note = v->seq[v->idx++];
            if (note <= 0x18) {
                FUN_02323040(i);
                FUN_0232e94c(v, 0);
                FUN_0232fe40(v, i, 0, 0x60, 0, 0);
                if (v->flags & 1) {
                    d = (G_0238ee3c.tick % v->rnd & 3) - 2;
                    v->rnd++;
                    note += d;
                    if (note < 0)
                        note = 0;
                    else if (note > 0x18)
                        note = 0x18;
                }
                FUN_0232e9ec(v, 1, note << 6);
                if (v->flags & 4)
                    FUN_0232ea00(v, 1, 0x28);
            } else if (note == 0x1a) {
                FUN_02323040(i);
                FUN_0232e94c(v, 0);
            } else if (note == 0x19) {
                FUN_02323040(i);
            } else if (note == 0x1b) {
                v->active = 0;
                FUN_0232e94c(v, 0);
            }
        } else {
            v->delay--;
        }
    }
    G_0238ee3c.tick++;
}
