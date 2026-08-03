// decomp: module=unk_autoload_0 addr=0x02323834 name=FUN_02323834
struct AppState {
    char pad_00[0x34];
    int val;
};
extern struct AppState G_0238ef0c;

int FUN_02323834(void) {
    return G_0238ef0c.val;
}
