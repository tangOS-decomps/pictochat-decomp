//cpp
// decomp: module=unk_autoload_0 addr=0x0232ac60 name=FUN_0232ac60
#pragma thumb on

struct Context_0232ac60 {
    unsigned char pad_00[0xc];
    void *source;
    unsigned short active;
};

extern "C" {
extern void FUN_02337584(void *, const void *, unsigned int);
extern void FUN_0232ac90(void *);

void FUN_0232ac60(Context_0232ac60 *self)
{
    unsigned short header[2];
    if (self->active != 0) {
        FUN_02337584(self->source, header, 4);
        if (header[0] != 4 && header[0] != 5 && header[0] == 6) {
            FUN_0232ac90(self->source);
        }
    }
}
}
