//cpp
// decomp: module=unk_autoload_0 addr=0x0232270c name=FUN_0232270c
#pragma thumb on

extern "C" {
typedef unsigned int u32;
typedef unsigned short u16;

extern volatile u32 *FUN_0232254c(void);
extern u32 FUN_023226d4(void);
extern void FUN_0233210c(void);
extern volatile u16 G_02fffce4;
extern volatile u32 G_02fff890;

void FUN_0232270c(void)
{
    volatile u32 *state = FUN_0232254c();
    u32 status = FUN_023226d4();
    {
        u32 value = *state;
        u32 bit = (value << 25) >> 31;
        if (bit != 0) {
            return;
        }
        bit = (value << 23) >> 31;
        if (bit != 0 && (status & 0xe03) == 0xe03) {
                *state = value | 0x10;
                return;
        }
    }

        u32 bit = ((u32)G_02fffce4 << 25) >> 31;
        if (bit != 0) {
            u32 flag = 1;
            u32 reg = G_02fff890;
            if ((reg & flag) == 0) {
                flag = 0;
            }
            if (flag == 0) {
                return;
            }
            bit = (*state << 28) >> 31;
            if (bit != 0) {
                return;
            }

            reg = G_02fff890;
            int flag2;
            if ((reg & 2) != 0) {
                flag2 = 1;
            } else {
                flag2 = 0;
            }
            if (flag2 == 0) {
                *state |= 0x10;
                return;
            }

            int count = 0;
            int mask = 2;
            goto check_status;
        loop_status:
            FUN_0233210c();
            status = FUN_023226d4();
            ++count;
            if (count >= 30) {
                *state |= 0x10;
                return;
            }
        check_status:
            if ((status & mask) != 0) {
                goto loop_status;
            }
        }
}
}
