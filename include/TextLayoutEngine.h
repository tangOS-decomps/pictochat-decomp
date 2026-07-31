#ifndef TEXT_LAYOUT_ENGINE_H
#define TEXT_LAYOUT_ENGINE_H

extern "C" {
    int TextLayout_DrawText(int a, int b, int c);
    int TextLayout_DrawGlyph(int a, int b, int c);
    int TextLayout_SetFont(int a, int b);
    int TextLayout_SetSpacing(int a, int b);
    int TextLayout_SetLineHeight(int a, int b);
}

class TextLayoutEngine {
public:
    inline int DrawText(int b, int c) { return TextLayout_DrawText((int)this, b, c); }
    inline int DrawGlyph(int b, int c) { return TextLayout_DrawGlyph((int)this, b, c); }
    inline int SetFont(int fontId) { return TextLayout_SetFont((int)this, fontId); }
    inline int SetSpacing(int pixels) { return TextLayout_SetSpacing((int)this, pixels); }
    inline int SetLineHeight(int height) { return TextLayout_SetLineHeight((int)this, height); }
};

#endif // TEXT_LAYOUT_ENGINE_H
