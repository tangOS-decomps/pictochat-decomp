// decomp: module=unk_autoload_0 addr=0x0232ef38 name=FUN_0232ef38
typedef struct Ent_ee54 {
    int a;
    int b;
} Ent_ee54;

extern Ent_ee54 G_023bee54[];
extern int FUN_02337f4c(int v);
extern void FUN_02337848(int mask, int lo, int hi);

void FUN_0232ef38(char *s, int v) {
    int i;
    *(int *)(s + 0x44) = v;
    for (i = 0; i < *(int *)(s + 0x50); i++) {
        unsigned char ch = s[0x54 + i];
        int r = FUN_02337f4c(*(int *)(s + 0x44) + G_023bee54[ch].b);
        FUN_02337848(1 << ch, (unsigned char)r, r >> 8);
    }
}
