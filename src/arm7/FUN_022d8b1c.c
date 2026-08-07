// decomp: module=arm7 addr=0x022d8b1c name=FUN_022d8b1c
// flags: -noThumb

// Restarts the shared alarm: cancels whatever was pending and re-arms it for
// the given delay, converted from milliseconds to ticks, with the supplied
// handler and a null user argument.

typedef struct Alarm {
    char pad[0x1c];
} Alarm;

typedef struct State {
    char pad[0x634];
    Alarm alarm;
} State;

extern void FUN_037cade0(Alarm *alarm);
extern void FUN_037cacfc(Alarm *alarm, unsigned long long tick, void *handler, void *arg);

// Milliseconds to timer ticks: the DS system clock divided by the /64
// prescaler is 0x82ea/64 ticks per millisecond.
#define TICKS_PER_MSEC_NUM 0x82ea

#pragma opt_propagation off

void FUN_022d8b1c(unsigned int ms, void *handler) {
    unsigned int mul;
    FUN_037cade0(&(*(State **)0x0380fff4)->alarm);
    mul = TICKS_PER_MSEC_NUM;
    FUN_037cacfc(&(*(State **)0x0380fff4)->alarm,
                 ((unsigned long long)ms * mul) >> 6, handler, 0);
}
