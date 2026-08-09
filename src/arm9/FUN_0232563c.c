// decomp: module=unk_autoload_0 addr=0x0232563c name=FUN_0232563c
#pragma thumb on
typedef struct {
    char pad[0x40];
    int f40;
    int f44;
} Ctx0232563c;

extern void FUN_023314e8(int, int);
extern int FUN_02336c60(int, int, int);

void FUN_0232563c(Ctx0232563c *ctx)
{
    FUN_023314e8(ctx->f40, ctx->f44);
    FUN_02336c60(ctx->f40, 0, ctx->f44);
}
