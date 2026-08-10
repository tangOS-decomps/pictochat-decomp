//cpp
// decomp: module=unk_autoload_0 addr=0x0233946c name=FUN_0233946c
// NONMATCHING: the control flow and pool references are correct; mwcc assigns the hardware-register and wait-pointer values to the opposite callee-saved registers and schedules a few pointer updates differently. (div=8). Logic verified correct vs ROM; not byte-exact.
extern "C" {

typedef unsigned int u32;

extern u32 G_023c3580[];
extern void FUN_0233731c(u32 channel);
extern void FUN_02337358(u32 channel);

void FUN_0233946c(void)
{
    u32 channel;
    u32 *reg;
    volatile u32 *wait;
    u32 *saved;
    u32 wait_mask;

    reg = (u32 *)0x040000b8;
    channel = 0;
    saved = G_023c3580;
    wait = (volatile u32 *)((char *)reg + 0xec);
    wait_mask = 2;
    wait_mask <<= 30;
    do {
        *saved = *(volatile u32 *)reg;
        switch (*(volatile u32 *)reg & 0x38000000) {
        case 0x28000000:
            while (*wait & wait_mask) {
            }
            break;
        case 0x18000000:
        case 0x20000000:
            FUN_0233731c(channel);
            break;
        default:
            if ((*(volatile u32 *)reg & 0x02000000) == 0) {
                FUN_0233731c(channel);
            } else {
                FUN_02337358(channel);
            }
            break;
        }
        saved++;
        channel++;
        reg += 3;
    } while (channel <= 3);
}

}
