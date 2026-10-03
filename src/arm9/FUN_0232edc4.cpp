//cpp
// decomp: module=unk_autoload_0 addr=0x0232edc4 name=FUN_0232edc4
#pragma thumb on
extern "C" {
extern void *FUN_0232e178(void *, int);
extern void FUN_0232ed94(void *);
extern void FUN_0232e13c(void *, void *);
extern void FUN_0232ed58(void *);

void *FUN_0232edc4(int value)
{
    void *obj = FUN_0232e178((void *)0x023be56c, 0);

    if (obj == 0) {
        obj = FUN_0232e178((void *)0x023be578, 0);
        if (value < *(unsigned char *)((char *)obj + 0x3d))
            return 0;
        FUN_0232ed94(obj);
    }

    FUN_0232e13c((void *)0x023be56c, obj);
    *(unsigned char *)((char *)obj + 0x3d) = (unsigned char)value;
    FUN_0232ed58(obj);
    return obj;
}
}
