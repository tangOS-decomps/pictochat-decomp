// decomp: module=arm7 addr=0x022e2eac name=FUN_022e2eac
// flags: -noThumb

// Runs the (a, b, c) request under the lock stored at +0x314 of the ARM7 state
// block, flushing pending work first.
//
// The three callees live in the Thumb-mode 0x0380xxxx region, so every call
// site goes through an ARM->Thumb veneer that the linker parked immediately
// after this function. The externs are named after the veneers themselves --
// that is what this translation unit's BL genuinely resolves to in the ROM --
// with the Thumb entry points they trampoline to noted here:
//     FUN_022e2efc -> 0x03801c44   (acquire)
//     FUN_022e2f08 -> 0x03802a68   (the request itself)
//     FUN_022e2f14 -> 0x03801c8c   (release)

extern void FUN_022e2efc(void *lock);
extern void FUN_022e2f14(void *lock);
extern void FUN_022e2df4(void);
extern void FUN_022e2f08(int a, int b, int c);

void FUN_022e2eac(int a, int b, int c)
{
    FUN_022e2efc(*(void **)(*(char **)0x0380fff4 + 0x314));
    FUN_022e2df4();
    FUN_022e2f08(a, b, c);
    FUN_022e2f14(*(void **)(*(char **)0x0380fff4 + 0x314));
}
