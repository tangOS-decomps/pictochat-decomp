// decomp: module=arm7 addr=0x022d3ebc name=FUN_022d3ebc
// flags: -O4,s -noThumb
// NOTE: verify with --size 0x118, not the nominal 0x104 - the stated size
// excludes this function's own trailing 5-word literal pool.

// Watchdog tick for the session whose control block hangs off +0x550 of the
// block at 0x023190dc.  Only runs while the session is in state 1.
//
// After the periodic FUN_037cb0b8 bookkeeping call it checks the 64-bit
// deadline pair: +0x7b8 is the timeout length and +0x738 the start stamp, both
// zero when no deadline is armed.  Once (now | 1) - start exceeds the timeout
// the start stamp is disarmed and a 0x25 message is posted to the queue at
// 0x02318164; if the message could not be allocated or the post failed, a
// {0x80, 8, 0x16, 0x25} event is raised instead.  Every other path (no
// deadline armed, or the deadline not yet reached) falls through to the shared
// FUN_022d40d8.
//
// `now | 1` really is an OR into the low word only - mwcc spells the high half
// as `orr lr, r1, #0`, which is the 64-bit form of the same expression.
//
// FUN_037c9e90 is declared here with four parameters: r2 (0) and r3 (0x8001)
// are live at the bl, so by register liveness they are arguments as well as
// the values written into the message.  That is also what pins them to a
// consecutive pair and lets mwcc fold the two adjacent field stores into the
// ROM's single `stmib r1, {r2, r3}` - spelled as a two-argument call the pair
// lands in r0/r2 and the function comes out one word long.  INFERRED; if
// FUN_037c9e90 is declared with two parameters elsewhere in src/, the two
// declarations disagree and only this site's codegen is evidence.

typedef unsigned long long u64;

typedef struct Session {
    unsigned char pad0[0x0c];
    int state;                  /* +0x00c */
    unsigned char pad1[0x728];
    u64 start;                  /* +0x738 */
    unsigned char pad2[0x78];
    u64 timeout;                /* +0x7b8 */
} Session;

typedef struct Message {
    int cmd;                    /* +0x00 */
    int arg;                    /* +0x04 */
    int flags;                  /* +0x08 */
} Message;

typedef struct Event {
    unsigned short group;       /* +0x00 */
    unsigned short code;        /* +0x02 */
    unsigned short detail;      /* +0x04 */
    unsigned short cmd;         /* +0x06 */
} Event;

extern Session *G_023190dc[];

extern void FUN_037cb0b8(void *buf, int a, int b, const char *tag, int flag);
extern u64 FUN_037caa3c(void);
extern int FUN_037c9e90(void *queue, Message *msg, int arg, int flags);
extern Event *FUN_037d14bc(void);
extern void FUN_037d1464(Event *ev);
extern Message *FUN_022ce718(void);
extern void FUN_022d40d8(void);

void FUN_022d3ebc(void)
{
    Session *s = G_023190dc[0x550 / 4];

    if (s->state != 1) {
        return;
    }

    FUN_037cb0b8((void *)0x03807230, 0xc8, 0x107, (const char *)0x02306f48, 1);

    if (s->timeout != 0) {
        u64 now = FUN_037caa3c() | 1;

        if (s->start != 0 && now - s->start > s->timeout) {
            Message *msg;
            int ok;

            s->start = 0;
            msg = FUN_022ce718();
            if (msg == 0) {
                ok = 0;
            } else {
                msg->cmd = 0x25;
                msg->arg = 0;
                msg->flags = 0x8001;
                ok = FUN_037c9e90((void *)0x02318164, msg, 0, 0x8001);
            }
            if (ok == 0) {
                Event *ev = FUN_037d14bc();

                ev->group = 0x80;
                ev->code = 8;
                ev->detail = 0x16;
                ev->cmd = 0x25;
                FUN_037d1464(ev);
            }
            return;
        }
    }

    FUN_022d40d8();
}
