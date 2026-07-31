// decomp: module=unk_autoload_0 addr=0x02320b80 name=FUN_02320b80
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
