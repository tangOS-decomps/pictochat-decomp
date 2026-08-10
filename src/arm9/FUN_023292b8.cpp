//cpp
// decomp: module=unk_autoload_0 addr=0x023292b8 name=FUN_023292b8
#pragma thumb on

struct Context_023292b8 {
    unsigned char bytes[0x54];
    int state;
};

extern "C" {
extern unsigned char *FUN_02329994(void);
extern int memcmp(unsigned char *, unsigned char *, unsigned int);

unsigned char *FUN_023292b8(Context_023292b8 *self)
{
    if (self->state == 2) {
        bool equal = memcmp(FUN_02329994(), self->bytes, 6) == 0;
        if (equal == false) {
            return self->bytes + 6;
        }
    }
    return 0;
}
}
