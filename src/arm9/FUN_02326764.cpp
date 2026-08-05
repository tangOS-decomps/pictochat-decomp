//cpp
#pragma thumb on
extern "C" {
int FUN_02326764(int a) { a++; if (a >= 1024) { a -= 1024; } return a; }
}