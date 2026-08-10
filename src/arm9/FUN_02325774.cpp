//cpp
// decomp: module=unk_autoload_0 addr=0x02325774 name=FUN_02325774
#pragma thumb on
#pragma opt_strength_reduction off

extern "C" {
struct Row_02325774 {
    unsigned short values[0x20];
};
extern Row_02325774 G_0239c114[];
extern void FUN_023314e8(void *, unsigned int);
extern void FUN_02336a84(int, int, unsigned int);

void FUN_02325774(void)
{
    int row;
    int column;
    for (row = 0; row < 10; row++) {
        for (column = 0; column < 0x20; column++) {
            G_0239c114[row].values[column] = (unsigned short)(row * 0x20 + column);
        }
    }
    FUN_023314e8(G_0239c114, 0x800);
    FUN_02336a84((int)G_0239c114, 0, 0x800);
}
}
