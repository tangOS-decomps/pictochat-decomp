// decomp: module=unk_autoload_0 addr=0x0232a064 name=FUN_0232a064
#pragma thumb on

struct T0232a064 {
    char pad[0x30];
    void *data;
};

struct T0232a064Entry {
    unsigned short kind;
    char pad[6];
    unsigned short value;
};

extern struct T0232a064 G_023bd60c;
extern struct T0232a064Entry *FUN_0232b690(struct T0232a064 *, unsigned int);

void *FUN_0232a064(int a)
{
    unsigned char i;
    struct T0232a064Entry *p;
    int offset = a << 4;

    for (i = 0; i < 8; i++) {
        p = FUN_0232b690((struct T0232a064 *)((char *)G_023bd60c.data + offset), i);
        if (p->kind != 0 && p->value == 0xbd8a)
            return p;
    }

    for (i = 0; i < 8; i++) {
        p = FUN_0232b690((struct T0232a064 *)((char *)G_023bd60c.data + offset), i);
        if (p->kind != 0)
            return p;
    }
    return 0;
}
