// decomp: module=arm7 addr=0x022c59c8 name=FUN_022c59c8
// flags: -O4,s -noThumb
// ARM7 subsystem bring-up: calls each init entry point in a fixed order and
// finishes with the "init complete" notifier.  FUN_022c59fc and FUN_022c5a08
// are the ARM->Thumb veneers the linker parked immediately after this
// function; their real targets are the Thumb entries 0x037fed78 and
// 0x03803f50 (see lever 5 - the reloc resolves to the veneer, not the entry).
extern void FUN_022c59fc(void);
extern void FUN_022c5a14(void);
extern void FUN_022c4948(void);
extern void FUN_022c4714(void);
extern void FUN_022c5f78(void);
extern void FUN_022c6168(void);
extern void FUN_022c638c(void);
extern void FUN_022c4efc(void);
extern void FUN_022c6e50(void);
extern void FUN_022c5a08(void);

void FUN_022c59c8(void) {
    FUN_022c59fc();
    FUN_022c5a14();
    FUN_022c4948();
    FUN_022c4714();
    FUN_022c5f78();
    FUN_022c6168();
    FUN_022c638c();
    FUN_022c4efc();
    FUN_022c6e50();
    FUN_022c5a08();
}
