//cpp
// decomp: module=unk_autoload_0 addr=0x02320e3c name=FUN_02320e3c
// decomp: module=unk_autoload_0 addr=0x02320e3c name=FUN_02320e3c

class Class_02320c84 {
public:
    void DrawText(int a, int b, int d, int e);
};

extern "C" void func_02320c84(int a, int b, Class_02320c84* self, int d, int e, int f, int g, int h, int i);

void Class_02320c84::DrawText(int a, int b, int d, int e) {
    int zero = 0;
    int neg1 = zero - 1;
    func_02320c84(a, b, this, d, zero, zero, e, neg1, neg1);
}
