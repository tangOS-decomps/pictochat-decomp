//cpp
// decomp: module=unk_autoload_0 addr=0x02331bfc name=FUN_02331bfc

#pragma thumb on
extern "C" {
extern unsigned short G_023c0adc[];
void FUN_02331bfc(int a) { G_023c0adc[0] &= ~(1 << a); }
}
