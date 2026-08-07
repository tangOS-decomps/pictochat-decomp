// decomp: module=arm7 addr=0x022c69f8 name=FUN_022c69f8
// flags: -noThumb

// Installs the V-count-match IRQ handler at 0x037fe5c8, programs the 9-bit
// compare line from the caller's descriptor (+0x10) into REG_DISPSTAT's split
// LYC field (bits 15..8 plus bit 7), enables the V-count IRQ (bit 0x20) and
// unmasks IRQ source 4.

extern void FUN_022c4738(int mask, void *handler);
extern void FUN_022c486c(int mask);
extern void FUN_037fe5c8(void);

typedef struct VCount {
    char pad[0x10];
    short line;
} VCount;

void FUN_022c69f8(VCount *v)
{
    FUN_022c4738(4, (void *)FUN_037fe5c8);
    *(volatile unsigned short *)0x04000004 =
        (*(volatile unsigned short *)0x04000004 & 0x3f) |
        ((v->line & 0xff) << 8) | ((v->line & 0x100) >> 1);
    *(volatile unsigned short *)0x04000004 |= 0x20;
    FUN_022c486c(4);
}
