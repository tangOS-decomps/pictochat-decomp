//cpp
#pragma thumb on
extern "C" {
extern int G_023bd60c[];
extern int G_023bd66c[];
extern void FUN_02331ef0(int*);
int FUN_02329e80(void) { G_023bd60c[3] = 1; FUN_02331ef0(G_023bd66c); return 1; }
}