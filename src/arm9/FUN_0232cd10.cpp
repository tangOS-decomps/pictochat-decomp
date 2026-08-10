//cpp
// decomp: module=unk_autoload_0 addr=0x0232cd10 name=FUN_0232cd10
#pragma thumb on

extern "C" {
typedef unsigned char u8;
typedef unsigned short u16;

extern int FUN_0232c520(int, int);
extern void FUN_023314e8(const void *, int);
extern void *FUN_0232c4d0(void);
extern void FUN_0232c3bc(int, int);
extern void FUN_02337584(const void *, void *, int);
extern void FUN_023374f0(void *, int, int);
extern int FUN_0232c484(const void *, int);

struct Msg0232cd10 {
    u16 type;
    u16 unused0;
    const u16 *data;
    u8 bytes[24];
    int arg;
    u16 unused1;
    u16 last;
};

int FUN_0232cd10(int arg0, const u16 *data, const void *src, int arg3, u16 arg4)
{
    int result = FUN_0232c520(1, 2);
    if (result == 0) {
        if (data == 0) {
            return 6;
        }

        FUN_023314e8(data, *data << 1);
        char *state = (char *)FUN_0232c4d0();
        *(u16 *)(state + 0x150) = 0;
        *(int *)(state + 0x14c) = 0;
        FUN_0232c3bc(12, arg0);

        Msg0232cd10 msg;
        msg.type = 12;
        msg.data = data;
        if (src != 0) {
            FUN_02337584(src, msg.bytes, 24);
        } else {
            FUN_023374f0(msg.bytes, 0, 24);
        }
        msg.arg = arg3;
        msg.last = arg4;
        result = FUN_0232c484(&msg, 40);
        if (result == 0) {
            result = 2;
        }
    }
    return result;
}
}
