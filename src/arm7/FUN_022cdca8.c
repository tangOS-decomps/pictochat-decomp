// decomp: module=arm7 addr=0x022cdca8 name=FUN_022cdca8
// flags: -O4,s
// Event dispatcher: brackets the handling with the enter/leave pair
// (FUN_022cd6b0 / FUN_022cd6d4), always reports the event, then runs the
// type-specific handler for events 6 and 0x86 only.  FUN_022cdce4 is the
// ARM->Thumb veneer parked directly after this function (lever 5).
// The test is spelled `if (type != 6) { ... } else { ... }` on purpose: the
// ROM branches AWAY on ==6 and falls through into the ==0x86 body, which is
// the opposite layout from `if (type == 6) ... else if (type == 0x86) ...`
// and from a two-case switch (the switch also emits an extra `b` to the
// default).  Verified at --size 0x3a.
#pragma thumb on

extern void FUN_022cd6b0(void);
extern void FUN_022cd6bc(int type, int arg);
extern void FUN_022cd6c8(int a, int b);
extern void FUN_022cdce4(int a, int b);
extern void FUN_022cd6d4(void);

void FUN_022cdca8(int type, int arg, int a, int b) {
    FUN_022cd6b0();
    FUN_022cd6bc(type, arg);
    if (type != 6) {
        if (type == 0x86) {
            FUN_022cdce4(a, b);
        }
    } else {
        FUN_022cd6c8(a, b);
    }
    FUN_022cd6d4();
}
