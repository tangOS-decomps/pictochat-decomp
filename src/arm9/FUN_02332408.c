// decomp: module=unk_autoload_0 addr=0x02332408 name=FUN_02332408
#pragma thumb on

extern void FUN_02330ffc(void *, void *);
extern void FUN_02330fb4(void *);
extern void FUN_02332494(void *);

struct Global_02332408 {
    void *field0;
    int flags;
    void *field8;
    unsigned char pad[0x4e8 - 0xc];
    void *callback;
};

extern struct Global_02332408 G_023c0ba0;

int FUN_02332408(void (*callback)(void *), int initialize)
{
    struct Global_02332408 *state = &G_023c0ba0;

    if (initialize != 0) {
        FUN_02330ffc((char *)state + 0x28, state->field8);
        state->callback = (void *)callback;
        state->flags |= 8;
        FUN_02330fb4((char *)state + 0x28);
    } else {
        callback(state);
        FUN_02332494(state);
    }

    if (initialize != 0)
        return 1;
    return *(int *)state->field0 == 0;
}
