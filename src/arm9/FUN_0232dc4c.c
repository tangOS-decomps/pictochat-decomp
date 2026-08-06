// decomp: module=unk_autoload_0 addr=0x0232dc4c name=FUN_0232dc4c

// Guard wrapper: forwards all four args to FUN_0232dbd0 when the halfword at +8
// is zero. The pass-through keeps r1-r3 live from entry to the bl, which is what
// pushes the compare temp into r4 (a lone pointer arg compiles to r1 instead).

struct MyStruct {
    char pad[0x8];
    unsigned short f8;
};
extern void FUN_0232dbd0(struct MyStruct* p, int a, int b, int c);
void FUN_0232dc4c(struct MyStruct* p, int a, int b, int c) {
    if (p->f8 == 0) {
        FUN_0232dbd0(p, a, b, c);
    }
}
