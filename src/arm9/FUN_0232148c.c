// flags: -O4,s
// decomp: module=unk_autoload_0 addr=0x0232148c name=FUN_0232148c
#pragma thumb on

// Draws a straight line between (x0,y0) and (x1,y1) on the chat canvas.
// Steps one pixel at a time along whichever axis spans further and carries a
// 20.12 fixed-point slope along the other; FUN_02321480 is |a-b| and
// FUN_02321408 plots a single pixel.
extern int FUN_02321480(int a, int b);
extern void FUN_02321408(int ctx, int x, int y, int color);

void FUN_0232148c(int ctx, int x0, int y0, int x1, int y1, int color)
{
    int t;
    int i;
    int acc;
    int count1, count2, step1, step2;

    if (FUN_02321480(x0, x1) > FUN_02321480(y0, y1)) {
        if (x0 > x1) {
            t = x0; x0 = x1; x1 = t;
            t = y0; y0 = y1; y1 = t;
        }
        count1 = x1 - x0;
        step1 = ((y1 - y0) << 12) / count1;
        for (i = 0, acc = 0; i < count1; i++) {
            FUN_02321408(ctx, x0 + i, y0 + (acc >> 12), color);
            acc += step1;
        }
    } else {
        if (y0 > y1) {
            t = x0; x0 = x1; x1 = t;
            t = y0; y0 = y1; y1 = t;
        }
        count2 = y1 - y0;
        step2 = ((x1 - x0) << 12) / count2;
        for (i = 0, acc = 0; i < count2; i++) {
            FUN_02321408(ctx, x0 + (acc >> 12), y0 + i, color);
            acc += step2;
        }
    }
}
