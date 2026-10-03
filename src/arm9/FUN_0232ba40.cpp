//cpp
// decomp: module=unk_autoload_0 addr=0x0232ba40 name=FUN_0232ba40
extern "C" unsigned int G_023bd814[];
extern "C" unsigned char G_023bd864[];
extern "C" int FUN_0232a4e8(void *);
extern "C" int FUN_0232b794(void *, unsigned int, unsigned short);
extern "C" void FUN_0232a480();
extern "C" void FUN_02329bd8(int);
extern "C" void FUN_0232bd8c();
struct Input {unsigned int a[3]; unsigned int buffer; unsigned short size;};
extern "C" void FUN_0232ba40(Input *p) {
  if (!FUN_0232a4e8(p)) {
    if (!FUN_0232b794(G_023bd864, p->buffer, p->size)) { FUN_0232a480(); FUN_02329bd8(12); return; }
    if (!G_023bd814[14]) FUN_0232bd8c();
  }
}
