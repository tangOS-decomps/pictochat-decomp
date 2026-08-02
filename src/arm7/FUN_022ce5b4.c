// decomp: module=arm7 addr=0x022ce5b4 name=FUN_022ce5b4
// flags: -noThumb
extern unsigned char G_023180dc[];
extern int func_023018a0(unsigned int avg);

int FUN_022ce5b4(void) {
    int i;
    unsigned int sum = 0;
    for (i = 0; i < 0x20; i++) {
        sum += G_023180dc[0x1554 + i];
    }
    return func_023018a0(sum >> 5);
}
