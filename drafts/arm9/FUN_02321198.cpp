// decomp: module=unk_autoload_0 addr=0x02321198 name=FUN_02321198
extern int PTR[];
extern void F(int, void *, int);
struct S { char pad[0x24]; int flag; };
extern struct S G2;
void FUN_02321198(void) {
    F(0, PTR, 0x28);
    G2.flag = 1;
}
