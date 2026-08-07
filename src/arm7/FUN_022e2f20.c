// decomp: module=arm7 addr=0x022e2f20 name=FUN_022e2f20
// flags: -O4,s -noThumb

// Reads the 2-byte payload length out of the device (property 0x2c), sanity
// checks it against [0xa4, 0x1d6], allocates length+2 bytes from the pool at
// +0x188 and pulls the body in with property 0x2a.  The stored pointer is
// biased by 0xc so the caller sees the payload, not the block header.
// Every device access is bracketed by FUN_022e2efc/FUN_022e2df4 on the way in
// and FUN_022e2f14 on the way out.

extern void FUN_022e2efc(int port);
extern void FUN_022e2df4(void);
extern void FUN_022e2f08(int prop, unsigned int size, void *buf);
extern void FUN_022e2f14(int port);
extern void *FUN_037c58fc(void *heap, unsigned int size);

typedef struct Ctx {
    char pad0[0x188];
    char heap[0x18c]; /* 0x188 */
    int port;         /* 0x314 */
    void *buf;        /* 0x318 */
} Ctx;

int FUN_022e2f20(void)
{
    unsigned int len;

    FUN_022e2efc((*(Ctx **)0x0380fff4)->port);
    FUN_022e2df4();
    len = 0;
    FUN_022e2f08(0x2c, 2, &len);
    FUN_022e2f14((*(Ctx **)0x0380fff4)->port);

    if (len < 0xa4 || len > 0x1d6) {
        return 0;
    }

    len = len + 2;
    (*(Ctx **)0x0380fff4)->buf =
        FUN_037c58fc((*(Ctx **)0x0380fff4)->heap, len);
    if ((*(Ctx **)0x0380fff4)->buf == 0) {
        return 0;
    }
    (*(Ctx **)0x0380fff4)->buf = (char *)(*(Ctx **)0x0380fff4)->buf + 0xc;

    FUN_022e2efc((*(Ctx **)0x0380fff4)->port);
    FUN_022e2df4();
    FUN_022e2f08(0x2a, len, (*(Ctx **)0x0380fff4)->buf);
    FUN_022e2f14((*(Ctx **)0x0380fff4)->port);
    return 1;
}
