//cpp
// decomp: module=unk_autoload_0 addr=0x02321770 name=FUN_02321770
// verify: python tools/match.py --c src/arm9/FUN_02321770.cpp --func FUN_02321770 --addr 0x02321770 --size 0x26 --module unk_autoload_0 --version 2.0/sp1

// Walks the collection and runs the pass over every entry whose flag at +0x28
// is still clear.

#pragma thumb on
extern "C" {
typedef struct It {
    char pad[0x28];
    unsigned char flag;
} It;
extern It *FUN_0232e178(void *, It *);
extern void FUN_02321708(It *);
void FUN_02321770(void *s)
{
    It *p = 0;

    goto step;
body:
    if (p->flag == 0) FUN_02321708(p);
step:
    p = FUN_0232e178(s, p);
    if (p != 0) goto body;
}
}
