// decomp: module=arm7 addr=0x022cdb44 name=FUN_022cdb44
// flags: -O4,s
// size: 0xb8, not funcs.json's 0x68 - the cached bound stops inside the Thumb
// halfword jump table (36 entries at 0x022cdb5a) and misses the three case
// bodies plus the two trailing pool words.

// Normalises the 6-bit channel field of the word at *p: channels 0..9 and
// 16..17 stay as they are, 18..25 and 34..35 rebase by 0x12, 32..33 rebase by
// 0x18 and set the "rebased" flag, and everything else is forced to channel 0.

#pragma thumb on

typedef struct {
    unsigned int lo : 8;
    unsigned int chan : 6;
    unsigned int rebased : 1;
    unsigned int hi : 17;
} Word022cdb44;

void FUN_022cdb44(Word022cdb44 *p)
{
    switch (p->chan) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 16:
    case 17:
        p->rebased = 0;
        break;
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 34:
    case 35:
        p->rebased = 1;
        p->chan = p->chan - 0x12;
        break;
    case 32:
    case 33:
        p->rebased = 1;
        p->chan = p->chan - 0x18;
        break;
    default:
        p->rebased = 0;
        p->chan = 0;
        break;
    }
}
