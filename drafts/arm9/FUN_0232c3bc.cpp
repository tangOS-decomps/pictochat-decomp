// decomp: module=unk_autoload_0 addr=0x0232c3bc name=FUN_0232c3bc
struct T0232c3bc { char pad[0x18]; int arr[1]; };
struct G0232c3bc { char pad[4]; struct T0232c3bc *field4; };
void FUN_0232c3bc(int idx, int val) {
    struct G0232c3bc *g = (struct G0232c3bc *)0x023bd8a0;
    g->field4->arr[idx] = val;
}
