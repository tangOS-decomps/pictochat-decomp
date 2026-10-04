// decomp: module=unk_autoload_0 addr=0x02322104 name=FUN_02322104

// Polls the yes/no prompt of the scroll widget (state block at G_0238e028)
// while it is in mode 2 and the prompt is up: touching a button or pressing
// left/right moves the selection (with a click sound), A or a yes-touch
// returns the current selection, B or a no-touch returns 0. Otherwise -1.

struct Scroll {
    int pos;
    int bodyOfs;
    int edgeOfs;
    int thumb;
    int unk10;
    int active;
    int mode;
    int f1c;
    int choice;
};

extern struct Scroll G_0238e028;
extern char G_0238e050[];
extern char G_0233b4c4[];

extern void FUN_02321328(void *, void *);
extern int FUN_023213c4(void *, int);
extern int FUN_023212bc(int);
extern void FUN_02320978(int);

int FUN_02322104(void)
{
    int ret = -1;
    int yes;
    int no;

    if (G_0238e028.mode == 2 && G_0238e028.f1c == 1) {
        yes = 0;
        no = 0;
        FUN_02321328(G_0238e050, G_0233b4c4);
        if (FUN_023213c4(G_0238e050, 1)) {
            yes = 1;
            G_0238e028.choice = 1;
        } else if (FUN_023213c4(G_0238e050, 0)) {
            G_0238e028.choice = 0;
            no = 1;
        }
        if (FUN_023212bc(0x20)) {
            G_0238e028.choice = 0;
            FUN_02320978(0x1d);
        } else if (FUN_023212bc(0x10)) {
            G_0238e028.choice = 1;
            FUN_02320978(0x1d);
        } else if (FUN_023212bc(1) || yes) {
            ret = G_0238e028.choice;
        } else if (FUN_023212bc(2) || no) {
            ret = 0;
        }
    }
    return ret;
}
