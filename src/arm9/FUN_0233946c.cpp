//cpp
// decomp: module=unk_autoload_0 addr=0x0233946c name=FUN_0233946c

extern "C" {
typedef unsigned int u32;

extern u32 G_023c3580[4];
void FUN_0233731c(u32 channel);
void FUN_02337358(u32 channel);

void FUN_0233946c(void)
{
    u32 ch;
    u32 *saved;
    volatile u32 *cnt;

    ch = 0;
    cnt = (volatile u32 *)0x040000b8;
    saved = G_023c3580;
    do {
        *saved = *cnt;
        switch (*cnt & 0x38000000) {
        case 0x28000000:
            while (*(volatile u32 *)0x040001a4 & 0x80000000) {
            }
            break;
        case 0x18000000:
        case 0x20000000:
            FUN_0233731c(ch);
            break;
        default:
            if ((*cnt & 0x02000000) == 0) {
                FUN_0233731c(ch);
            } else {
                FUN_02337358(ch);
            }
            break;
        }
        saved++;
        cnt += 3;
        ch++;
    } while (ch <= 3);
}
}
