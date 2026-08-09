//cpp
// decomp: module=unk_autoload_0 addr=0x02329fac name=FUN_02329fac

#pragma thumb on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
struct Entry_02329fac {
    u16 active;
    u16 field2;
    u16 high;
    u16 low;
    u16 id;
};

extern char G_023bd60c[];
extern Entry_02329fac *FUN_0232b690(void *, unsigned int);
extern void FUN_0232a620(Entry_02329fac *, int);

int FUN_02329fac(void)
{
    u8 index;
    Entry_02329fac *best;
    best = 0;
    index = 0;
    u32 wanted = 0xbd8a;
    do {
        Entry_02329fac *entry = FUN_0232b690(
            (char *)*(void **)(G_023bd60c + 0x30) +
                (u8)G_023bd60c[2] * 0x10,
            index);
        if (entry->active != 0) {
            if (entry->id == wanted) {
                best = entry;
                break;
            }
            if (*(volatile u16 *)&entry->id == 0x2348) {
                if (best != 0) {
                    if ((((u32)entry->high << 16) | entry->low) >
                        (((u32)best->high << 16) | best->low)) {
                        best = entry;
                    }
                } else {
                    best = entry;
                }
            }
        }
        index = (u8)(index + 1);
    } while (index < 8);

    if (best != 0) {
        FUN_0232a620((Entry_02329fac *)best, 1);
        return 1;
    }
    return 0;
}
}
