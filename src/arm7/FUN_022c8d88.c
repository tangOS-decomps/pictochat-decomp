// decomp: module=arm7 addr=0x022c8d88 name=FUN_022c8d88
// flags: -O4,s

// Walks the child list hanging off +0x3c of `obj`, and for every child that is
// still active applies `value` (when non-negative), marks it dirty at +0x22 and
// kicks it.

#pragma thumb on

extern void FUN_022c8ea8(void *obj, int arg, int flag);
extern int FUN_022c8288(void *node);
extern void FUN_022c826c(void *node, unsigned char value);
extern void FUN_022c8280(void *node);

void FUN_022c8d88(void *obj, int arg, int value)
{
    char *node;

    FUN_022c8ea8(obj, arg, 0);
    for (node = *(char **)((char *)obj + 0x3c); node != 0;
         node = *(char **)(node + 0x50)) {
        if (FUN_022c8288(node) != 0) {
            if (value >= 0) {
                FUN_022c826c(node, (unsigned char)value);
            }
            *(unsigned char *)(node + 0x22) = 1;
            FUN_022c8280(node);
        }
    }
}
