// decomp: module=arm7 addr=0x022d0edc name=FUN_022d0edc
// flags: -O4,s -noThumb
//
// Type-2 (shutdown) request handler.  Refuses with reason 3 unless the state
// halfword is 2; otherwise queries the driver and either reports the failure
// code it returned (reason 1, detail 0x301) or performs the teardown and
// answers with reason 0.
// Verify with size 0xb0, not 0xac - the stated size excludes the trailing pool
// word (&G_023190dc).
//
// NOTE: FUN_022d08bc is declared `void FUN_022d08bc(void *)` in
// src/arm7/FUN_022d08bc.c; this call site consumes r0 after the call, so it is
// declared here as returning the block it filled in.

typedef struct Mgr0edc {
    char pad[0x550];
    unsigned short *state;
} Mgr0edc;

extern Mgr0edc G_023190dc;

extern unsigned short *FUN_022d08bc(void *out);
extern void FUN_022d0f8c(int arg);
extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(void);

void FUN_022d0edc(void) {
    char buf[0x200];
    unsigned short *state = G_023190dc.state;
    unsigned short *msg;
    unsigned short err;

    if (*state != 2) {
        msg = FUN_037d14bc();
        msg[0] = 2;
        msg[1] = 3;
        FUN_037d1464();
    } else {
        err = FUN_022d08bc(buf)[2];
        if (err != 0) {
            unsigned short type = 2;
            unsigned short reason = 1;

            msg = FUN_037d14bc();
            msg[0] = type;
            msg[1] = reason;
            msg[2] = reason + 0x300;
            msg[3] = err;
            FUN_037d1464();
        } else {
            *state = 1;
            FUN_022d0f8c(1);
            *state = 0;
            msg = FUN_037d14bc();
            msg[0] = 2;
            msg[1] = 0;
            FUN_037d1464();
        }
    }
}
