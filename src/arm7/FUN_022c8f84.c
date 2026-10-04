// decomp: module=arm7 addr=0x022c8f84 name=FUN_022c8f84
// flags: -O4,s
//
// Sequence-player tick: for each of the player's 16 track slots (bytes at
// +8, 0xff = unused) it ages the track's channel list, honours the
// note-finish / wait countdowns, then interprets sequence bytecode from the
// track's cursor until the track waits again: notes (< 0x80) allocate and
// start a channel through NoteOnCommandProc; 0x80-0xff are wait/program,
// open-track/jump/call, variable arithmetic and compares (0xb0), per-track
// parameter bytes (0xc0/0xd0), 16-bit parameters (0xe0) and
// return/loop-end/fin (0xf0). A track that hits fin (0xff) is closed;
// returns TRUE once no track is still playing.
//
// Byte-exact on mwccarm 2.0/sp2p2, sp2p3 and sp2p4 ONLY. sp1..sp2 emit the
// same instructions but flush the mid-function literal pool (0xffff and the
// channel callback) three case blocks later in the 0xc0 switch - their pool
// distance limit is larger. Size is the untruncated 0x7e0 (Ghidra's 0x774
// stops before the 0xf0-group tail and the trailing pool).
//   python tools/match.py --c src/arm7/FUN_022c8f84.c --func FUN_022c8f84 \
//     --addr 0x022c8f84 --size 0x7e0 --module arm7 --version 2.0/sp2p2
//
// Phrasing that the bytes depend on:
//  - the 0xc0/0xd0 `par` lives in a stack slot (the ROM reloads it per case
//    and sign-loads it for transpose/pitch bend), reproduced by reading it
//    through `*(s8 *)&par`;
//  - case bodies sit in the jump tables' block order, which is source order;
//  - the empty `case 0xfe` is what makes the 0xf0 group a jump table;
//  - `allowedChannels &= ...` as its own statement sets the stack-arg store
//    order before the channel-alloc call;
//  - NoteOnCommandProc must be inlined (always_inline), as the ROM has it.

#pragma thumb on

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef int BOOL;

#define NULL 0
#define TRUE 1
#define FALSE 0

typedef struct ExChannel {
    u8 pad0[3];
    u8 pad3_0 : 2;
    u8 autoSweep : 1;
    u8 pad3_3 : 5;
    u8 pad4[4];
    u8 key;                   /* +0x08 */
    u8 velocity;              /* +0x09 */
    u8 padA[0x14 - 0x0a];
    s32 sweepCounter;         /* +0x14 */
    s32 sweepLength;          /* +0x18 */
    u8 pad1C[0x22 - 0x1c];
    u8 prio;                  /* +0x22 */
    u8 pad23[0x32 - 0x23];
    s16 sweepPitch;           /* +0x32 */
    s32 length;               /* +0x34 */
    u8 pad38[0x50 - 0x38];
    struct ExChannel *nextLink; /* +0x50 */
} ExChannel;

typedef struct InstData {
    u8 type;
    u8 pad;
    u16 param[5];
} InstData;

typedef struct Track {
    u8 active : 1;
    u8 noteWait : 1;
    u8 muteFlag : 1;
    u8 tie : 1;
    u8 noteFinishWait : 1;
    u8 portamento : 1;
    u8 cmp : 1;
    u8 channelMask : 1;
    u8 f1;
    u16 prgNo;                /* +0x02 */
    u8 volume;                /* +0x04 */
    u8 volume2;               /* +0x05 */
    s8 pitchBend;             /* +0x06 */
    u8 bendRange;             /* +0x07 */
    s8 pan;                   /* +0x08 */
    u8 pad9[5];
    u8 attack;                /* +0x0e */
    u8 decay;                 /* +0x0f */
    u8 sustain;               /* +0x10 */
    u8 release;               /* +0x11 */
    u8 prio;                  /* +0x12 */
    s8 transpose;             /* +0x13 */
    u8 portaKey;              /* +0x14 */
    u8 portaTime;             /* +0x15 */
    s16 sweepPitch;           /* +0x16 */
    u8 modDepth;              /* +0x18 */
    u8 modSpeed;              /* +0x19 */
    u8 modType;               /* +0x1a */
    u8 modRange;              /* +0x1b */
    u16 modDelay;             /* +0x1c */
    u16 channelMaskBits;      /* +0x1e */
    s32 wait;                 /* +0x20 */
    const u8 *base;           /* +0x24 */
    const u8 *cur;            /* +0x28 */
    const u8 *posCallStack[3]; /* +0x2c */
    u8 loopCount[3];          /* +0x38 */
    u8 callStackDepth;        /* +0x3b */
    ExChannel *channelList;   /* +0x3c */
} Track;

typedef struct Player {
    u8 f0;
    u8 playerNo;
    u8 pad2[2];
    u8 prio;                  /* +0x04 */
    u8 volume;                /* +0x05 */
    u8 pad6[2];
    u8 tracks[16];            /* +0x08 */
    u16 tempo;                /* +0x18 */
    u8 pad1A[6];
    void *bank;               /* +0x20 */
} Player;

extern BOOL G_0380581c;

extern Track *FUN_022c8dec(Player *player, int trackNo);
extern void FUN_022c8e0c(Player *player, int trackNo);
extern u8 FUN_022c88bc(Track *track);
extern s32 FUN_022c8c38(Track *track, Player *player, int argType);
extern u32 FUN_022c8c14(Track *track);
extern void FUN_022c8bf0(const void *addr);
extern void FUN_022c8d88(Track *track, Player *player, int release);
extern void FUN_022c8dcc(Track *track);
extern void FUN_022c8d80(Track *track, const void *base, u32 offset);
extern s16 *FUN_022c9764(Player *player, int varNo);
extern void FUN_022c97cc(Track *track, Player *player, int mute);
extern BOOL FUN_022c9828(void *bank, int prgNo, int key, InstData *inst);
extern ExChannel *FUN_022c8290(u32 chBitMask, int prio, BOOL strongRequest,
                               void (*callback)(), void *userData);
extern void FUN_022c83d0(ExChannel *ch);
extern BOOL FUN_022c9948(ExChannel *ch, int key, int velocity, s32 length,
                         void *bank, InstData *inst);
extern void FUN_022c8238(ExChannel *ch, int attack);
extern void FUN_022c8254(ExChannel *ch, int decay);
extern void FUN_022c8268(ExChannel *ch, int sustain);
extern void FUN_022c826c(ExChannel *ch, int release);
extern u16 FUN_022c7af4(void);
extern void FUN_038008fc();

#pragma always_inline on
static void NoteOnCommandProc(Track *track, Player *player, int key, int velocity, s32 length)
{
    ExChannel *ch = NULL;

    if (track->tie) {
        ch = track->channelList;
        if (ch != NULL) {
            ch->key = (u8)key;
            ch->velocity = velocity;
        }
    }
    if (ch == NULL) {
        InstData inst;
        u32 allowedChannels;

        if (!FUN_022c9828(player->bank, track->prgNo, key, &inst))
            return;
        switch (inst.type) {
        case 1:
        case 4:
            allowedChannels = 0xffff;
            break;
        case 2:
            allowedChannels = 0x3f00;
            break;
        case 3:
            allowedChannels = 0xc000;
            break;
        default:
            return;
        }
        allowedChannels &= track->channelMaskBits;
        ch = FUN_022c8290(allowedChannels,
                          player->prio + track->prio,
                          track->channelMask, FUN_038008fc, track);
        if (ch == NULL)
            return;
        if (!FUN_022c9948(ch, key, velocity,
                          track->tie ? -1 : length,
                          player->bank, &inst)) {
            ch->prio = 0;
            FUN_022c83d0(ch);
            return;
        }
        ch->nextLink = track->channelList;
        track->channelList = ch;
    }
    if (track->attack != 0xff)
        FUN_022c8238(ch, track->attack);
    if (track->decay != 0xff)
        FUN_022c8254(ch, track->decay);
    if (track->sustain != 0xff)
        FUN_022c8268(ch, track->sustain);
    if (track->release != 0xff)
        FUN_022c826c(ch, track->release);
    ch->sweepPitch = track->sweepPitch;
    if (track->portamento)
        ch->sweepPitch += (s16)((track->portaKey - key) << 6);
    if (track->portaTime == 0) {
        ch->sweepLength = length;
        ch->autoSweep = FALSE;
    } else {
        int swp = track->portaTime * track->portaTime;
        int sp = ch->sweepPitch < 0 ? -ch->sweepPitch : ch->sweepPitch;
        ch->sweepLength = (swp * sp) >> 11;
    }
    ch->sweepCounter = 0;
}

BOOL FUN_022c8f84(Player *player, BOOL doPlay)
{
    BOOL isPlaying = FALSE;
    int trackNo;

    for (trackNo = 0; trackNo < 16; trackNo++) {
        Track *track = FUN_022c8dec(player, trackNo);
        ExChannel *ch;
        int result;

        if (track == NULL || track->cur == NULL)
            continue;

        for (ch = track->channelList; ch != NULL; ch = ch->nextLink) {
            if (ch->length > 0)
                ch->length--;
            if (!ch->autoSweep && ch->sweepCounter < ch->sweepLength)
                ch->sweepCounter++;
        }

        if (track->noteFinishWait) {
            if (track->channelList != NULL) {
                result = 0;
                goto step_done;
            }
            track->noteFinishWait = FALSE;
        }

        if (track->wait > 0) {
            track->wait--;
            if (track->wait > 0) {
                result = 0;
                goto step_done;
            }
        }

        FUN_022c8bf0(track->cur);

        while (track->wait == 0 && !track->noteFinishWait) {
            u8 varNo;
            u8 velocity;
            BOOL runFlag = TRUE;
            int argType;
            BOOL specialFlag = FALSE;
            int cmd;

            cmd = FUN_022c88bc(track);
            if (cmd == 0xa2) {
                cmd = FUN_022c88bc(track);
                runFlag = track->cmp;
            }
            if (cmd == 0xa0) {
                cmd = FUN_022c88bc(track);
                argType = 3;
                specialFlag = TRUE;
            }
            if (cmd == 0xa1) {
                cmd = FUN_022c88bc(track);
                argType = 4;
                specialFlag = TRUE;
            }

            if (!(cmd & 0x80)) {
                s32 length;
                int key;

                velocity = FUN_022c88bc(track);
                length = FUN_022c8c38(track, player, specialFlag ? argType : 2);
                key = cmd + track->transpose;

                if (!runFlag)
                    continue;

                if (key < 0)
                    key = 0;
                else if (key > 127)
                    key = 127;

                if (!track->muteFlag && doPlay)
                    NoteOnCommandProc(track, player, key, velocity, length > 0 ? length : -1);
                track->portaKey = (u8)key;
                if (track->noteWait) {
                    track->wait = length;
                    if (length == 0)
                        track->noteFinishWait = TRUE;
                }
            } else {
                switch (cmd & 0xf0) {
                case 0x80: {
                    s32 par = FUN_022c8c38(track, player, specialFlag ? argType : 2);
                    if (!runFlag)
                        break;
                    switch (cmd) {
                    case 0x80:
                        track->wait = par;
                        break;
                    case 0x81:
                        if (par < 0x10000)
                            track->prgNo = (u16)par;
                        break;
                    }
                    break;
                }
                case 0x90:
                    switch (cmd) {
                    case 0x93: {
                        u8 no = FUN_022c88bc(track);
                        u32 off = FUN_022c8c14(track);
                        Track *newTrack;
                        if (!runFlag)
                            break;
                        newTrack = FUN_022c8dec(player, no);
                        if (newTrack != NULL && newTrack != track) {
                            FUN_022c8d88(newTrack, player, -1);
                            FUN_022c8dcc(newTrack);
                            FUN_022c8d80(newTrack, track->base, off);
                        }
                        break;
                    }
                    case 0x94: {
                        u32 off = FUN_022c8c14(track);
                        if (!runFlag)
                            break;
                        track->cur = track->base + off;
                        break;
                    }
                    case 0x95: {
                        u32 off = FUN_022c8c14(track);
                        if (!runFlag)
                            break;
                        if (track->callStackDepth >= 3)
                            break;
                        track->posCallStack[track->callStackDepth] = track->cur;
                        track->callStackDepth++;
                        track->cur = track->base + off;
                        break;
                    }
                    }
                    break;
                case 0xc0:
                case 0xd0: {
                    u8 par = (u8)FUN_022c8c38(track, player, specialFlag ? argType : 0);
                    if (!runFlag)
                        break;
                    switch (cmd) {
                    case 0xc1:
                        track->volume = par;
                        break;
                    case 0xd5:
                        track->volume2 = par;
                        break;
                    case 0xc2:
                        player->volume = par;
                        break;
                    case 0xc5:
                        track->bendRange = par;
                        break;
                    case 0xc6:
                        track->prio = par;
                        break;
                    case 0xc7:
                        track->noteWait = par;
                        break;
                    case 0xcf:
                        track->portaTime = par;
                        break;
                    case 0xca:
                        track->modType = par;
                        break;
                    case 0xcb:
                        track->modSpeed = par;
                        break;
                    case 0xcc:
                        track->modDepth = par;
                        break;
                    case 0xcd:
                        track->modRange = par;
                        break;
                    case 0xd0:
                        track->attack = par;
                        break;
                    case 0xd1:
                        track->decay = par;
                        break;
                    case 0xd2:
                        track->sustain = par;
                        break;
                    case 0xd3:
                        track->release = par;
                        break;
                    case 0xd4:
                        if (track->callStackDepth >= 3)
                            break;
                        track->posCallStack[track->callStackDepth] = track->cur;
                        track->loopCount[track->callStackDepth] = par;
                        track->callStackDepth++;
                        break;
                    case 0xc8:
                        track->tie = par;
                        FUN_022c8d88(track, player, -1);
                        FUN_022c8dcc(track);
                        break;
                    case 0xd7:
                        FUN_022c97cc(track, player, par);
                        break;
                    case 0xc9:
                        track->portaKey = (u8)(par + track->transpose);
                        track->portamento = TRUE;
                        break;
                    case 0xce:
                        track->portamento = par;
                        break;
                    case 0xc3:
                        track->transpose = *(s8 *)&par;
                        break;
                    case 0xc4:
                        track->pitchBend = *(s8 *)&par;
                        break;
                    case 0xc0:
                        track->pan = (s8)(par - 0x40);
                        break;
                    case 0xd6:
                        if (G_0380581c) {
                            FUN_022c9764(player, par);
                        }
                        break;
                    }
                    break;
                }
                case 0xe0: {
                    s16 par = (s16)FUN_022c8c38(track, player, specialFlag ? argType : 1);
                    if (!runFlag)
                        break;
                    switch (cmd) {
                    case 0xe1:
                        player->tempo = (u16)par;
                        break;
                    case 0xe0:
                        track->modDelay = (u16)par;
                        break;
                    case 0xe3:
                        track->sweepPitch = par;
                        break;
                    }
                    break;
                }
                case 0xb0: {
                    varNo = FUN_022c88bc(track);
                    s16 par = (s16)FUN_022c8c38(track, player, specialFlag ? argType : 1);
                    s16 *varPtr = FUN_022c9764(player, varNo);
                    if (!runFlag || varPtr == NULL)
                        break;
                    switch (cmd) {
                    case 0xb0:
                        *varPtr = par;
                        break;
                    case 0xb1:
                        *varPtr += par;
                        break;
                    case 0xb2:
                        *varPtr -= par;
                        break;
                    case 0xb3:
                        *varPtr *= par;
                        break;
                    case 0xb4:
                        if (par != 0)
                            *varPtr /= par;
                        break;
                    case 0xb5:
                        if (par >= 0)
                            *varPtr <<= par;
                        else
                            *varPtr >>= -par;
                        break;
                    case 0xb6: {
                        BOOL minus = FALSE;
                        s32 rnd;
                        if (par < 0) {
                            minus = TRUE;
                            par = (s16)(-par);
                        }
                        rnd = FUN_022c7af4();
                        rnd = (rnd * (par + 1)) >> 16;
                        if (minus)
                            rnd = -rnd;
                        *varPtr = (s16)rnd;
                        break;
                    }
                    case 0xb8:
                        track->cmp = (*varPtr == par);
                        break;
                    case 0xb9:
                        track->cmp = (*varPtr >= par);
                        break;
                    case 0xba:
                        track->cmp = (*varPtr > par);
                        break;
                    case 0xbb:
                        track->cmp = (*varPtr <= par);
                        break;
                    case 0xbc:
                        track->cmp = (*varPtr < par);
                        break;
                    case 0xbd:
                        track->cmp = (*varPtr != par);
                        break;
                    }
                    break;
                }
                case 0xf0:
                    if (!runFlag)
                        break;
                    switch (cmd) {
                    case 0xfd:
                        if (track->callStackDepth == 0)
                            break;
                        track->callStackDepth--;
                        track->cur = track->posCallStack[track->callStackDepth];
                        break;
                    case 0xfc: {
                        u8 count;
                        if (track->callStackDepth == 0)
                            break;
                        count = track->loopCount[track->callStackDepth - 1];
                        if (count != 0) {
                            count--;
                            if (count == 0) {
                                track->callStackDepth--;
                                break;
                            }
                        }
                        track->loopCount[track->callStackDepth - 1] = count;
                        track->cur = track->posCallStack[track->callStackDepth - 1];
                        break;
                    }
                    case 0xfe:
                        break;
                    case 0xff:
                        result = -1;
                        goto step_done;
                    }
                    break;
                }
            }
        }

        result = 0;
    step_done:
        if (result == 0)
            isPlaying = TRUE;
        else
            FUN_022c8e0c(player, trackNo);
    }

    return isPlaying ? FALSE : TRUE;
}
