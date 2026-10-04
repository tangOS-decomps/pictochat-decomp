// decomp: module=unk_autoload_0 addr=0x02327b54 name=FUN_02327b54

// Re-initialises the chat screen's shared state at G_023a0098: tears it down
// and resets it, installs the screen's update handler, clears the work buffer
// reported by FUN_02323d28, then wipes the 0x800-byte scratch block, two
// rodata-bounded VRAM regions and the two-byte flag area.

extern char G_023a0098[];
extern char G_023a070c[];
extern char G_02343b64[];      /* start of the first region */
extern char G_end_02343d44[];  /* one past its end */
extern char G_023486e4[];      /* start of the second region */
extern char G_endA_023488e4[]; /* one past its end */
extern char G_0233b4ac[];

extern void FUN_02325654(void *);
extern void FUN_02325774(void);
extern void FUN_0232563c(void *);
extern void FUN_02323510(int, int, int);
extern void FUN_02325b00(void);
extern void FUN_02323458(void (*)(void), void *);
extern int FUN_02323d28(void);
extern int FUN_02323d3c(void);
extern void FUN_02336ce8(int, int, int);
extern void FUN_02323464(void *, int, int);
extern void FUN_02336b0c(void *, int, int);
extern void FUN_02336d2c(void *, int, int);
extern void *FUN_0233665c(void);
extern void FUN_0233740c(int, void *, int);
extern void FUN_02336800(void *, int, int);

void FUN_02327b54(void)
{
    int buf;

    FUN_02325654(G_023a0098);
    FUN_02325774();
    FUN_0232563c(G_023a0098);
    FUN_02323510(0x16, 0x60, 0);
    FUN_02323458(FUN_02325b00, G_023a0098);
    buf = FUN_02323d28();
    FUN_02336ce8(buf, 0, FUN_02323d3c());
    FUN_02323464(G_023a070c, 10, 0);
    FUN_02336b0c(G_023a070c, 0, 0x800);
    FUN_02336d2c(G_02343b64, 0, G_end_02343d44 - G_02343b64);
    FUN_0233740c(0x7009, FUN_0233665c(), 0x800);
    FUN_02336800(G_023486e4, 0, G_endA_023488e4 - G_023486e4);
    FUN_02336800(G_0233b4ac, 0, 2);
}
