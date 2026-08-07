// decomp: module=arm7 addr=0x022d8078 name=FUN_022d8078
// flags: -O4,s -noThumb
// Shuts the wireless block down: clears the busy flag, stops the hardware,
// masks the WiFi power register and frees the pending transfer handle.
extern void FUN_037c8430(void);
extern void FUN_022ded7c(int handle);
extern void FUN_022d9c60(int handle, int reason);

void FUN_022d8078(void)
{
    unsigned char *p = *(unsigned char **)0x0380fff4 + 0x344;

    *(unsigned short *)(p + 0x6a) = 0;
    FUN_037c8430();
    *(unsigned short *)0x0480802a = 0;
    if (*(unsigned short *)(p + 0x88) != 0) {
        FUN_022ded7c(*(unsigned short *)(p + 0x88));
        FUN_022d9c60(*(unsigned short *)(p + 0x88), 0x20);
        *(unsigned short *)(p + 0x88) = 0;
    }
}
