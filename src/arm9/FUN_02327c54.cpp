//cpp
#pragma thumb on
extern "C" {
extern int FUN_02326bac(int);
extern void FUN_02320978(int);
void FUN_02327c54(int* a) { if (FUN_02326bac(a[4]) != 0) { FUN_02320978(5); } else { FUN_02320978(15); } }
}