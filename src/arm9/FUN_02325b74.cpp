//cpp
// decomp: module=unk_autoload_0 addr=0x02325b74 name=FUN_02325b74
#pragma thumb on
#pragma opt_strength_reduction off
// flags: -O4,s

extern "C" {
extern unsigned int FUN_02327990(void);
extern void FUN_0233746c(int, int, int);
extern int FUN_02325c2c(int, int);

int FUN_02325b74(int ptr, int *count, int clear)
{
    int size = ((int)((FUN_02327990() & ~7U) + 24) / 8) * 32;
    if (clear != 0) {
        FUN_0233746c(0, ptr, size);
        FUN_0233746c(0, ptr + 0x400, size);
    }

    *count = 5;
    goto first_check;
first_body:
        ptr += 2 << 10;
        *count = *count - 1;
first_check:
    if (FUN_02325c2c(ptr, 2 << 10) != 0 && *count != 0) {
        goto first_body;
    }
    if (*count == 0) {
        return 0;
    }
    if (*count < 1) {
        goto done;
    }
    goto second_check;
    second_body:
        *count = *count - 1;
    second_check:
    if (FUN_02325c2c(ptr + (*count - 1) * (2 << 10), 2 << 10) != 0) {
        goto second_body;
    }
    if (clear != 0 &&
        (FUN_02325c2c(ptr, size) == 0 || FUN_02325c2c(ptr + 0x400, size) == 0)) {
        *count = *count + 1;
        ptr -= 0x800;
    }
done:
    return ptr;
}
}
