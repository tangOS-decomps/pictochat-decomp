// decomp: module=unk_autoload_0 addr=0x02322554 name=FUN_02322554

// Recomputes the app's environment flag word (FUN_0232254c) from the user
// settings halfword at 0x02FFFCE4, the held keys and the boot flags at
// 0x02FFF890 / header byte 0x02FFFE1F: settings-incomplete and related
// bits, the bit-3 key state, and two debug-mode bits that need the boot
// flag plus either a key combo or the header bit.

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Flags {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
} Flags;

typedef struct Cfg {
    u16 lo : 6;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 b8 : 1;
    u16 b9 : 1;
    u16 b10 : 1;
    u16 b11 : 1;
    u16 b12 : 1;
    u16 b13 : 1;
    u16 b14 : 1;
    u16 b15 : 1;
} Cfg;

typedef struct Byte {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 hi : 5;
} Byte;

#define CFG (*(Cfg *)0x02FFFCE4)
#define BYTE (*(Byte *)0x02FFFE1F)

extern Flags *FUN_0232254c(void);
extern u16 FUN_023226d4(void);

static inline int isDev(void)
{
    return (*(volatile u32 *)0x02FFF890 & 2) ? 1 : 0;
}

void FUN_02322554(void)
{
    Flags *f = FUN_0232254c();
    u16 keys = FUN_023226d4();
    int a;
    int b;

    f->b2 = CFG.b9;
    f->b0 = (CFG.b13 & CFG.b15 & CFG.b11 & CFG.b14 & CFG.b10) == 0;
    f->b1 = CFG.b13;
    f->b8 = f->b0 | f->b2;
    f->b3 = (keys & 8) ? 1 : 0;

    a = 0;
    b = 0;
    if (isDev() && f->b8)
        b = 1;
    if (b && (keys & 0xD03) == 0xD03)
        a = 1;
    f->b6 = a;

    a = 0;
    if (isDev()) {
        b = 0;
        if (isDev() && BYTE.b2)
            b = 1;
        if (b)
            a = 1;
    }
    f->b6 = f->b6 | a;

    a = 0;
    b = 0;
    if (CFG.b6 && isDev())
        b = 1;
    if (b && !f->b3)
        a = 1;
    f->b5 = a;
}
