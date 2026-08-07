// decomp: module=arm7 addr=0x022d7db8 name=FUN_022d7db8
// flags: -O4,s -noThumb
// NOTE: verify with --size 0xb4, not the nominal 0x98 - the stated size
// excludes this function's own trailing 7-word literal pool.

// Wifi shutdown path: silences the two MAC registers 0x04808036 and 0x04808168,
// waits, then finishes according to the driver phase word at +0x5f8 of the ARM7
// state block.  Phase 2 is the "still associated" case: it programs the power
// register 0x04808158, runs the disassociate helper, and reports the raw and
// masked association-ID halves of 0x0480815c through FUN_022d862c before a
// longer wait and the common teardown FUN_022d87fc.  Phase 3 goes straight to
// the teardown; any other phase does nothing further.

typedef unsigned short u16;
typedef volatile unsigned short vu16;

extern void FUN_037c83b4(int cycles, void *arg);   // ARM<->Thumb veneer target
extern void FUN_037c849c(void);                    // ARM<->Thumb veneer target
extern void FUN_022d862c(int what, int value);
extern void FUN_022d87fc(void);

void FUN_022d7db8(void)
{
    u16 phase;

    *(vu16 *)0x04808036 = 0;
    FUN_037c83b4(0x1f40, (void *)0x0230bc88);
    *(vu16 *)0x04808168 = 0;

    phase = *(u16 *)(*(unsigned char **)0x0380fff4 + 0x5f8);
    switch (phase) {
    case 2: {
        u16 aid;

        *(vu16 *)0x04808158 = 0x6001;
        FUN_037c849c();
        aid = *(vu16 *)0x0480815c;
        FUN_022d862c(1, aid & 0x7f);
        FUN_022d862c(1, aid);
        FUN_037c83b4(0x9c40, (void *)0x0230bc88);
        FUN_022d87fc();
        break;
    }
    case 3:
        FUN_022d87fc();
        break;
    }
}
