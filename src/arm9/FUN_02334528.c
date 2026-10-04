// decomp: module=unk_autoload_0 addr=0x02334528 name=FUN_02334528
typedef struct Ctx_4528 {
    char *buf;
    unsigned int size;
    unsigned int pos;
} Ctx_4528;

extern unsigned int FUN_02333f20(void (*put)(void), Ctx_4528 *ctx, const char *fmt, void *args);
extern void FUN_02334500(void);

unsigned int FUN_02334528(char *buf, unsigned int size, const char *fmt, void *args) {
    Ctx_4528 ctx;
    unsigned int n;
    ctx.pos = 0;
    ctx.buf = buf;
    ctx.size = size;
    n = FUN_02333f20(FUN_02334500, &ctx, fmt, args);
    if (buf != 0) {
        if (n < size) {
            buf[n] = 0;
        } else if (size != 0) {
            *(buf + size - 1) = 0;
        }
    }
    return n;
}
