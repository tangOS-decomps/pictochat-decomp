// decomp: module=unk_autoload_0 addr=0x0232fdec name=FUN_0232fdec
#pragma thumb on

extern void *FUN_0232f558(void *);
extern int FUN_0232f74c(int);
extern void *FUN_02330558(int, int);
extern int FUN_0232feac(void *, int, int, int, void *, int, void *, int);

struct Item_0232fdec {
    int value;
    unsigned short field4;
    unsigned char pad6[2];
    unsigned char field8;
    unsigned char field9;
};

int FUN_0232fdec(void *arg0, void *arg1, int arg2)
{
    int *entry;
    struct Item_0232fdec *item;
    int handle;

    entry = (int *)FUN_0232f558(arg1);
    if (entry == 0)
        return 0;

    handle = FUN_0232f74c(entry[0]);
    if (handle == 0)
        return 0;

    item = (struct Item_0232fdec *)FUN_02330558(handle, arg2);
    if (item == 0)
        return 0;

    return FUN_0232feac(arg0, item->field9, item->field4, item->field8,
                        item, handle, arg1, arg2);
}
