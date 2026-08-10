//cpp
// decomp: module=unk_autoload_0 addr=0x0232d32c name=FUN_0232d32c
#pragma thumb on
extern "C" {
extern void FUN_02338df8(void *, unsigned short, unsigned short, unsigned char,
                         unsigned char, unsigned short, unsigned short,
                         unsigned char, unsigned char);
extern void FUN_02338cbc(void *);
void FUN_0232d32c(void)
{
    unsigned char object[8];
    volatile unsigned short *first = (volatile unsigned short *)0x02fffcd8;
    volatile unsigned short *second = (volatile unsigned short *)0x02fffcda;
    volatile unsigned char *third = (volatile unsigned char *)0x02fffcdc;
    volatile unsigned char *time = (volatile unsigned char *)0x02fffcdd;
    volatile unsigned short *time_1 = (volatile unsigned short *)0x02fffcde;
    volatile unsigned short *time_3 = (volatile unsigned short *)0x02fffce0;
    FUN_02338df8(object,
                 *first,
                 *second,
                 *third, time[0],
                 *time_1,
                 *time_3,
                 time[5], time[6]);
    FUN_02338cbc(object);
}
}
