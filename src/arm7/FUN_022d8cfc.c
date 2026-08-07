// decomp: module=arm7 addr=0x022d8cfc name=FUN_022d8cfc
// flags: -O4,s -noThumb

// Same shape as FUN_022d8cb8 but the payload starts at +0x28 instead of +0x24:
// copies the 0x24-byte header to `hdr`, then the halfword-rounded payload to
// `body` when `len` is non-zero.

extern void FUN_037cb78c(void *dst, const void *src, int n);

void FUN_022d8cfc(const unsigned char *src, void *hdr, void *body, int len)
{
    FUN_037cb78c(hdr, src, 0x24);
    if (len != 0) {
        FUN_037cb78c(body, src + 0x28, (len + 1) & ~1);
    }
}
