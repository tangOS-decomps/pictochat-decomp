// decomp: module=unk_autoload_0 addr=0x023293fc name=FUN_023293fc
// flags: -O4,s

// Records a member (MAC address + profile) in the 16-slot member table at
// G_023a0f70. A new member gets a "joined" system message, unless it is this
// console itself, plus a birthday message when the profile's birthday is
// today. The member then takes its existing slot or the first free one, and
// is marked present (1) or departed (2).

typedef unsigned char u8;
typedef unsigned short u16;

struct Mac {
    u16 w[3];
};

struct Profile {
    /* 0x00 */ u16 name[10];
    /* 0x14 */ u16 pad14[27];
    /* 0x4a */ u8 birthMonth;
    /* 0x4b */ u8 birthDay;
};

struct Member {
    /* 0x00 */ struct Mac mac;
    /* 0x06 */ struct Profile profile;
    /* 0x52 */ u16 pad52;
    /* 0x54 */ int state;
};

struct Date {
    int year;
    int month;
    int day;
    int week;
};

extern struct Member G_023a0f70[16];

extern struct Member *FUN_023294e4(struct Mac *);
extern void FUN_02334628(u16 *, u16 *, int);
extern int *FUN_023260bc(void);
extern void FUN_02329628(u16 *, int, u16 *);
extern void *FUN_02329994(void);
extern int FUN_02332e38(const void *, const void *, int);
extern void FUN_02326488(u16 *, int);
extern void FUN_02322c00(struct Date *);
extern void FUN_02329640(u16 *, u16 *);
extern void FUN_023274f8(void);

static inline int IsSameMac(const void *a, const void *b)
{
    return FUN_02332e38(a, b, 6) == 0;
}

void FUN_023293fc(struct Mac *mac, struct Profile *profile, int present)
{
    u16 name[10];
    struct Date date;
    u16 msg[0x82];
    struct Member *m;
    int i;

    m = FUN_023294e4(mac);
    if (m == 0) {
        FUN_02334628(name, profile->name, 10);
        msg[0] = 0;
        FUN_02329628(&msg[1], *FUN_023260bc(), name);
        if (present != 0 && !IsSameMac(FUN_02329994(), mac)) {
            FUN_02326488(&msg[1], 0x10);
            FUN_02322c00(&date);
            if (profile->birthMonth == date.month && profile->birthDay == date.day) {
                FUN_02329640(&msg[1], name);
                FUN_02326488(&msg[1], 0x12);
            }
        }
        for (i = 0; i < 16; i++) {
            m = &G_023a0f70[i];
            if (m->state == 0)
                goto found;
        }
        m = 0;
    }
found:
    if (m != 0) {
        m->mac = *mac;
        m->profile = *profile;
        m->state = present ? 1 : 2;
        if (m->state == 2)
            FUN_023274f8();
    }
}
