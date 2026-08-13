// decomp: module=unk_autoload_0 addr=0x02325804 name=FUN_02325804

// When FUN_02323834 reports state 1 and FUN_02325cb4 hands back a live handle,
// resets slot `a` and re-points it at the handle's FUN_02323f00 value.

#pragma thumb on
extern int FUN_02325cb4(void);
extern int FUN_02323834(void);
extern void FUN_02325834(int, int);
extern int FUN_02323f00(int);
extern void FUN_0232598c(int, int);

void FUN_02325804(int a)
{
    int p = FUN_02325cb4();
    if (FUN_02323834() == 1 && p != 0) {
        FUN_02325834(a, 0);
        FUN_0232598c(a, FUN_02323f00(p));
    }
}
