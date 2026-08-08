//cpp
// decomp: module=unk_autoload_0 addr=0x02331838 name=FUN_02331838
// verify: python tools/match.py --c src/arm9/FUN_02331838.cpp --func FUN_02331838 --addr 0x02331838 --size 0x1c --module unk_autoload_0 --version 2.0/sp1
// flags: -noThumb

// Vectors through the handler table at G_02369e08.

extern "C" {
typedef void (*Fn)(int);
extern Fn G_02369e08[];
void FUN_02331838(int i, int a) { G_02369e08[i](a); }
}
