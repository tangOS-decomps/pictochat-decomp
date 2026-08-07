// decomp: module=arm7 addr=0x022d6414 name=FUN_022d6414
// flags: -noThumb

// Builds and posts a type-0x23 report message: the 0x1c-byte payload is
// gathered into a stack scratch buffer by FUN_022d6470 (which also returns the
// status halfword), the message header records the caller's handle, and the
// payload is copied into the message body before it is queued.

extern int FUN_022d6470(void *src, void *out);
extern void *FUN_037d14bc(void);
extern void FUN_037d1464(void *msg);
extern void FUN_037cb8b4(const void *src, void *dst, unsigned int len);

typedef struct Report {
    unsigned short cmd;
    unsigned short status;
    int handle;
    char body[0x1c];
} Report;

void FUN_022d6414(int *ctx)
{
    char buf[0x1c];
    int status = FUN_022d6470(ctx + 1, buf);
    Report *msg = (Report *)FUN_037d14bc();

    msg->cmd = 0x23;
    msg->status = status;
    msg->handle = ctx[1];
    FUN_037cb8b4(buf, msg->body, 0x1c);
    FUN_037d1464(msg);
}
