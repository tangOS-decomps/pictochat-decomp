//cpp
// decomp: module=unk_autoload_0 addr=0x0233846c name=FUN_0233846c
extern "C" {

typedef unsigned char u8;

typedef struct FUN_0233846c_State FUN_0233846c_State;
struct FUN_0233846c_State {
    FUN_0233846c_State *field_0;
    int field_4;
    FUN_0233846c_State *field_8;
    unsigned int field_c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
};

extern int FUN_02332080(void);
extern void FUN_02332094(int state);
extern int FUN_0233844c(u8 value);
extern void FUN_02330f6c(void *object);

void FUN_0233846c(FUN_0233846c_State *state, int value)
{
    int irq;
    FUN_0233846c_State *node;
    FUN_0233846c_State **link;
    u8 kind;

    irq = FUN_02332080();
    node = state->field_8;
    if (node != 0) {
        link = &node->field_8;
        while (*link != 0) {
            if (*link == state) {
                *link = state->field_0;
                break;
            }
            link = &(*link)->field_0;
        }
        state->field_0 = 0;
    }
    kind = (u8)(state->field_c >> 8);
    if (FUN_0233844c(kind) == 0) {
        node->field_18 = kind;
        node->field_1c = value;
    }
    state->field_14 = value;
    state->field_c &= ~0xcf;
    FUN_02330f6c((char *)state + 0x18);
    FUN_02332094(irq);
}

}
