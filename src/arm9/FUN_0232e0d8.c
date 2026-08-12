// decomp: module=unk_autoload_0 addr=0x0232e0d8 name=FUN_0232e0d8
#pragma thumb on

struct Link0232e0d8 {
    void *f0;
    void *f4;
};

struct List0232e0d8 {
    void *f0;
    void *f4;
    unsigned short f8;
    unsigned short fa;
};

extern void FUN_0232e090(struct List0232e0d8 *, void *);

void FUN_0232e0d8(struct List0232e0d8 *list, void *obj)
{
    struct Link0232e0d8 *link;

    if (list->f0 == 0) {
        FUN_0232e090(list, obj);
        return;
    }

    link = (struct Link0232e0d8 *)((char *)obj + list->fa);
    link->f0 = 0;
    link->f4 = list->f0;
    ((struct Link0232e0d8 *)((char *)list->f0 + list->fa))->f0 = obj;
    list->f0 = obj;
    list->f8 = list->f8 + 1;
}
