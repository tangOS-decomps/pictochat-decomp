// decomp: module=unk_autoload_0 addr=0x02323f80 name=FUN_02323f80
// flags: -O4,s

// Tints the rectangle [x0,x1) x [y0,y1) of a 4bpp tiled canvas that is
// `width` pixels wide: walks the 8x8 tiles the rectangle touches, builds a
// row mask holding `color` in every covered nibble, drops the nibbles whose
// pixel is still transparent (0), and adds the rest into each covered row.

typedef unsigned int u32;

void FUN_02323f80(void *buf, int width, u32 color, int x0, int y0, int x1, int y1)
{
    int tx0;
    int tx1;
    int ty1;
    u32 *tile;
    int ty;
    int tx;
    int px0;
    int px1;
    int py1;
    int py;
    int i;
    u32 mask;
    u32 add;
    u32 row;

    if (x0 >= x1 || y0 >= y1)
        return;

    tx0 = x0 >> 3;
    tx1 = ((x1 - 1) >> 3) + 1;
    ty1 = ((y1 - 1) >> 3) + 1;
    for (ty = y0 >> 3; ty < ty1; ty++) {
        for (tx = tx0; tx < tx1; tx++) {
            px0 = (x0 - tx * 8 < 0) ? 0 : x0 - tx * 8;
            py = (y0 - ty * 8 < 0) ? 0 : y0 - ty * 8;
            px1 = x1 - tx * 8;
            if (px1 > 8)
                px1 = 8;
            py1 = (y1 - ty * 8 > 8) ? 8 : y1 - ty * 8;
            tile = (u32 *)((char *)buf + (tx + ty * (width >> 3)) * 32);
            mask = 0;
            for (i = 0; i < px1 - px0; i++)
                mask |= color << (i * 4);
            mask <<= px0 * 4;
            for (; py < py1; py++) {
                add = mask;
                row = tile[py];
                if (!(row & 0xF0000000))
                    add &= 0x0FFFFFFF;
                if (!(row & 0x0F000000))
                    add &= 0xF0FFFFFF;
                if (!(row & 0x00F00000))
                    add &= 0xFF0FFFFF;
                if (!(row & 0x000F0000))
                    add &= 0xFFF0FFFF;
                if (!(row & 0x0000F000))
                    add &= 0xFFFF0FFF;
                if (!(row & 0x00000F00))
                    add &= 0xFFFFF0FF;
                if (!(row & 0x000000F0))
                    add &= ~0xF0;
                if (!(row & 0x0000000F))
                    add &= ~0xF;
                tile[py] += add;
            }
        }
    }
}
