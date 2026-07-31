//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x0232dfa8 name=FUN_0232dfa8
struct T0232dfa8 { char pad[6]; unsigned short count; };
void *FUN_0232dfa8(struct T0232dfa8 *s, int idx) {
    unsigned short count = s->count;
    char *base = (char *)s + 8;
    if (idx < 0 || idx >= count) {
        return 0;
    }
    return base + idx * 0xc;
}

}
