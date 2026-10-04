// decomp: module=unk_autoload_0 addr=0x02330ef4 name=FUN_02330ef4
extern char G_023c07c4[];
extern void FUN_0233108c(void);
extern void FUN_02331400(void *t);
extern void *FUN_02330b8c(void *list, void *t);
extern void FUN_02330c20(void *t);
extern void FUN_02330f6c(void *p);
extern void FUN_023310b0(void);
extern void FUN_02330fe8(void);
extern void FUN_02332274(void);

void FUN_02330ef4(void) {
    char *t = **(char ***)(G_023c07c4 + 8);
    FUN_0233108c();
    FUN_02331400(t);
    if (*(void **)(t + 0x78) != 0) {
        FUN_02330b8c(*(void **)(t + 0x78), t);
    }
    FUN_02330c20(t);
    *(int *)(t + 0x64) = 2;
    FUN_02330f6c(t + 0x9c);
    FUN_023310b0();
    FUN_02330fe8();
    FUN_02332274();
}
