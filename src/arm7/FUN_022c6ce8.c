// decomp: module=arm7 addr=0x022c6ce8 name=FUN_022c6ce8
// flags: -O4,s -noThumb

// Records a new value of the monotonically-increasing counter at +4; if it went
// backwards the wrap count at +8 is bumped. Runs with IRQs masked and returns
// the (possibly bumped) wrap count.

extern int func_022c6d40(void);       // OS_DisableInterrupts
extern int func_022c6d54(int state);  // OS_RestoreInterrupts

typedef struct Ctr {
    int f0;
    int last;
    int wraps;
} Ctr;

extern Ctr G_0380520c;

int FUN_022c6ce8(int v)
{
    int state = func_022c6d40();
    if (v < G_0380520c.last) {
        G_0380520c.wraps = G_0380520c.wraps + 1;
    }
    G_0380520c.last = v;
    func_022c6d54(state);
    return G_0380520c.wraps;
}
