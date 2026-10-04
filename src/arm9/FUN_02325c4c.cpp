//cpp
// decomp: module=unk_autoload_0 addr=0x02325c4c name=FUN_02325c4c
extern "C" int FUN_02327990(void);
extern "C" int FUN_02325c4c(int x,int y) {
 if(x>=24 && x<252 && y>=18 && y<98) {
  if(y<34 && x<FUN_02327990()+24) return 0;
  return 1;
 }
 return 0;
}
