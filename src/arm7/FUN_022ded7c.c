// decomp: module=arm7 addr=0x022ded7c name=FUN_022ded7c
// flags: -O4,s -noThumb
// size: 0xf8 - the nominal 0xf4 excludes the trailing pool word.
//
// Flushes every queued command addressed to `id` from the three send queues
// at +0x194 (0xc bytes each, -1-terminated lists). In queue 1, or when the
// command is the one currently in flight for that queue (+0x438, 0x14-byte
// stride), it is released in place; otherwise it is completed with status 2
// and unlinked from the queue.

typedef unsigned short u16;

typedef struct Queue {
    int head;
    int pad[2];
} Queue;

typedef struct Flight {
    int cur;
    int pad[4];
} Flight;

extern unsigned short FUN_022da108(int idx);
extern int FUN_037c5b10(int cmd);
extern void FUN_022d9bf0(u16 *req);
extern void FUN_022d9b60(u16 *req);
extern void FUN_022dded8(Queue *q, int cmd);

#define ST (*(char **)0x0380fff4)

void FUN_022ded7c(int id)
{
    int cmd;
    u16 *req;
    int next;
    int flushed = 0;
    unsigned int i;

    if (FUN_022da108(id) == 0) {
        return;
    }
    for (i = 0; i < 3; i++) {
        cmd = ((Queue *)(ST + 0x194))[i].head;
        if (cmd == -1) {
            continue;
        }
        do {
            next = FUN_037c5b10(cmd);
            req = (u16 *)(cmd + 0x10);
            if (req[1] == id) {
                if (i == 1 || (int)req == ((Flight *)(ST + 0x438))[i].cur) {
                    FUN_022d9bf0(req);
                    req[1] = 0;
                    FUN_022d9b60(req);
                } else {
                    req[4] = 2;
                    FUN_022d9bf0(req);
                    FUN_022dded8(&((Queue *)(ST + 0x194))[i], cmd);
                    if (flushed == 0) {
                        flushed = 1;
                    }
                }
            }
            cmd = next;
        } while (cmd != -1);
    }
}
