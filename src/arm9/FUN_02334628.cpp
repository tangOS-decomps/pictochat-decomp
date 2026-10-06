//cpp
// decomp: module=unk_autoload_0 addr=0x02334628 name=FUN_02334628
// verify: python tools/match.py --c src/arm9/FUN_02334628.cpp --func FUN_02334628 --addr 0x02334628 --size 0x32 --module unk_autoload_0 --version 2.0/sp1

// Copy a bounded halfword string and pad the remaining destination with zeroes.

#pragma thumb on
extern "C" {
unsigned short *FUN_02334628(unsigned short *dst,const unsigned short *src,unsigned n) {
 volatile unsigned short *d=dst;
 while(n) {
  if((*d++=*src++)==0) {
   if(--n==0) return dst;
   do {*d++=0;} while(--n);
   return dst;
  }
  --n;
 }
 return dst;
}
}
