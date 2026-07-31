// ==========================================================
// C++ Class / Module Implementation: StringUtils.cpp
// ==========================================================

// --- memset.cpp ---
//cpp
// decomp: module=unk_autoload_0 addr=0x02332e70 name=FUN_02332e70
extern "C" void FUN_02332e70(unsigned char *dst, int c, unsigned int n) {
    unsigned int val = (unsigned char)c;

    if (n >= 0x20) {
        unsigned int count = (unsigned int)(-(int)(unsigned int)dst) & 3;
        if (count != 0) {
            n -= count;
            do {
                *dst++ = (unsigned char)val;
            } while (--count != 0);
        }

        if (val != 0) {
            val |= (val << 24) | (val << 16) | (val << 8);
        }

        count = n >> 5;
        if (count != 0) {
            do {
                ((unsigned int *)dst)[0] = val;
                ((unsigned int *)dst)[1] = val;
                ((unsigned int *)dst)[2] = val;
                ((unsigned int *)dst)[3] = val;
                ((unsigned int *)dst)[4] = val;
                ((unsigned int *)dst)[5] = val;
                ((unsigned int *)dst)[6] = val;
                unsigned int *q = (unsigned int *)dst + 7;
                dst += 32;
                q[0] = val;
            } while (--count != 0);
        }

        unsigned int nword = (n & 0x1f) >> 2;
        if (nword != 0) {
            do {
                *(unsigned int *)dst = val;
                dst += 4;
            } while (--nword != 0);
        }

        n &= 3;
    }

    if (n != 0) {
        do {
            *dst++ = (unsigned char)val;
        } while (--n != 0);
    }
}

// --- memchr.cpp ---
//cpp
extern "C" {
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

}

// --- memcmp.cpp ---
//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x02332e38 name=memcmp
// memcmp-style ordering comparator: returns 0 if the first n bytes of p0/p1
// are equal, else -1/1 by unsigned byte magnitude at the first mismatch
// (not a general difference like libc memcmp). The `if (p0[-1] < p1[-1])
// return -1; return 1;` polarity (rather than the more natural `>=` first)
// matters for the match - it decides which branch falls straight through
// to its own `pop {r3,r4}; bx lr` vs which one is reached by the bhs
// branch.
int memcmp(unsigned char *p0, unsigned char *p1, unsigned int n) {
    if (n != 0) {
        do {
            if (*p0++ != *p1++) {
                if (p0[-1] < p1[-1]) {
                    return -1;
                }
                return 1;
            }
        } while (--n != 0);
    }
    return 0;
}

}

// --- memcpy_bytes.cpp ---
//cpp
extern "C" {
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

}

// --- strlen_s8.cpp ---
//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x02334584 name=strlen_s8
int strlen_s8(const signed char *p) {
    int len = -1;
    int c;
    int zero = 0;
    do {
        len++;
        c = p[zero];
        p++;
    } while (c != 0);
    return len;
}

}

// --- wcslen.cpp ---
//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x023345fc name=wcslen
int wcslen(const unsigned short *p) {
    int len = -1;
    do {
        len++;
    } while (*p++ != 0);
    return len;
}

}

// --- SafeStoreByte.cpp ---
//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x02332d84 name=SafeStoreByte
int SafeStoreByte(char *ptr, char val) {
    if (ptr == 0) {
        return 0;
    }
    *ptr = val;
    return 1;
}

}

