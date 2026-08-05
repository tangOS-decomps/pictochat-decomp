//cpp
#pragma thumb on
extern "C" {
extern unsigned int G_04001000[];
void FUN_023363f0(unsigned int a) { G_04001000[0] = (G_04001000[0] & ~7) | a; }
}