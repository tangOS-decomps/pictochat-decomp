//cpp
// decomp: module=unk_autoload_0 addr=0x0232dec8 name=FUN_0232dec8
#pragma thumb on

extern "C" {
extern void *FUN_0232de74(void *, void *, int *, int);

int FUN_0232dec8(void *self, void *entry, int arg)
{
    int maximum = 0;
    int value = 0;
    while (entry != 0) {
        entry = FUN_0232de74(self, entry, &value, arg);
        if (maximum < value) {
            maximum = value;
        }
    }
    return maximum;
}
}
