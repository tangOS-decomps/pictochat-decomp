// decomp: module=unk_autoload_0 addr=0x02332e1c name=memchr
// memchr-style byte search: scans n bytes from s for the byte value c,
// returning a pointer to the first match or NULL. The `if (n != 0) { do
// {...} while(--n) } return 0;` shape (rather than an early `if (n==0)
// return 0;`) matters for the match: it lets the compiler share a single
// tail `movs r0,#0; bx lr` between the "n was zero" and "loop exhausted"
// paths instead of emitting two copies.
void *memchr(unsigned char *s, int c, unsigned int n) {
    unsigned char ch = (unsigned char)c;
    if (n != 0) {
        do {
            if (*s++ == ch) {
                return s - 1;
            }
        } while (--n != 0);
    }
    return 0;
}
