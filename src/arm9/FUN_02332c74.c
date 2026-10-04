// decomp: module=unk_autoload_0 addr=0x02332c74 name=FUN_02332c74

// NitroSDK CARDi_TaskThread: the card worker thread. Sleeps until a task is
// posted, copies it out under the interrupt lock, runs it, then clears the
// busy flag and fires the completion callback. Exits the thread once the
// owner field has been cleared; otherwise drops the task and loops.

typedef struct CARDiTask {
    int (*task)(struct CARDiTask *);
    void (*callback)(struct CARDiTask *);
    int result;
    unsigned int params[6];
} CARDiTask;

typedef struct {
    unsigned char unk0[0xc0];
    CARDiTask *volatile task;
} CARDiTaskOwner;

typedef struct {
    unsigned char unk0[6];
    unsigned char busy;
} CARDiFlags;

extern CARDiFlags G_023c1508;
extern int G_023c14e8;

void FUN_023374f0(void *dst, int value, int size); /* MI_CpuFill8 */
int FUN_02332080(void);                           /* OS_DisableInterrupts */
int FUN_02332094(int prev);                       /* OS_RestoreInterrupts */
void FUN_02330f38(void *queue);                   /* OS_SleepThread */
void FUN_02330e78(void);                          /* OS_ExitThread */

void FUN_02332c74(CARDiTaskOwner *p)
{
    for (;;) {
        CARDiTask task;
        int bak_psr;

        FUN_023374f0(&task, 0, sizeof(task));
        bak_psr = FUN_02332080();
        while (p->task == 0) {
            FUN_02330f38(0);
        }
        task = *p->task;
        FUN_02332094(bak_psr);

        if (task.task) {
            task.result = (*task.task)(&task);
        }

        bak_psr = FUN_02332080();
        {
            void (*callback)(CARDiTask *) = task.callback;

            G_023c1508.busy = 0;
            if (callback) {
                (*callback)(&task);
            }
        }
        if (G_023c14e8 == 0) {
            break;
        }
        p->task = 0;
        FUN_02332094(bak_psr);
    }
    FUN_02330e78();
}
