//cpp
// decomp: module=unk_autoload_0 addr=0x02325804 name=FUN_02325804
extern "C" void *FUN_02325cb4(void);
extern "C" int FUN_02323834(void);
extern "C" void FUN_02325834(void*,unsigned);
extern "C" unsigned FUN_02323f00(void*);
extern "C" void FUN_0232598c(void*,unsigned);
extern "C" void FUN_02325804(void *self) {
 void *p=FUN_02325cb4();
 if(FUN_02323834()==1 && p) {
  FUN_02325834(self,0);
  FUN_0232598c(self,FUN_02323f00(p));
 }
}
