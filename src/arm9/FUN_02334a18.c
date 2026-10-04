// decomp: module=unk_autoload_0 addr=0x02334a18 name=FUN_02334a18

// MSL ansi_fp __timesdec: schoolbook multiplication of two decimal digit
// strings. Column sums are accumulated from the least significant digit up,
// the product keeps at most 32 significant digits, and the dropped tail is
// rounded half-to-even via __rounddec.

typedef struct decimal {
    char sign;
    char unused;
    short exp;
    struct {
        unsigned char length;
        unsigned char text[32];
        unsigned char unused;
    } sig;
} decimal;

void FUN_02334948(decimal *d, int digits); /* __rounddec */

void FUN_02334a18(decimal *result, const decimal *x, const decimal *y)
{
    unsigned long accumulator = 0;
    unsigned char mantissa[64];
    int i = x->sig.length + y->sig.length - 1;
    unsigned char *pDigit = mantissa + i + 1;
    unsigned char *pEnd = pDigit;
    unsigned char *ip;

    result->sign = 0;

    for (; i > 0; i--) {
        int k = y->sig.length - 1;
        int j = i - k - 1;
        int l;
        int t;
        const unsigned char *xp;
        const unsigned char *yp;

        if (j < 0) {
            j = 0;
            k = i - 1;
        }

        xp = x->sig.text + j;
        yp = y->sig.text + k;
        l = k + 1;
        t = x->sig.length - j;

        if (l > t)
            l = t;

        for (; l > 0; l--, xp++, yp--)
            accumulator += *xp * *yp;

        *--pDigit = (unsigned char)(accumulator % 10);
        accumulator /= 10;
    }

    result->exp = (short)(x->exp + y->exp);

    if (accumulator) {
        *--pDigit = (unsigned char)accumulator;
        result->exp++;
    }

    for (i = 0; i < 32 && pDigit < pEnd; i++, pDigit++)
        result->sig.text[i] = *pDigit;

    result->sig.length = (unsigned char)i;

    if (pDigit < pEnd && *pDigit >= 5) {
        if (*pDigit != 5)
            goto round;

        for (ip = pDigit + 1; ip < pEnd; ip++)
            if (*ip)
                goto round;

        if ((*(pDigit - 1) & 1) == 0)
            return;

    round:
        FUN_02334948(result, result->sig.length);
    }
}
