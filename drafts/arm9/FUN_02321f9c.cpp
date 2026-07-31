// decomp: module=unk_autoload_0 addr=0x02321f9c name=FUN_02321f9c
extern void FUN_02321f74(void);
extern int FUN_02321684(void *, void *, int);
struct S { char pad[0x14]; int f14; };
extern struct S G;
extern int G2[];
extern int G3[];
void FUN_02321f9c(void) {
    FUN_02321f74();
    FUN_02321684(G2, G3, G.f14);
}
