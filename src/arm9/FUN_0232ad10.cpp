//cpp
// decomp: module=unk_autoload_0 addr=0x0232ad10 name=FUN_0232ad10
extern "C" void FUN_02337584(void*,void*,unsigned);
extern "C" void FUN_0232ad44(void*);
struct S { unsigned a,b,c; void *data; unsigned short count; };
extern "C" void FUN_0232ad10(S *self) {
 unsigned short header[2];
 if(self->count) {
  FUN_02337584(self->data,header,4);
  switch(header[0]) {
   case 4: FUN_0232ad44(self->data); break;
   case 5: break;
   case 6: break;
  }
 }
}
