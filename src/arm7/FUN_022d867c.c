// decomp: module=arm7 addr=0x022d867c name=FUN_022d867c
// flags: -O4,s -noThumb

extern void FUN_022e2e4c(int index, int count, void *buf);
extern int FUN_022d8e04(unsigned int byte, int acc);

int FUN_022d867c(void)
{
    unsigned int buf;
    int n;
    unsigned int i;
    int acc;

    acc = 0;
    buf = 0;
    for (i = 0, n = 0x64; i < 0x69; i++, n++) {
        FUN_022e2e4c(n, 1, &buf);
        if (i == 1) {
            buf &= 0x80;
        }
        acc = FUN_022d8e04(buf & 0xff, acc);
    }
    return acc;
}
