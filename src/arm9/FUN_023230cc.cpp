//cpp
// decomp: module=unk_autoload_0 addr=0x023230cc name=FUN_023230cc
// verify: python tools/match.py --c src/arm9/FUN_023230cc.cpp --func FUN_023230cc --addr 0x023230cc --size 0x14 --module unk_autoload_0 --version 2.0/sp1

// Tail-calls the worker with the handle parked at G_0238ef04+4 and a fixed
// count of 4, forwarding the caller's own argument as the second parameter.

#pragma thumb on
extern "C" {
extern void FUN_0232e5c8(int, int, int);
extern int G_0238ef04[];
void FUN_023230cc(int a) { FUN_0232e5c8(G_0238ef04[1], a, 4); }
}
