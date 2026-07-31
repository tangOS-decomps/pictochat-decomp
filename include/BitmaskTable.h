#ifndef BITMASK_TABLE_H
#define BITMASK_TABLE_H

extern "C" {
    int Bitmask_GetBit2(int a);
    int Bitmask_GetBit3(int a);
    int Bitmask_GetBit4(int a);
    int Bitmask_GetWord0(void);
    int Bitmask_GetWord1(void);
    int Bitmask_GetWord2(void);
    int Bitmask_GetWord3(void);
    void Bitmask_SetFlag9(void);
}

class BitmaskTable {
public:
    inline int GetBit2(int val) const { return Bitmask_GetBit2(val); }
    inline int GetBit3(int val) const { return Bitmask_GetBit3(val); }
    inline int GetBit4(int val) const { return Bitmask_GetBit4(val); }
    inline int GetWord0() const { return Bitmask_GetWord0(); }
    inline int GetWord1() const { return Bitmask_GetWord1(); }
    inline int GetWord2() const { return Bitmask_GetWord2(); }
    inline int GetWord3() const { return Bitmask_GetWord3(); }
    inline void SetFlag9() { Bitmask_SetFlag9(); }
};

#endif // BITMASK_TABLE_H
