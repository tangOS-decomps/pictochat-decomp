//cpp
// decomp: module=unk_autoload_0 addr=0x02322cd8 name=FUN_02322cd8
#pragma thumb on
extern "C" {
extern int FUN_02334564(char *, const char *, ...);
extern int G_0238ede0[];
extern char G_0233ae48[];
extern char G_0233ae58[];

void FUN_02322cd8(void)
{
    int v;
    int next;

    v = G_0238ede0[2] + 1;
    G_0238ede0[2] = v;

    if (v > 10) {
        G_0238ede0[2] = 0;

        v = G_0238ede0[3];
        next = v + 1;
        G_0238ede0[3] = next;

        if (next == G_0238ede0[1])
            G_0238ede0[3] = next + 1;

        if (G_0238ede0[3] > 15)
            G_0238ede0[3] = 3;
    }

    char buf[0x20];
    FUN_02334564(buf, G_0233ae48, G_0238ede0[3]);
    FUN_02334564(buf, G_0233ae58, G_0238ede0[1]);
}
}
