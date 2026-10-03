//cpp
// decomp: module=unk_autoload_0 addr=0x02325c88 name=FUN_02325c88
extern "C" unsigned FUN_02325c88(int x,int y,int a,int b){int dx=a-x; int dy=b-y;unsigned *p=(unsigned*)0x040002b8;volatile unsigned short *q=(volatile unsigned short*)0x040002b0;*p=dx*dx+dy*dy;while(*q&0x8000){}return *(volatile unsigned*)0x040002b4;}
