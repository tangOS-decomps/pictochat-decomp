// decomp: module=unk_autoload_0 addr=0x023234c0 name=FUN_023234c0
struct S { char pad[0xc]; int fc; char pad2[0x30 - 0xc - 4]; short f30; };
extern struct S G;
void FUN_023234c0(void) {
    G.f30 = 0;
    G.fc = 0;
}
