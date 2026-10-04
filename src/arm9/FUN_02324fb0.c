// decomp: module=unk_autoload_0 addr=0x02324fb0 name=FUN_02324fb0
// flags: -O4,s

// Picker error check: unless an error is already being shown, polls the
// connection status and, for codes 0xc/0xd/0xe, records the error state and
// pops up the matching message (0xd formats it with the current channel
// number), then opens the dialog.

typedef unsigned short u16;

struct Picker {
    char pad00[0x2c];
    int err;
};

extern struct Picker G_0239be54;

extern int FUN_0232996c(void);
extern void FUN_02321f9c(int, int);
extern void FUN_02321fbc(int, int, void *);
extern void FUN_023223f0(int, int);
extern void FUN_023224fc(void);
extern int *FUN_023260bc(void);
extern void FUN_02329650(u16 *, int);

void FUN_02324fb0(void)
{
    u16 buf[128];
    int err = G_0239be54.err;

    if (err != 2 && err != 4 && err != 3) {
        switch (FUN_0232996c()) {
        case 0xc:
            G_0239be54.err = 2;
            FUN_02321f9c(0x33, 1);
            FUN_023223f0(0x1b, 0);
            FUN_023224fc();
            break;
        case 0xd:
            G_0239be54.err = 4;
            FUN_02329650(buf, *FUN_023260bc());
            FUN_02321fbc(0x34, 1, buf);
            FUN_023223f0(0x1b, 0);
            FUN_023224fc();
            break;
        case 0xe:
            G_0239be54.err = 3;
            FUN_02321f9c(0x35, 1);
            FUN_023223f0(0x1b, 0);
            FUN_023224fc();
            break;
        }
    }
}
