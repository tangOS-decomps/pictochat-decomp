//cpp
// decomp: module=unk_autoload_0 addr=0x02327474 name=FUN_02327474
// flags: -O4,s

extern "C" {
extern unsigned char G_0239f15c[];
extern void FUN_0233746c(int, void *, int);

void FUN_02327474(void)
{
    int i = 0;

    do {
        if (G_0239f15c[i * 0x5c + 0x58] != 0 &&
            G_0239f15c[i * 0x5c + 0x59] == 0) {
            FUN_0233746c(0, G_0239f15c + i * 0x5c, 0x16);
            G_0239f15c[i * 0x5c + 0x58] = 0;
        }
        i++;
    } while (i < 10);
}
}
