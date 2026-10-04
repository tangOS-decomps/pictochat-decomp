// decomp: module=unk_autoload_0 addr=0x02331ddc name=FUN_02331ddc

// NitroSDK OSi_InsertAlarm: for a periodic alarm, advances the fire time to
// the first period boundary after now; then links the alarm into the
// fire-time-sorted alarm queue, reprogramming the hardware timer whenever it
// becomes the new head.

typedef unsigned long long OSTick;

typedef struct OSAlarm OSAlarm;
struct OSAlarm {
    void (*handler)(void *);
    void *arg;
    unsigned int tag;
    OSTick fire;
    OSAlarm *prev;
    OSAlarm *next;
    OSTick period;
    OSTick start;
};

typedef struct {
    unsigned short useAlarm;
    unsigned short pad;
    OSAlarm *head;
    OSAlarm *tail;
} AlarmState;

extern AlarmState G_023c0af0;

OSTick FUN_02331ca8(void);          /* OS_GetTick */
void FUN_02331d1c(OSAlarm *alarm);  /* OSi_SetTimer */

void FUN_02331ddc(OSAlarm *alarm, OSTick fire)
{
    OSAlarm *prev;
    OSAlarm *next;

    if (alarm->period > 0) {
        OSTick tick = FUN_02331ca8();

        fire = alarm->start;
        if (alarm->start < tick) {
            fire += alarm->period * ((tick - alarm->start) / alarm->period + 1);
        }
    }

    alarm->fire = fire;

    for (next = G_023c0af0.head; next; next = next->next) {
        if ((long long)(fire - next->fire) >= 0) {
            continue;
        }

        alarm->prev = next->prev;
        next->prev = alarm;
        alarm->next = next;
        prev = alarm->prev;
        if (prev) {
            prev->next = alarm;
        } else {
            G_023c0af0.head = alarm;
            FUN_02331d1c(alarm);
        }
        return;
    }

    alarm->next = 0;
    prev = G_023c0af0.tail;
    G_023c0af0.tail = alarm;
    alarm->prev = prev;
    if (prev) {
        prev->next = alarm;
    } else {
        G_023c0af0.head = G_023c0af0.tail = alarm;
        FUN_02331d1c(alarm);
    }
}
