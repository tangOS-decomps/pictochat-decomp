// decomp: module=unk_autoload_0 addr=0x02334b80 name=FUN_02334b80

// MSL ansi_fp __two_exp: writes 2^exp into a decimal. Small exponents come
// straight from a table of digit strings; anything else squares 2^(exp/2) and
// multiplies by one more 2 (or 5e-1) when exp is odd.

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

void FUN_02334b20(decimal *d, const char *s, short exp);
void FUN_02334a18(decimal *dst, const decimal *x, const decimal *y);

void FUN_02334b80(decimal *result, long exp)
{
    switch (exp) {
    case -64:
        FUN_02334b20(result, "542101086242752217003726400434970855712890625", -20);
        return;
    case -53:
        FUN_02334b20(result, "11102230246251565404236316680908203125", -16);
        return;
    case -32:
        FUN_02334b20(result, "23283064365386962890625", -10);
        return;
    case -16:
        FUN_02334b20(result, "152587890625", -5);
        return;
    case -8:
        FUN_02334b20(result, "390625", -3);
        return;
    case -7:
        FUN_02334b20(result, "78125", -3);
        return;
    case -6:
        FUN_02334b20(result, "15625", -2);
        return;
    case -5:
        FUN_02334b20(result, "3125", -2);
        return;
    case -4:
        FUN_02334b20(result, "625", -2);
        return;
    case -3:
        FUN_02334b20(result, "125", -1);
        return;
    case -2:
        FUN_02334b20(result, "25", -1);
        return;
    case -1:
        FUN_02334b20(result, "5", -1);
        return;
    case 0:
        FUN_02334b20(result, "1", 0);
        return;
    case 1:
        FUN_02334b20(result, "2", 0);
        return;
    case 2:
        FUN_02334b20(result, "4", 0);
        return;
    case 3:
        FUN_02334b20(result, "8", 0);
        return;
    case 4:
        FUN_02334b20(result, "16", 1);
        return;
    case 5:
        FUN_02334b20(result, "32", 1);
        return;
    case 6:
        FUN_02334b20(result, "64", 1);
        return;
    case 7:
        FUN_02334b20(result, "128", 2);
        return;
    case 8:
        FUN_02334b20(result, "256", 2);
        return;
    default: {
        decimal x2, temp;

        FUN_02334b80(&x2, ((long)((0x80000000UL & exp) >> 31) + exp) >> 1);
        FUN_02334a18(result, &x2, &x2);
        if (exp & 1) {
            temp = *result;
            if (exp > 0)
                FUN_02334b20(&x2, "2", 0);
            else
                FUN_02334b20(&x2, "5", -1);
            FUN_02334a18(result, &temp, &x2);
        }
    }
    }
}
