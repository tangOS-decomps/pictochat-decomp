// decomp: module=arm7 addr=0x022c864c name=FUN_022c864c

void FUN_022c864c(char *state, void *value)
{
    *(int *)(state + 0x10) = 0xFFFE9680;
    *(unsigned char *)(state + 2) = 0;
    *(void **)(state + 0x34) = value;
    *(unsigned short *)(state + 0x30) = 0;
    *(unsigned short *)(state + 0x2E) = 0;
    *(unsigned char *)(state + 3) |= 2;
    *(unsigned char *)(state + 3) =
        (*(unsigned char *)(state + 3) & ~1) | 1;
}
