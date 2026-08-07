//cpp
// decomp: module=arm7 addr=0x022d80f8 name=FUN_022d80f8
// flags: -O4,s -noThumb
typedef unsigned short u16;

extern "C" volatile u16 G_04808094;
extern "C" void FUN_037c8430(void);

extern "C" void FUN_022d80f8(void)
{
    if ((G_04808094 & 0x8000) == 0) {
        FUN_037c8430();
    }
}
