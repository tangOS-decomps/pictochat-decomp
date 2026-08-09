// decomp: module=unk_autoload_0 addr=0x02338a3c name=FUN_02338a3c
#pragma thumb on
typedef struct {
    char pad[0x10];
    int *f10;
} Ctx02338a3c;

extern int FUN_0233895c(Ctx02338a3c *, int, int);

int FUN_02338a3c(Ctx02338a3c *ctx, int a, int b)
{
    int local[2];
    ctx->f10 = local;
    local[0] = a;
    local[1] = b;
    return FUN_0233895c(ctx, 0xe, 1);
}
