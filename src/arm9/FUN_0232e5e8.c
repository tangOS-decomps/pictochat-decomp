// decomp: module=unk_autoload_0 addr=0x0232e5e8 name=FUN_0232e5e8
#pragma thumb on
#pragma opt_propagation off

extern void FUN_0232e260(void *dst, void *src);
extern void FUN_0232e27c(void *dst, void *src);
extern void FUN_0232e514(void *dst, void *src);

void FUN_0232e5e8(char *a, char *b)
{
    char local[8];
    char *q;
    char *p;

    q = b;
    p = a;
    q -= 0x10;
    p += 0x24;

    FUN_0232e260(local, q);
    FUN_0232e27c(p + 8, q);
    FUN_0232e514(p, local);
}
