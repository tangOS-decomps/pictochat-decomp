// decomp: module=arm7 addr=0x022c1608 name=FUN_022c1608
// flags: -O4,s -noThumb
// NOTE: verify with --size 0x88, not the nominal 0x84 - the stated size
// excludes this function's own trailing literal pool word.

// Dispatches an incoming request (a0/a1) against the ARM7 state block. If
// the sub-state flag at +0x1fc is already set, forwards straight to
// FUN_022c1238 (passing the +0x1f4 sub-object) and raises event (2, 0x13).
// Otherwise probes readiness via FUN_022c56b0 on the +0x304 field: if ready,
// hands the request to FUN_022c105c; if not, falls back to the same
// FUN_022c1238 forward as the first case.

typedef struct Ctx {
    unsigned char pad[0x1fc];
    unsigned short state;   /* +0x1fc */
    unsigned char pad2[0x304 - 0x1fe];
    int field304;           /* +0x304 */
} Ctx;

extern void FUN_022c1238(void *a0, void *a1, void *a2);
extern void FUN_022c0e48(int a, int b);
extern int FUN_022c56b0(int a, void *b, int c);
extern void FUN_022c105c(void *a0, void *a1);

void FUN_022c1608(void *a0, void *a1)
{
    Ctx *ctx = *(Ctx **)0x0380fff4;

    if (ctx->state != 0) {
        FUN_022c1238(a0, (char *)ctx + 0x1f4, a1);
        FUN_022c0e48(2, 0x13);
    } else if (FUN_022c56b0(ctx->field304, a1, 0) != 0) {
        FUN_022c105c(a0, a1);
    } else {
        FUN_022c1238(a0, (char *)*(Ctx **)0x0380fff4 + 0x1f4, a1);
    }
}
