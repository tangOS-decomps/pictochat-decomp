import os

draft_bodies = {
    'FUN_02321c58.cpp': """// decomp: module=unk_autoload_0 addr=0x02321c58 name=FUN_02321c58
extern "C" {
    extern int G_02321c58[];
    int *FUN_02321c58(void) {
        return G_02321c58;
    }
}
""",
    'FUN_02321c60.cpp': """// decomp: module=unk_autoload_0 addr=0x02321c60 name=FUN_02321c60
extern "C" {
    extern int G_02321c60[];
    int *FUN_02321c60(void) {
        return G_02321c60;
    }
}
""",
    'FUN_02321c68.cpp': """// decomp: module=unk_autoload_0 addr=0x02321c68 name=FUN_02321c68
extern "C" {
    extern int G_02321c68[];
    int *FUN_02321c68(void) {
        return G_02321c68;
    }
}
""",
    'FUN_02321cf8.cpp': """// decomp: module=unk_autoload_0 addr=0x02321cf8 name=FUN_02321cf8
extern "C" {
    extern int G_02321cf8[];
    void FUN_02321cf8(int v) {
        G_02321cf8[0] = v;
    }
}
""",
    'FUN_02321d04.cpp': """// decomp: module=unk_autoload_0 addr=0x02321d04 name=FUN_02321d04
extern "C" {
    extern int G_02321d04;
    extern int F_02321d04(int, int);
    int FUN_02321d04(int a) {
        return F_02321d04(a, G_02321d04);
    }
}
""",
    'FUN_02321fd4.cpp': """// decomp: module=unk_autoload_0 addr=0x02321fd4 name=FUN_02321fd4
extern "C" {
    extern int G_02321fd4[];
    void FUN_02321fd4(void) {
        G_02321fd4[9] = 1;
    }
}
""",
    'FUN_02321fe0.cpp': """// decomp: module=unk_autoload_0 addr=0x02321fe0 name=FUN_02321fe0
extern "C" {
    extern int G_02321fe0[];
    int FUN_02321fe0(void) {
        return G_02321fe0[9];
    }
}
""",
    'FUN_02321fec.cpp': """// decomp: module=unk_autoload_0 addr=0x02321fec name=FUN_02321fec
extern "C" {
    struct S_02321fec { char pad[0x14]; int f14; };
    extern struct S_02321fec G_02321fec;
    int FUN_02321fec(void) {
        return G_02321fec.f14 != -1;
    }
}
"""
}

for fname, body in draft_bodies.items():
    fpath = f'drafts/arm9/{fname}'
    with open(fpath, 'w') as f: f.write(body)
    print(f"Updated draft: {fpath}")
