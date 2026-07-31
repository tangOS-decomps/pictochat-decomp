//cpp
// decomp: module=unk_autoload_0 addr=0x02320ed4 name=FUN_02320ed4
// decomp: module=unk_autoload_0 addr=0x02320ed4 name=FUN_02320ed4

class Class_02320c84 {
public:
    void DrawText(int a, int b, int d, int e, int f, int g, int h);
};

extern "C" void func_02320c84(int a, int b, Class_02320c84* self, int d, int e, int f, int g, int h, int i);

void Class_02320c84::DrawText(int a, int b, int d, int e, int f, int g, int h) {
    func_02320c84(a, b, this, d, e, f, g, h, -1);
}
