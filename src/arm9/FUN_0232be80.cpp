//cpp
// NONMATCHING: PR validator reports 22 differing words at its authoritative merge target (div=22). Logic retained as a draft; not byte-exact there.
// Counts as decompiled, not matched.
// decomp: module=unk_autoload_0 addr=0x0232be80 name=FUN_0232be80
// Reconstructed packet-send retry loop at 0x0232be80.

#pragma thumb on
extern "C" {
struct Packet0232be80 {
    int value;
    int cookie;
    unsigned short zero;
    unsigned short first;
    unsigned short second;
    unsigned short tag;
};

extern int G_023bd878[];
extern int G_023bd874;
extern int FUN_0232b514(void *, void *, int);
extern void FUN_0232a200(void);
extern void FUN_02329958(int);
extern void FUN_0232bf04(void);

int FUN_0232be80(unsigned short first, int value, unsigned short second, int once, int cookie) {
    struct Packet0232be80 packet;
    int i = 0;

    packet.zero = 0;
    packet.first = first;
    packet.value = value;
    packet.second = second;
    packet.cookie = 0;
    if (once != 1) {
        int shift = 1;
        do {
            packet.tag = 7 << shift;
            if (i == 4) {
                packet.cookie = cookie;
            } else {
                packet.cookie = 0;
            }
            if (FUN_0232b514(G_023bd878, &packet, 0x10) == 0) {
                FUN_0232a200();
                FUN_02329958(12);
            }
            i++;
            shift += 3;
        } while (i < 5);
    } else {
        packet.tag = 1;
        packet.cookie = cookie;
        if (FUN_0232b514(G_023bd878, &packet, 0x10) == 0) {
            FUN_02329958(12);
        }
    }
    if (G_023bd874 == 0) {
        FUN_0232bf04();
    }
    return 1;
}
}
