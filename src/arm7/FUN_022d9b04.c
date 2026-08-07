// decomp: module=arm7 addr=0x022d9b04 name=FUN_022d9b04
// flags: -noThumb

// Runs a beacon/scan submission against the state block's +0x1ac descriptor
// while holding lock 0x01000000: if the descriptor's counter at +0x08 is zero
// the pool is (re)initialised first, then the caller's request is handed to
// FUN_037c5a18 and the lock is released.

extern int FUN_037c9084(int lock);
extern void FUN_037c904c(int token);
extern void FUN_022da128(int arg);
extern void FUN_037c5a18(void *req, void *desc, int arg);

void FUN_022d9b04(void *req, int arg)
{
    unsigned short *desc = (unsigned short *)(*(int *)0x0380fff4 + 0x1ac);
    int token = FUN_037c9084(0x01000000);

    if (desc[4] == 0) {
        FUN_022da128(0);
    }
    FUN_037c5a18(req, desc, arg);
    FUN_037c904c(token);
}
