//cpp
#pragma thumb on
extern "C" {
int FUN_02326774(int a) { a--; if (a < 0) { a += 1024; } return a; }
}