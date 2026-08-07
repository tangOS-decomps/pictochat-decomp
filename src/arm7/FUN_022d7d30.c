// decomp: module=arm7 addr=0x022d7d30 name=FUN_022d7d30
// flags: -O4,s -noThumb

// Shuts a capture/camera block down: optionally issues the 0xc008 command when
// the state word at +0x5f8 of the global context says 2, then bangs the DSi
// extended-I/O registers at 0x04808158/0x0480815c/0x04808168/0x04808036.

extern void FUN_022d865c(int cmd);
extern void FUN_022d862c(int reg, int value);
extern void FUN_037c849c(void);

extern int G_0380fff4;

void FUN_022d7d30(void)
{
    unsigned char *base = (unsigned char *)G_0380fff4 + 0x500;

    if (*(unsigned short *)(base + 0xf8) == 2) {
        FUN_022d865c(0xc008);
    }

    *(volatile unsigned short *)0x04808158 = 0x601e;
    FUN_037c849c();
    FUN_022d862c(0x1e, *(volatile unsigned short *)0x0480815c | 0x3f);
    *(volatile unsigned short *)0x04808168 = 0x800d;
    *(volatile unsigned short *)0x04808036 = 1;
}
