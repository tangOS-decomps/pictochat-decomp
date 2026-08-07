// decomp: module=arm7 addr=0x022ce6b8 name=FUN_022ce6b8
#pragma arm

typedef struct ConnMgr3 {
    char pad[0x578];
    unsigned int f578;
    unsigned int f57c;
    unsigned int f580;
} ConnMgr3;

extern ConnMgr3 G_023190dc;
extern int func_037cb520(void);
extern void func_037cb534(int state);
extern void func_037c9d2c(void);
extern void func_037c9b84(void *a, unsigned int b);
extern char *FUN_022d6bec(void);
extern void func_037c9d64(void);

void FUN_022ce6b8(void) {
    int state = func_037cb520();
    func_037c9d2c();
    func_037c9b84((void *)0x03807134, G_023190dc.f578);
    char *r = FUN_022d6bec();
    func_037c9b84(r, G_023190dc.f57c);
    func_037c9b84((void *)0x03807090, G_023190dc.f580);
    func_037c9d64();
    func_037cb534(state);
}

#pragma thumb
