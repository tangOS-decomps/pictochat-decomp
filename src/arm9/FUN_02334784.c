// decomp: module=unk_autoload_0 addr=0x02334784 name=FUN_02334784

// ldexp / fdlibm scalbn: x * 2^n by editing the exponent field directly,
// with MSL's up-front pass-through for 0, infinities and NaNs. Subnormal
// inputs are normalised by 2^54 first and subnormal results are scaled back
// by 2^-54; out-of-range results saturate to +-huge or +-tiny.

#define __HI(x) (((int *)&x)[1])
#define __LO(x) (((int *)&x)[0])

int FUN_02334f98(double x);               /* __fpclassifyd */
double FUN_023346cc(double x, double y);  /* copysign */

static const double two54 = 1.80143985094819840000e+16;
static const double twom54 = 5.55111512312578270212e-17;
static const double huge = 1.0e+300;
static const double tiny = 1.0e-300;

double FUN_02334784(double x, int n)
{
    int k, hx, lx;

    if (FUN_02334f98(x) <= 2 || x == 0.0)
        return x;
    hx = __HI(x);
    lx = __LO(x);
    k = (hx & 0x7ff00000) >> 20;
    if (k == 0) {
        if ((lx | (hx & 0x7fffffff)) == 0)
            return x;
        x *= two54;
        hx = __HI(x);
        k = ((hx & 0x7ff00000) >> 20) - 54;
        if (n < -50000)
            return tiny * x;
    }
    if (k == 0x7ff)
        return x + x;
    k = k + n;
    if (k > 0x7fe)
        return huge * FUN_023346cc(huge, x);
    if (k > 0) {
        __HI(x) = (hx & 0x800fffff) | (k << 20);
        return x;
    }
    if (k <= -54) {
        if (n > 50000)
            return huge * FUN_023346cc(huge, x);
        else
            return tiny * FUN_023346cc(tiny, x);
    }
    k += 54;
    __HI(x) = (hx & 0x800fffff) | (k << 20);
    return x * twom54;
}
