// decomp: module=unk_autoload_0 addr=0x02320728 name=FUN_02320728
extern "C" {
    extern char gBufferStart_02348ee4[];
    extern char gBufferEnd_023490e4[];
    void func_02336840(void* dst, int val, int size);
    void func_0232074c(int mode);

    void FUN_02320728(int mode) {
        int size = (int)(gBufferEnd_023490e4 - gBufferStart_02348ee4) - 0x20;
        func_02336840(gBufferStart_02348ee4, 0, size);
        func_0232074c(mode);
    }
}
