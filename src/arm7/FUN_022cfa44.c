// decomp: module=arm7 addr=0x022cfa44 name=FUN_022cfa44
// flags: -noThumb
typedef struct ConnMgr3 {
    char pad[0x544];
    void *f544;
    void *f548;
} ConnMgr3;

extern ConnMgr3 G_023190dc;
extern int func_037cb520(void);
extern void func_037ca570(void *a, void *b, void *msg);
extern void func_037cb534(int state);

void FUN_022cfa44(void *msg) {
    int state = func_037cb520();
    func_037ca570(G_023190dc.f544, G_023190dc.f548, msg);
    func_037cb534(state);
}
