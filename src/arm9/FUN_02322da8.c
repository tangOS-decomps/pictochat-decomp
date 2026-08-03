// decomp: module=unk_autoload_0 addr=0x02322da8 name=FUN_02322da8
struct MyStruct {
    char pad[0x34];
    int val;
};
extern struct MyStruct G_0238edf8;
int FUN_02322da8(void) {
    return G_0238edf8.val;
}
