//cpp
// decomp: module=unk_autoload_0 addr=0x0232f7dc name=FUN_0232f7dc
extern "C" {

typedef struct FUN_0232f7dc_Item FUN_0232f7dc_Item;
typedef void (*FUN_0232f7dc_Callback)(void *self, void *arg1, void *arg2, void *arg3);

struct FUN_0232f7dc_Item {
    int field_0;
    int field_4;
    void *field_8;
    FUN_0232f7dc_Callback field_c;
    void *field_10;
    void *field_14;
    int field_18;
    int field_1c;
    char field_20[1];
};

extern FUN_0232f7dc_Item *FUN_0232e188(void *list, FUN_0232f7dc_Item *item);
extern void FUN_0232e13c(void *list, FUN_0232f7dc_Item *item);
extern void FUN_0232e734(void *object, int value);
extern void FUN_0232f8e8(void);
extern void FUN_0232f8c0(void *state);

void FUN_0232f7dc(void **state)
{
    FUN_0232f7dc_Item *outer;
    FUN_0232f7dc_Item *item;
    FUN_0232f7dc_Callback callback;
    int called;

    called = 0;
    outer = FUN_0232e188((char *)state + 4, 0);
    while (outer != 0) {
        item = FUN_0232e188(outer, 0);
        while (item != 0) {
            callback = item->field_c;
            if (callback != 0) {
                callback(item->field_20, item->field_8, item->field_10, item->field_14);
                called = 1;
            }
            item = FUN_0232e188(outer, item);
        }
        FUN_0232e13c((char *)state + 4, outer);
        outer = FUN_0232e188((char *)state + 4, 0);
    }
    FUN_0232e734(*state, 3);
    if (called != 0) {
        FUN_0232f8e8();
    }
    FUN_0232f8c0(state);
}

}
