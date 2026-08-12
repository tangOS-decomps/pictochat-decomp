// decomp: module=unk_autoload_0 addr=0x0232571c name=FUN_0232571c
#pragma thumb on

struct Obj_0232571c {
    char pad00[0x10];
    int field10;
    char pad14[0x24];
    int field38;
    int field3c;
    int field40;
    int field44;
};

extern void FUN_0233746c(int value, int address, int size);
extern int FUN_02327990(void);
extern void FUN_02325910(struct Obj_0232571c *self, int value, int flag);

void FUN_0232571c(struct Obj_0232571c *self)
{
    int value;

    FUN_0233746c(0, self->field10, self->field44);
    FUN_0233746c(0, self->field3c, self->field44);
    FUN_0233746c(0, self->field40, self->field44);
    FUN_0233746c(0, self->field38, self->field44);

    value = FUN_02327990();
    value += 5;
    FUN_02325910(self, value, 1);
}
