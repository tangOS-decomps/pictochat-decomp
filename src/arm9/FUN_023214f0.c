// decomp: module=unk_autoload_0 addr=0x023214f0 name=FUN_023214f0
#pragma thumb on
struct Item {
    char pad[0x28];
    unsigned char flag;
};
extern void FUN_02321488(struct Item *);
extern struct Item *FUN_0232def8(void *, struct Item *);

void FUN_023214f0(void *obj) {
    struct Item *it = 0;
    goto loop_check;
loop_body:
    if (it->flag == 0) {
        FUN_02321488(it);
    }
loop_check:
    it = FUN_0232def8(obj, it);
    if (it != 0) goto loop_body;
}
