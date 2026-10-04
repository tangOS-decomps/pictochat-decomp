// decomp: module=arm7 addr=0x022df00c name=FUN_022df00c
// flags: -O4,s -noThumb
// size: 0x8c - the nominal 0x88 excludes the trailing pool word.
//
// Completes every command in send queue `i` (+0x194, 0xc bytes per queue,
// -1-terminated) with status 2, releasing it first unless this is queue 2,
// and unlinking it from the queue when `unlink` is set.

typedef unsigned short u16;

typedef struct Queue {
    int head;
    int pad[2];
} Queue;

extern int FUN_037c5b10(int cmd);
extern void FUN_022d9bf0(u16 *req);
extern void FUN_022dded8(Queue *q, int cmd);

#define ST (*(char **)0x0380fff4)

void FUN_022df00c(int i, int unlink)
{
    int cmd = ((Queue *)(ST + 0x194))[i].head;
    int next;

    if (cmd == -1) {
        return;
    }
    do {
        next = FUN_037c5b10(cmd);
        if (i != 2) {
            FUN_022d9bf0((u16 *)(cmd + 0x10));
        }
        ((u16 *)(cmd + 0x10))[4] = 2;
        if (unlink) {
            FUN_022dded8(&((Queue *)(ST + 0x194))[i], cmd);
        }
        cmd = next;
    } while (cmd != -1);
}
