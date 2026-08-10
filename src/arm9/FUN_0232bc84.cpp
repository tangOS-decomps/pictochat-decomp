//cpp
// decomp: module=unk_autoload_0 addr=0x0232bc84 name=FUN_0232bc84

extern "C" {
extern unsigned char G_023bd814[];
extern unsigned char G_023bd854[];
extern void FUN_0232b854(char *);
extern void FUN_0232bd8c(void);

void FUN_0232bc84(char *packet)
{
    if (*(unsigned short *)G_023bd814 == *(unsigned short *)(packet + 0x12)) {
        *(unsigned short *)G_023bd814 = 0xffff;
        if (*(int *)(G_023bd814 + 0x38) != 0) {
            if (*(int *)(G_023bd814 + 0x2c) != 0) {
                *(int *)(G_023bd814 + 0x38) = 3;
            } else {
                *(int *)(G_023bd814 + 0x38) = 0;
            }
        }
        *(int *)(G_023bd814 + 0x20) = -1;
        FUN_0232b854((char *)G_023bd854);
        FUN_0232bd8c();
    }
}
}
