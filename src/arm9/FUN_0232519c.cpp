// decomp: module=unk_autoload_0 addr=0x0232519c name=FUN_0232519c
// Cyclic counter advance: increments `cur`, sets `flag` if it just landed on
// `lo` or `hi`, and wraps back to `lo + 1` once it exceeds `hi`. Likely an
// animation-frame or blink-timer counter given the wrap-on-overflow shape.
struct Counter {
    unsigned short cur;
    unsigned short lo;
    unsigned short hi;
    unsigned short flag;
};
void FUN_0232519c(struct Counter *c)
{
    c->cur = c->cur + 1;
    if (c->cur == c->lo || c->cur == c->hi) {
        c->flag = 1;
    }
    if (c->cur > c->hi) {
        c->cur = c->lo + 1;
    }
}
