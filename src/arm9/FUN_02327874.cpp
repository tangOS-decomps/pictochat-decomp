//cpp
// decomp: module=unk_autoload_0 addr=0x02327874 name=FUN_02327874

// Initialisation step: runs FUN_02322db4, then clears/fills two adjacent
// structures in RAM - 0x1a bytes at G_0239fe4c through FUN_023374f0 and 0x14
// bytes at G_0239fe38 through FUN_0233746c - and hands the second to
// FUN_0232e980.
//
// The two fill helpers live in ARM code, so the ROM reaches them with `blx`
// where a Thumb-to-Thumb call would use `bl`. Both are relocation slots, so the
// encodings compare equal either way.

#pragma thumb on
extern "C" {
extern int G_0239fe4c[];
extern int G_0239fe38[];
extern void FUN_02322db4(void);
extern void FUN_023374f0(void *, int, int);
extern void FUN_0233746c(int, void *, int);
extern void FUN_0232e980(int *);

void FUN_02327874(void)
{
    FUN_02322db4();
    FUN_023374f0(G_0239fe4c, 0, 0x1a);
    FUN_0233746c(0, G_0239fe38, 0x14);
    FUN_0232e980(G_0239fe38);
}
}
