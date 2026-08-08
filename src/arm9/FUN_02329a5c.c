// decomp: module=unk_autoload_0 addr=0x02329a5c name=FUN_02329a5c
extern int FUN_0232ca9c(void *, void (*)(void), unsigned short);
extern void FUN_02329bd8(int);
extern void FUN_02329a8c(void);

typedef struct {
    unsigned short version;
    unsigned short reserved;
    void *data;
} G_023BD5E0;

int FUN_02329a5c(void)
{
    void (*cb)(void) = FUN_02329a8c;
    G_023BD5E0 *g = (G_023BD5E0 *)0x023BD5E0;
    int result;

    do {
        result = FUN_0232ca9c(g->data, cb, g->version);
    } while (result == 4);

    if (result != 2) {
        FUN_02329bd8(0);
        return 0;
    }
    return 1;
}
