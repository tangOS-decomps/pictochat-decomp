// decomp: module=arm7 addr=0x022c0f78 name=FUN_022c0f78
// flags: -O4,s -noThumb
// Pulls one entry out of the queue hanging off the global context at +0x308
// into a stack temporary, hands it to the handler, then signals completion
// with event 3 / code 0xc.
// NOTE: verify with --size 0x3c, not funcs.json's 0x38 - the stated size
// excludes this function's own trailing pool word.
typedef struct Ctx {
    char pad[0x308];
    void *queue;
} Ctx;

extern Ctx *G_0380fff4;
extern void FUN_022c573c(void *queue, void *out, int flag);
extern void FUN_022c0fb4(void *msg);
extern void FUN_022c0e48(int a, int b);

void FUN_022c0f78(void) {
    void *msg;

    FUN_022c573c(G_0380fff4->queue, &msg, 1);
    FUN_022c0fb4(&msg);
    FUN_022c0e48(3, 0xc);
}
