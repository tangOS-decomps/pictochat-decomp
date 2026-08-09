//cpp
// decomp: module=unk_autoload_0 addr=0x0232b380 name=FUN_0232b380
// Matches mwccarm 2.0/sp1p6 through 2.0/sp2p4.
extern "C" {

typedef unsigned char u8;

typedef struct {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 pad_3;
    void *field_4;
    void *field_8;
    int field_c;
} FUN_0232b380_State;

typedef void *(*AllocFunc)(int size, int alignment);

extern void FUN_0233746c(int value, void *dest, int size);
extern void FUN_023314e8(void *dest, int size);
extern void FUN_02331dd4(void *entry);

void FUN_0232b380(FUN_0232b380_State *state, int value, int count)
{
    register FUN_0232b380_State *p;
    int i;
    int size;

    p = state;
    p->field_0 = value;
    p->field_1 = 0;
    p->field_2 = count;
    p->field_c = 0;
    if (*(AllocFunc *)0x023bd5fc != 0) {
        size = count * 0xe0;
        p->field_4 = (*(AllocFunc *)0x023bd5fc)(size, 0x20);
        p->field_8 = (*(AllocFunc *)0x023bd5fc)(count * 0x2c, 0x20);
        FUN_0233746c(0, p->field_4, size);
        FUN_023314e8(p->field_4, size);
        i = 0;
        if (count > 0) {
            size = i;
            do {
                FUN_02331dd4((u8 *)p->field_8 + size);
                i++;
                size += 0x2c;
            } while (i < count);
        }
    }
}

}
