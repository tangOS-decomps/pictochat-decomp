//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232b690 name=FUN_0232b690
struct T0232b690 { char pad[2]; unsigned char field2; char pad2; void *field4; };
void *FUN_0232b690(struct T0232b690 *s, unsigned int idx) {
    if (idx > s->field2) {
        return 0;
    }
    return (char *)s->field4 + idx * 0xe0;
}

}
