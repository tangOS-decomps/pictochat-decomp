// decomp: module=arm7 addr=0x022e2e4c name=FUN_022e2e4c
// flags: -O4,s -noThumb

// Copies n entries out of the table at +0x318, translating each one through
// FUN_022d8d6c on the way in and FUN_022d8d40 on the way out. Does nothing
// when the table has not been installed.

typedef struct State {
    char pad[0x318];
    unsigned char *f318;
} State;

extern int FUN_022d8d6c(unsigned char *src);
extern void FUN_022d8d40(unsigned char *dst, int v);

void FUN_022e2e4c(int index, int n, unsigned char *dst) {
    unsigned char *src = (*(State **)0x0380fff4)->f318;
    if (src == 0) return;
    src = src + index - 0x2a;
    while (n != 0) {
        int v = FUN_022d8d6c(src);
        src++;
        FUN_022d8d40(dst, v);
        dst++;
        n--;
    }
}
