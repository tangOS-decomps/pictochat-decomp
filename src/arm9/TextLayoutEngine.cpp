// ==========================================================
// C++ Class Implementation: TextLayoutEngine.cpp
// ==========================================================

// --- TextLayoutEngine ---
//cpp
extern "C" {
// decomp: module=unk_autoload_0 addr=0x02329628 name=TextLayout_DrawText
extern int FUN_02329668(int a, int b, int c, int code);
int TextLayout_DrawText(int a, int b, int c) {
    return FUN_02329668(a, b, c, 5);
}

// decomp: module=unk_autoload_0 addr=0x02329634 name=TextLayout_DrawGlyph
int TextLayout_DrawGlyph(int a, int b, int c) {
    return FUN_02329668(a, b, c, 6);
}

// decomp: module=unk_autoload_0 addr=0x02329640 name=TextLayout_SetFont
int TextLayout_SetFont(int a, int b) {
    return FUN_02329668(a, 0, b, 4);
}

// decomp: module=unk_autoload_0 addr=0x02329650 name=TextLayout_SetSpacing
int TextLayout_SetSpacing(int a, int b) {
    return FUN_02329668(a, b, 0, 0x34);
}

// decomp: module=unk_autoload_0 addr=0x0232965c name=TextLayout_SetLineHeight
int TextLayout_SetLineHeight(int a, int b) {
    return FUN_02329668(a, b, 0, 0x39);
}

}
