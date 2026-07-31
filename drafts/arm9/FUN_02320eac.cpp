//cpp
// decomp: module=unk_autoload_0 addr=0x02320eac name=FUN_02320eac
// decomp: module=unk_autoload_0 addr=0x02320eac name=FUN_02320eac

class Class_02320c84 {
public:
    void DrawText(int a, int b, int d, int e, int f, int g);
};

extern "C" void func_02320c84(int a, int b, Class_02320c84* self, int d, int e, int f, int g, int h, int i);

void Class_02320c84::DrawText(int a, int b, int d, int e, int f, int g) {
    int zero = 0;
    int neg1 = ~zero;
    func_02320c84(a, b, this, d, e, f, neg1, g, neg1);
}
