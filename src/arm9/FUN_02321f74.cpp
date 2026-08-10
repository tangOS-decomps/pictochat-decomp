//cpp
// decomp: module=unk_autoload_0 addr=0x02321f74 name=FUN_02321f74
#pragma thumb on
struct State_0238e028 {
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    int field_14;
    int field_18;
};
extern "C" {
extern State_0238e028 G_0238e028;
extern void FUN_02322524(void);
extern void FUN_02321df4(void);
void FUN_02321f74(int value, int mode)
{
    FUN_02322524();
    FUN_02321df4();
    G_0238e028.field_14 = value;
    G_0238e028.field_18 = mode;
    if (mode == 2) {
        G_0238e028.field_04 = -14;
        G_0238e028.field_08 = 8;
    }
}
}
