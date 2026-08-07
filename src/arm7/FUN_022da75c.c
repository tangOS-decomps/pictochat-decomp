// decomp: module=arm7 addr=0x022da75c name=FUN_022da75c
// flags: -O4,s -noThumb

// Handler for the "set power-save mode" request: stamps result code 9 into the
// reply block, rejects any of the three boolean fields being out of range with
// error 5, then applies the power-save flag and pushes the resulting sleep mode
// out through FUN_022d7d1c / FUN_022d7cf0.

extern int FUN_022d7c88(unsigned short enable);
extern int FUN_022d7d1c(int mode);
extern unsigned int FUN_022d7cf0(unsigned int value);

typedef struct PsReq {
    char pad[0x10];
    unsigned short enable;  /* 0x10 */
    unsigned short deep;    /* 0x12 */
    unsigned short extra;   /* 0x14 */
} PsReq;

typedef struct Reply {
    unsigned short pad;
    unsigned short code;    /* 0x02 */
} Reply;

int FUN_022da75c(PsReq *req, Reply *reply)
{
    reply->code = 9;

    if (req->enable > 1) {
        return 5;
    }
    if (req->deep > 1) {
        return 5;
    }
    if (req->extra > 1) {
        return 5;
    }

    FUN_022d7c88(req->enable);

    if (req->enable == 1) {
        if (req->deep == 1) {
            FUN_022d7d1c(0x8001);
        } else {
            FUN_022d7d1c(0);
        }
        *(unsigned short *)((*(char **)0x0380fff4) + 0x358) = req->extra;
    } else {
        FUN_022d7d1c(0x8000);
        FUN_022d7cf0(2);
    }
    return 0;
}
