//cpp
// decomp: module=unk_autoload_0 addr=0x0232b09c name=FUN_0232b09c

extern "C" {
extern unsigned char G_023bd698[];
extern int FUN_0232981c(void);
extern void FUN_0232b0d0(void);
extern void FUN_02329bd8(int);

void FUN_0232b09c(char *packet)
{
    if (FUN_0232981c() == 0) {
        if (*(unsigned short *)(packet + 2) == 0) {
            if (*(int *)(G_023bd698 + 0x1c) != 0) {
                FUN_0232b0d0();
                return;
            }
        } else if (*(int *)(G_023bd698 + 0x1c) != 0) {
            FUN_02329bd8(0xc);
        }
    }
}
}
