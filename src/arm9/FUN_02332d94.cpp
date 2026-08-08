//cpp
// decomp: module=unk_autoload_0 addr=0x02332d94 name=FUN_02332d94
// verify: python tools/match.py --c src/arm9/FUN_02332d94.cpp --func FUN_02332d94 --addr 0x02332d94 --size 0x10 --module unk_autoload_0 --version 2.0/sp1

// Dispatches through the table at G_02369e9c: slot 2 points at a record whose
// second word is the handler; both of the caller's arguments ride through.

#pragma thumb on
extern "C" {
typedef void (*Handler)(int, int);
extern Handler *G_02369e9c[];
void FUN_02332d94(int a, int b) { G_02369e9c[2][1](a, b); }
}
