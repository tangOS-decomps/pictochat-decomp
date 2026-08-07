// decomp: module=arm7 addr=0x022c5a50 name=FUN_022c5a50
// flags: -O4,s -noThumb
//
// Caches the two per-id region answers into the shared-WRAM tables at
// 0x02fffdc4 and 0x02fffda0, so later queries can read them without
// recomputing.

extern void *FUN_022c5ab4(int id);
extern void *FUN_022c5b30(int id);

void FUN_022c5a50(int id)
{
    ((void **)0x02fffdc4)[id] = FUN_022c5ab4(id);
    ((void **)0x02fffda0)[id] = FUN_022c5b30(id);
}
