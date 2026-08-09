//cpp
// decomp: module=unk_autoload_0 addr=0x0232cc64 name=FUN_0232cc64
#pragma thumb on

extern "C" {
typedef unsigned char u8;
typedef unsigned short u16;

extern int FUN_0232c520(int, int, int, int);
extern void FUN_0232c3bc(int, int);
extern int FUN_0232c484(const void *, int);

struct Msg0232cc64 {
    u16 type;
    u16 count;
    int data;
    u16 value;
    u8 bytes[6];
};

struct Src0232cc64 {
    int data;
    u16 count;
    u16 value;
    u8 bytes[6];
};

int FUN_0232cc64(int arg, const Src0232cc64 *src, int, int)
{
    int result = FUN_0232c520(3, 2, 3, 5);
    if (result == 0) {
        if (src == 0) {
            return 6;
        }
        if (src->data == 0) {
            return 6;
        }
        if (src->count < 1 || src->count > 14) {
            return 6;
        }

        FUN_0232c3bc(10, arg);
        Msg0232cc64 msg;
        msg.type = 10;
        msg.count = src->count;
        msg.data = src->data;
        msg.value = src->value;
        msg.bytes[0] = src->bytes[0];
        msg.bytes[1] = src->bytes[1];
        msg.bytes[2] = src->bytes[2];
        msg.bytes[3] = src->bytes[3];
        msg.bytes[4] = src->bytes[4];
        msg.bytes[5] = src->bytes[5];
        result = FUN_0232c484(&msg, 16);
        if (result == 0) {
            result = 2;
        }
    }
    return result;
}
}
