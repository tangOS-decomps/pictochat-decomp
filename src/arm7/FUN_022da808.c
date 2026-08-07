// decomp: module=arm7 addr=0x022da808 name=FUN_022da808
// flags: -O4,s -noThumb
// size: 0x140 - the stated 0x13c excludes the trailing pool word (0x0380fff4).
//
// Validates and queues a scan request. Stamps the pending-job slot at
// G+0x404 with the caller's sequence number, rejects the call unless the
// driver is in state 1, 2 or 3 (0xb) and the channel mask is populated (1),
// then range-checks every field of the request block (5 on any failure)
// including each byte of the 0x10-byte SSID, which must pass the character
// filter. On success it programs the key and the channel list, parks the two
// pointers in the job slot, marks it type 0x10 and posts it (0x80).

typedef struct {
    unsigned char  pad00[0x10];
    unsigned char  f10[6];
    unsigned short f16;
    unsigned char  f18[0x20];
    unsigned short f38;
    unsigned char  f3a[0x10];
    unsigned short f4a;
    unsigned short f4c;
} Req;

typedef struct {
    unsigned char  pad00[2];
    unsigned short f02;
} Ctl;

typedef struct {
    unsigned short f00;
    unsigned char  pad02[2];
    unsigned short f04;
    unsigned char  pad06[0x12];
    Req           *f18;
    Ctl           *f1c;
} Job;

typedef struct {
    unsigned char  pad000[0x32e];
    unsigned short f32e;
    unsigned char  pad330[0x1c];
    unsigned short f34c;
} State;

extern State *G_0380fff4;

extern unsigned char FUN_022d8d6c(const void *p);
extern int FUN_022d84e0(int ch);
extern void FUN_022d75a8(void *key);
extern void FUN_022d760c(int count, void *list);
extern void FUN_037c5628(int a, int b);

int FUN_022da808(Req *req, Ctl *ctl)
{
    State *g;
    Job *job;
    unsigned int i;
    unsigned short s;
    int b;

    g = G_0380fff4;
    job = (Job *)((char *)g + 0x404);
    job->f04 = ctl->f02 - 3;
    ctl->f02 = 3;

    s = g->f32e;
    if (s != 1 && s != 3 && s != 2) {
        return 0xb;
    }

    if (G_0380fff4->f34c < 0x20) {
        return 1;
    }

    if (req->f16 > 0x20) {
        return 5;
    }

    if (req->f38 > 1) {
        return 5;
    }

    if (FUN_022d8d6c(req->f3a) == 0) {
        return 5;
    }

    if (req->f4a > 0x3e8) {
        return 5;
    }

    if (req->f4a < 0xa) {
        return 5;
    }

    if (req->f4c > 0x10) {
        return 5;
    }

    for (i = 0; i < 0x10; i++) {
        b = FUN_022d8d6c(&req->f3a[i]);
        if (b == 0) {
            break;
        }
        if (FUN_022d84e0(b) == 0) {
            return 5;
        }
    }

    FUN_022d75a8(req->f10);
    FUN_022d760c(req->f16, req->f18);

    job->f18 = req;
    job->f1c = ctl;
    job->f00 = 0x10;
    FUN_037c5628(2, 0);

    return 0x80;
}
