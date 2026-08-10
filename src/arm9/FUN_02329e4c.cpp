//cpp
// decomp: module=unk_autoload_0 addr=0x02329e4c name=FUN_02329e4c
#pragma thumb on
extern "C" {
struct State_023bd60c {
    unsigned char field_0[2];
    unsigned char index;
    unsigned char pad_3[9];
    int state;
    unsigned char pad_10[0x20];
    unsigned char *data;
};
extern volatile State_023bd60c G_023bd60c;
void FUN_0232a0b8(void);
void FUN_0232b6a4(unsigned char *);
void FUN_0232a16c(void);
int FUN_02329e4c(void)
{
    if (G_023bd60c.state == 0) {
        FUN_0232a0b8();
        return 1;
    }
    if (G_023bd60c.state == 1) {
        FUN_0232b6a4(G_023bd60c.data + G_023bd60c.index * 0x10);
        FUN_0232a16c();
        return 1;
    }
    return 0;
}
}
