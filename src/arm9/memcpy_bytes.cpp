// decomp: module=unk_autoload_0 addr=0x02332df4 name=memcpy_bytes
// A memcpy-style byte copy (dst, src, n) that returns the original dst
// pointer, like libc memcpy - hence a separate walking pointer `d` (not
// mutating `dst` itself) so r0 is left untouched by the loop and still
// holds the caller's original pointer at return. The Thumb1 LDRSB
// register+register-only addressing (no immediate-offset form) is why the
// real binary's loop carries a permanently-zero index register alongside
// the incrementing src pointer - that's just how a plain `*src++` compiles
// here for a signed-char source, not anything the source needs to spell
// out.
void *memcpy_bytes(char *dst, char *src, unsigned int n) {
    char *d = dst;
    if (n != 0) {
        do {
            *d++ = *src++;
        } while (--n != 0);
    }
    return dst;
}
