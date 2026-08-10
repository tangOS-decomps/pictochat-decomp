//cpp
// decomp: module=unk_autoload_0 addr=0x02334598 name=FUN_02334598
#pragma thumb on

extern "C" char *FUN_02334598(char *dst, const char *src, unsigned int n)
{
    char *d = dst;
    char c;
    if (n != 0) {
        do {
            if ((*d++ = *src++) == 0) {
                if (--n != 0) {
                    do {
                        *d++ = 0;
                    } while (--n != 0);
                }
                break;
            }
        } while (--n != 0);
    }
    return dst;
}
