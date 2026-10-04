// decomp: module=unk_autoload_0 addr=0x02333f20 name=FUN_02333f20
//
// printf-family formatting core: walks the format string, writes literal runs
// through the caller's write callback, parses each %-spec with FUN_02332ee4,
// renders the argument into a 512-byte scratch buffer (integer, float, hex
// float, string/wide string, %n, %c, %%) and pads it to the field width.
// Returns the number of characters written, or -1 if the callback fails.
// Size is the untruncated 0x5e0 (Ghidra's 0x594 omits the tail and pool).
//
// Phrasing that the bytes depend on:
//  - the ptrdiff and long-double va_arg branches use their own types, so the
//    compiler keeps them as separate (identical-looking) branches;
//  - one double variable serves both %f and %a: the %a use becomes a second
//    live range with its own late spill slot, as in the ROM;
//  - the integer cases jump to their shared length computation on success.

typedef unsigned int size_t;
typedef unsigned short wchar_t;
typedef char *va_list;

#define VA_ARG(ap, T) (*(T *)((ap += sizeof(T)) - sizeof(T)))

#define BUFF_SIZE 512

enum {
    ARG_NORMAL,
    ARG_CHAR,
    ARG_SHORT,
    ARG_LONG,
    ARG_LONG_LONG,
    ARG_WCHAR,
    ARG_INTMAX,
    ARG_SIZE_T,
    ARG_PTRDIFF,
    ARG_LONG_DOUBLE
};

enum {
    JUSTIFY_LEFT,
    JUSTIFY_RIGHT,
    JUSTIFY_ZERO_FILL
};

typedef struct Format {
    unsigned char justification;
    unsigned char sign;
    unsigned char precision_specified;
    unsigned char alternate_form;
    unsigned char argument_options;
    unsigned char conversion_char;
    int field_width;
    int precision;
} Format;

typedef void *(*WriteProc)(void *arg, const char *buf, size_t n);

extern const wchar_t G_0236a09c[];
extern const char G_0236a0a0[];

extern char *FUN_023345d0(const char *s, int c);
extern size_t FUN_02334584(const char *s);
extern const char *FUN_02332ee4(const char *s, va_list *arg, Format *format);
extern char *FUN_02333288(long num, char *buff, Format format);
extern char *FUN_02333434(long long num, char *buff, Format format);
extern char *FUN_02333a38(long double num, char *buff, Format format);
extern char *FUN_02333648(long double num, char *buff, Format format);
extern int FUN_02332da4(char *dst, const wchar_t *src, size_t n);
extern void *FUN_02332e1c(const void *s, int c, size_t n);

int FUN_02333f20(WriteProc proc, void *procArg, const char *format_ptr, va_list arg)
{
    int num_chars;
    int chars_written;
    int field_width;
    Format format;
    long long_num;
    long long long_long_num;
    long double double_num;
    const char *curr_format;
    char buff[BUFF_SIZE];
    char *buff_ptr;
    char *string_end;
    char fill_char = ' ';

    chars_written = 0;

    while (*format_ptr) {
        curr_format = FUN_023345d0(format_ptr, '%');
        if (curr_format == 0) {
            num_chars = FUN_02334584(format_ptr);
            chars_written += num_chars;
            if (num_chars && !proc(procArg, format_ptr, num_chars))
                return -1;
            break;
        }

        num_chars = curr_format - format_ptr;
        chars_written += num_chars;
        if (num_chars && !proc(procArg, format_ptr, num_chars))
            return -1;

        format_ptr = FUN_02332ee4(curr_format, &arg, &format);

        switch (format.conversion_char) {
        case 'd':
        case 'i':
            if (format.argument_options == ARG_LONG)
                long_num = VA_ARG(arg, long);
            else if (format.argument_options == ARG_LONG_LONG)
                long_long_num = VA_ARG(arg, long long);
            else if (format.argument_options == ARG_INTMAX)
                long_long_num = VA_ARG(arg, long long);
            else if (format.argument_options == ARG_SIZE_T)
                long_num = VA_ARG(arg, size_t);
            else if (format.argument_options == ARG_PTRDIFF)
                long_num = VA_ARG(arg, long);
            else
                long_num = VA_ARG(arg, int);

            if (format.argument_options == ARG_SHORT)
                long_num = (short)long_num;
            if (format.argument_options == ARG_CHAR)
                long_num = (signed char)long_num;

            if (format.argument_options == ARG_LONG_LONG || format.argument_options == ARG_INTMAX) {
                if ((buff_ptr = FUN_02333434(long_long_num, buff + BUFF_SIZE, format)) != 0)
                    goto signed_done;
            } else {
                if ((buff_ptr = FUN_02333288(long_num, buff + BUFF_SIZE, format)) != 0)
                    goto signed_done;
            }
            goto conversion_error;
        signed_done:
            num_chars = buff + BUFF_SIZE - 1 - buff_ptr;
            break;

        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (format.argument_options == ARG_LONG)
                long_num = VA_ARG(arg, unsigned long);
            else if (format.argument_options == ARG_LONG_LONG)
                long_long_num = VA_ARG(arg, long long);
            else if (format.argument_options == ARG_INTMAX)
                long_long_num = VA_ARG(arg, long long);
            else if (format.argument_options == ARG_SIZE_T)
                long_num = VA_ARG(arg, size_t);
            else if (format.argument_options == ARG_PTRDIFF)
                long_num = VA_ARG(arg, long);
            else
                long_num = VA_ARG(arg, unsigned int);

            if (format.argument_options == ARG_SHORT)
                long_num = (unsigned short)long_num;
            if (format.argument_options == ARG_CHAR)
                long_num = (unsigned char)long_num;

            if (format.argument_options == ARG_LONG_LONG || format.argument_options == ARG_INTMAX) {
                if ((buff_ptr = FUN_02333434(long_long_num, buff + BUFF_SIZE, format)) != 0)
                    goto unsigned_done;
            } else {
                if ((buff_ptr = FUN_02333288(long_num, buff + BUFF_SIZE, format)) != 0)
                    goto unsigned_done;
            }
            goto conversion_error;
        unsigned_done:
            num_chars = buff + BUFF_SIZE - 1 - buff_ptr;
            break;

        case 'f':
        case 'F':
        case 'e':
        case 'E':
        case 'g':
        case 'G':
            if (format.argument_options == ARG_LONG_DOUBLE)
                double_num = VA_ARG(arg, long double);
            else
                double_num = VA_ARG(arg, double);
            if (!(buff_ptr = FUN_02333a38(double_num, buff + BUFF_SIZE, format)))
                goto conversion_error;
            num_chars = buff + BUFF_SIZE - 1 - buff_ptr;
            break;

        case 'a':
        case 'A':
            if (format.argument_options == ARG_LONG_DOUBLE)
                double_num = VA_ARG(arg, long double);
            else
                double_num = VA_ARG(arg, double);
            if (!(buff_ptr = FUN_02333648(double_num, buff + BUFF_SIZE, format)))
                goto conversion_error;
            num_chars = buff + BUFF_SIZE - 1 - buff_ptr;
            break;

        case 's':
            if (format.argument_options == ARG_WCHAR) {
                const wchar_t *wcs = VA_ARG(arg, const wchar_t *);
                if (wcs == 0)
                    wcs = G_0236a09c;
                if (FUN_02332da4(buff, wcs, BUFF_SIZE) < 0)
                    goto conversion_error;
                buff_ptr = buff;
            } else {
                buff_ptr = VA_ARG(arg, char *);
            }
            if (buff_ptr == 0)
                buff_ptr = (char *)G_0236a0a0;
            if (format.alternate_form) {
                num_chars = (unsigned char)*buff_ptr++;
                if (format.precision_specified && num_chars > format.precision)
                    num_chars = format.precision;
            } else if (format.precision_specified) {
                num_chars = format.precision;
                if ((string_end = FUN_02332e1c(buff_ptr, 0, num_chars)) != 0)
                    num_chars = string_end - buff_ptr;
            } else {
                num_chars = FUN_02334584(buff_ptr);
            }
            break;

        case 'n':
            buff_ptr = VA_ARG(arg, char *);
            switch (format.argument_options) {
            case ARG_NORMAL:
                *(int *)buff_ptr = chars_written;
                break;
            case ARG_SHORT:
                *(short *)buff_ptr = chars_written;
                break;
            case ARG_LONG:
                *(long *)buff_ptr = chars_written;
                break;
            case ARG_INTMAX:
                *(long long *)buff_ptr = chars_written;
                break;
            case ARG_SIZE_T:
                *(size_t *)buff_ptr = chars_written;
                break;
            case ARG_PTRDIFF:
                *(int *)buff_ptr = chars_written;
                break;
            case ARG_LONG_LONG:
                *(long long *)buff_ptr = chars_written;
                break;
            }
            continue;

        case 'c':
            buff_ptr = buff;
            *buff_ptr = VA_ARG(arg, int);
            num_chars = 1;
            break;

        case '%':
            buff_ptr = buff;
            *buff_ptr = '%';
            num_chars = 1;
            break;

        case 0xff:
        default:
        conversion_error:
            num_chars = FUN_02334584(curr_format);
            if (num_chars && !proc(procArg, curr_format, num_chars))
                return -1;
            return chars_written + num_chars;
        }

        field_width = num_chars;
        if (format.justification != JUSTIFY_LEFT) {
            fill_char = (format.justification == JUSTIFY_ZERO_FILL) ? '0' : ' ';
            if ((*buff_ptr == '+' || *buff_ptr == '-' || *buff_ptr == ' ') && fill_char == '0') {
                if (!proc(procArg, buff_ptr, 1))
                    return -1;
                ++buff_ptr;
                num_chars--;
            }
            while (field_width < format.field_width) {
                if (!proc(procArg, &fill_char, 1))
                    return -1;
                ++field_width;
            }
        }
        if (num_chars && !proc(procArg, buff_ptr, num_chars))
            return -1;
        if (format.justification == JUSTIFY_LEFT) {
            while (field_width < format.field_width) {
                char blank = ' ';
                if (!proc(procArg, &blank, 1))
                    return -1;
                ++field_width;
            }
        }
        chars_written += field_width;
    }

    return chars_written;
}
