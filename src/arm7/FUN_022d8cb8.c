// decomp: module=arm7 addr=0x022d8cb8 name=FUN_022d8cb8
// flags: -O4,s -noThumb

// Splits a packed 0x24-byte header + trailing payload out of `src`: the header
// is copied to `hdr`, and when `len` is non-zero the payload following it is
// copied to `body` rounded up to a halfword count.

extern void FUN_037cb78c(void *dst, const void *src, int n);

void FUN_022d8cb8(const unsigned char *src, void *hdr, void *body, int len)
{
    FUN_037cb78c(hdr, src, 0x24);
    if (len != 0) {
        FUN_037cb78c(body, src + 0x24, (len + 1) & ~1);
    }
}
