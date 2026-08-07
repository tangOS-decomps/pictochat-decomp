// decomp: module=arm7 addr=0x022d9bf0 name=FUN_022d9bf0
extern int FUN_037c9084(int lock);
extern void FUN_037c904c(int token);
extern void FUN_022da1e4(int id);

typedef struct Entry {
    char pad[0x16];
    unsigned short uses;
    unsigned short cur;
    unsigned short def;
} Entry;

void FUN_022d9bf0(unsigned short *req)
{
    int token;
    int id;
    Entry *e;

    id = req[1];
    e = &(*(Entry **)(*(int *)0x0380fff4 + 0x31c))[id];
    token = FUN_037c9084(0x01000000);

    if (*(unsigned short *)(*(int *)0x0380fff4 + 0x350) == 1 && e->uses == 1) {
        FUN_022da1e4(id);
    }
    e->uses--;
    FUN_037c904c(token);
}
