// decomp: module=unk_autoload_0 addr=0x023396c0 name=FUN_023396c0

// Backlight/panel power gate. Mode 1 powers the panel back up (refusing if it
// was switched off less than 8 ticks ago unless forced), mode 0 drains the
// pending work, powers it down and stamps the tick it went off. Either way the
// caller's job object is drained through one of two drain entry points.

typedef unsigned short u16;

struct Sync {
    char pad00[4];
    int tickOff;    /* 0x04 */
    int tickOn;     /* 0x08 */
    char pad0c[8];
    int job;        /* 0x14 */
};

extern int G_02fffc3c;          /* pool 0x02339774 */
extern struct Sync G_023c3564;  /* pool 0x02339778 */

#define REG_POWCNT (*(volatile u16 *)0x04000304)

extern int FUN_023392f8(void *);
extern int FUN_023392c0(void *, int, int);
extern int FUN_023393f0(int);
extern void FUN_0233210c(void);

int FUN_023396c0(int mode, void *job, int force, int alt)
{
    u16 pv;

    if (mode != 0) {
        if (mode == 1) {
        if (force == 0 && (unsigned int)(G_02fffc3c - G_023c3564.tickOff) <= 7)
            return 0;
        if (job != 0) {
            if (alt != 0) {
                while (FUN_023392f8(job) != 0)
                    ;
            } else {
                while (FUN_023392c0(job, 0, 0) != 0)
                    ;
            }
        }
        REG_POWCNT = (u16)(REG_POWCNT | 1);
        while (FUN_023393f0(G_023c3564.job) != 0)
            ;
        }
    } else {
        while (FUN_023393f0(0) != 0)
            ;
        if ((unsigned int)(G_02fffc3c - G_023c3564.tickOn) <= 2) {
            FUN_0233210c();
            FUN_0233210c();
        }
        pv = REG_POWCNT;
        REG_POWCNT = (u16)(pv & ~1);
        G_023c3564.tickOff = G_02fffc3c;
        if (job != 0) {
            if (alt != 0)
                FUN_023392f8(job);
            else
                FUN_023392c0(job, 0, 0);
        }
    }
    return 1;
}
