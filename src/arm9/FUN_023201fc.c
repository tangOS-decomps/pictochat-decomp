// decomp: module=unk_autoload_0 addr=0x023201fc name=FUN_023201fc

// Power-up sequencer callback. On success it advances through the steps:
// 0 sets the backlight from the user settings, 1 sets the LCD routing,
// 2 marks start-up done; each async request re-enters here with the next
// step. On failure (or if a request is refused) it re-arms a retry alarm.

typedef struct UserFlags {
    unsigned short language : 3;
    unsigned short gbaScreen : 1;
    unsigned short backlight : 2;
    unsigned short rest : 10;
} UserFlags;

typedef struct AppState {
    unsigned int pad0 : 4;
    unsigned int flag4 : 1;
} AppState;

extern struct { int f0; int f4; } G_0236a1a0;
extern char G_0236a1a8[];

extern int FUN_02322800(int, unsigned short, void (*)(int, int), int);
extern AppState *FUN_0232254c(void);
extern int FUN_02339318(int, int, void (*)(int, int), int);
extern void FUN_02331dac(void);
extern void FUN_02331ef0(void *);
extern void FUN_02331ea8(void *, unsigned long long, void (*)(void *), void *);
extern void FUN_023202a4(void *);

void FUN_023201fc(int err, int step)
{
    int retry = 0;

    if (err == 0) {
        switch (step) {
        case 0:
            if (FUN_02322800(4, ((unsigned)*(unsigned short *)0x02fffce4 << 26) >> 30, FUN_023201fc, 1))
                retry = 1;
            break;
        case 1: {
            int screen = 2;
            if (FUN_0232254c()->flag4)
                screen = ((UserFlags *)0x02fffce4)->gbaScreen;
            if (FUN_02339318(screen, 1, FUN_023201fc, 2))
                retry = 1;
            break;
        }
        case 2:
            G_0236a1a0.f0 = 1;
            FUN_02331dac();
            break;
        }
    } else {
        retry = 1;
        step--;
    }
    if (retry) {
        FUN_02331ef0(G_0236a1a8);
        FUN_02331ea8(G_0236a1a8, 0x20b, FUN_023202a4, (void *)step);
    }
}
