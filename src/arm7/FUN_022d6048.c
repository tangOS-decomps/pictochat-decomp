// decomp: module=arm7 addr=0x022d6048 name=FUN_022d6048
// flags: -O4,s -noThumb
//
// Shuts the work area down.  If the state halfword the manager points at is
// still 1 (running) the teardown is performed and a type-4/0 message is posted
// to the ARM9; otherwise the request is refused with a type-4/3 message.
// Verify with size 0x68, not 0x64 - the stated size excludes the trailing pool
// word (&G_023190dc).

typedef struct Mgr6048 {
    char pad[0x550];
    unsigned short *state;
} Mgr6048;

extern Mgr6048 G_023190dc;

extern void FUN_022d0f8c(int arg);
extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(void);

void FUN_022d6048(void) {
    unsigned short *state = G_023190dc.state;
    unsigned short *msg;

    if (*state != 1) {
        msg = FUN_037d14bc();
        msg[0] = 4;
        msg[1] = 3;
        FUN_037d1464();
    } else {
        FUN_022d0f8c(1);
        *state = 0;
        msg = FUN_037d14bc();
        msg[0] = 4;
        msg[1] = 0;
        FUN_037d1464();
    }
}
