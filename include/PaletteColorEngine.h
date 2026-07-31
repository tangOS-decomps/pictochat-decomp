#ifndef PALETTE_COLOR_ENGINE_H
#define PALETTE_COLOR_ENGINE_H

extern "C" {
    void Palette_InitBounds(char *p);
    void Palette_StepAnimation(void *c);
    void Palette_ResetState(char *p);
    int Palette_GetActiveColor(unsigned short *p);
}

class PaletteColorEngine {
private:
    unsigned short m_cur;   // 0x0
    unsigned short m_lo;    // 0x2
    unsigned short m_hi;    // 0x4
    unsigned short m_flag;  // 0x6

public:
    inline void InitBounds() { Palette_InitBounds((char *)this); }
    inline void StepAnimation() { Palette_StepAnimation((void *)this); }
    inline void ResetState() { Palette_ResetState((char *)this); }
    inline int GetActiveColor() const { return Palette_GetActiveColor((unsigned short *)this); }
};

#endif // PALETTE_COLOR_ENGINE_H
