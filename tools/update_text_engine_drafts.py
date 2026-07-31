import os

draft_bodies = {
    'FUN_023209ec.cpp': """// decomp: module=unk_autoload_0 addr=0x023209ec name=FUN_023209ec
extern "C" {
    extern int G[];
    extern int F(int *);
    int FUN_023209ec(void) {
        G[2] = 2;
        return F(G);
    }
}
""",
    'FUN_02320a00.cpp': """// decomp: module=unk_autoload_0 addr=0x02320a00 name=FUN_02320a00
extern "C" {
    extern int G[];
    void FUN_02320a00(void) {
        G[2] = 1;
    }
}
""",
    'FUN_02320a0c.cpp': """// decomp: module=unk_autoload_0 addr=0x02320a0c name=FUN_02320a0c
extern "C" {
    extern int G[];
    extern void FUN_02320a20(int);
    void FUN_02320a0c(void) {
        int v = G[2];
        if (v == 1) {
            FUN_02320a20(v);
        }
    }
}
""",
    'FUN_02320b80.cpp': """// decomp: module=unk_autoload_0 addr=0x02320b80 name=FUN_02320b80
extern "C" {
    struct S1 { char pad[0x30]; int a; int b; char pad2[0x60 - 0x34 - 4]; int c; };
    struct S0 { int a; int b; };
    extern struct S1 G1;
    extern struct S0 G0;
    void FUN_02320b80(void) {
        G1.a = 0;
        G0.a = 0;
        G1.b = 0;
        G0.b = 0;
        G1.c = 0;
    }
}
"""
}

for fname, body in draft_bodies.items():
    fpath = f'drafts/arm9/{fname}'
    with open(fpath, 'w') as f: f.write(body)
    print(f"Updated draft: {fpath}")
