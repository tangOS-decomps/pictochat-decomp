//cpp
// decomp: module=unk_autoload_0 addr=0x0232b6b0 name=FUN_0232b6b0
#pragma thumb on
struct State_0232b6b0 {
    unsigned char first;
    unsigned char active;
    volatile unsigned char count;
    unsigned char pad;
    void *buffer;
};
extern "C" {
extern void FUN_0232b6a4(State_0232b6b0 *);
extern void FUN_0233746c(int, void *, unsigned int);
extern void FUN_023314e8(void *, unsigned int);
void FUN_0232b6b0(State_0232b6b0 *state)
{
    FUN_0232b6a4(state);
    state->active = 0;
    unsigned int size = state->count * 0xe0;
    FUN_0233746c(0, state->buffer, size);
    FUN_023314e8(state->buffer, state->count * 0xe0);
}
}
