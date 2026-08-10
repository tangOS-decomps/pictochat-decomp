//cpp
// decomp: module=unk_autoload_0 addr=0x0232bccc name=FUN_0232bccc

extern "C" {
extern int FUN_0232981c(void);
extern void FUN_0232bc84(char *);
extern void FUN_0232bb9c(char *);

void FUN_0232bccc(char *packet)
{
    if (FUN_0232981c() == 0 && *(unsigned short *)(packet + 2) == 0) {
        unsigned short type = *(unsigned short *)(packet + 4);
        if (type == 7)
            return;
        if (type == 9)
            goto type9;
        if (type != 0x15)
            return;
        FUN_0232bb9c(packet);
        return;
type9:
        FUN_0232bc84(packet);
    }
}
}
