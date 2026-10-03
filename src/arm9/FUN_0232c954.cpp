//cpp
// decomp: module=unk_autoload_0 addr=0x0232c954 name=FUN_0232c954
#pragma thumb on
extern "C" {
struct State_0232c954 {
    int unk0;
    unsigned char *data;
};

extern State_0232c954 *FUN_0232c4d0(void);
extern int FUN_0232c520(int, ...);
extern void FUN_023314cc(void *, int);

unsigned int FUN_0232c954(void)
{
    State_0232c954 *s = FUN_0232c4d0();

    if (FUN_0232c520(2, 7, 8) != 0)
        return 0;

    FUN_023314cc(s->data + 0x0c, 4);
    if (*(int *)(s->data + 0x0c) == 1)
        return 0;

    FUN_023314cc(s->data + 0x3c, 4);
    return (*(unsigned short *)(s->data + 0x3c) + 0x1f) & ~0x1f;
}
}
