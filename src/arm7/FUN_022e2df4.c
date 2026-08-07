// decomp: module=arm7 addr=0x022e2df4 name=FUN_022e2df4
// flags: -noThumb -O4,s

extern void FUN_022e2e34(volatile unsigned int *p);
extern void FUN_022e2e40(void);

void FUN_022e2df4(void)
{
    volatile unsigned int val;
    volatile unsigned int *p = (volatile unsigned int *)&val;
    do {
        while (1) {
            FUN_022e2e34(p);
            if ((val & 0x20) == 0) {
                break;
            }
            FUN_022e2e40();
        }
    } while ((val & 1) != 0);
}
