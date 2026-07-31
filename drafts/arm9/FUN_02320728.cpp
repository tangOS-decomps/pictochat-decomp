//cpp
// decomp: module=unk_autoload_0 addr=0x02320728 name=FUN_02320728

extern "C" {
    extern char gBufferStart_02320728[];
    extern char gBufferEnd_02320728[];

    void func_02336840(void* dst, int val, int size);
    void func_0232074c(int mode);
}

class Class_02320728 {
public:
    static void ClearAndInit(int mode);
};

void Class_02320728::ClearAndInit(int mode) {
    int size = (int)(gBufferEnd_02320728 - gBufferStart_02320728) - 0x20;
    func_02336840(gBufferStart_02320728, 0, size);
    func_0232074c(mode);
}
