//cpp
// decomp: module=unk_autoload_0 addr=0x0233016c name=FUN_0233016c
#pragma thumb on
extern "C" {
extern void FUN_023301bc(int);
extern void FUN_0232efec(int, int, int, int, int, const void *, const void *);
extern const unsigned char G_02330249[];
extern const unsigned char G_02369d18[];
void FUN_0233016c(int a, int b, int c)
{
    FUN_023301bc(c);
    FUN_0232efec(a, b, 0, 32000, 2, G_02330249, G_02369d18);
}
}
