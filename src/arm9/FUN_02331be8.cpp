//cpp
#pragma thumb on
extern "C" {
extern unsigned short G_023c0adc[];
void FUN_02331be8(int a) { G_023c0adc[0] |= (1 << a); }
}