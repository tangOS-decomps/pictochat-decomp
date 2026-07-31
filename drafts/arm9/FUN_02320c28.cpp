// decomp: module=unk_autoload_0 addr=0x02320c28 name=FUN_02320c28
struct Elem { char pad[6]; short v; };
void FUN_02320c28(struct Elem *out, int *in) {
    out[0].v = in[0] >> 4;
    out[1].v = in[1] >> 4;
    out[2].v = in[2] >> 4;
    out[3].v = in[3] >> 4;
}
