//cpp
// decomp: module=unk_autoload_0 addr=0x0232153c name=FUN_0232153c
// verify: python tools/match.py --c src/arm9/FUN_0232153c.cpp --func FUN_0232153c --addr 0x0232153c --size 0x2c --module unk_autoload_0 --version 2.0/sp1

// Apply the drawing operation to each index in the requested range.

#pragma thumb on
extern "C" {
void FUN_0232148c(unsigned,unsigned,int,unsigned,int,unsigned);
void FUN_0232153c(unsigned p,unsigned q,int start,unsigned t,int end,unsigned u) {
 goto check;
 loop:
 FUN_0232148c(p,q,start,t,start,u);
 ++start;
 check:
 if(start<end) goto loop;
}
}
