// decomp: module=arm7 addr=0x022dee74 name=FUN_022dee74
// flags: -O4,s -noThumb
// NOTE: verify with --size 0xb0, not the nominal 0xac - the stated size
// excludes this function's own trailing 1-word literal pool.

// Beacon/association tick.  Bit 0 of the caller's flag word selects between
// the AP-side sweep and the client-side single-peer path.
//
// AP side: kick every peer slot from 1 up to the live peer count at +0x322 of
// the ARM7 state block (slot 0 is self).  The count is re-read from the state
// block on every iteration, so FUN_022ded7c may shrink or grow the table.
//
// Client side: find the peer we are talking to (FUN_022d991c, 0xff = none),
// kick it, and if the link mode word at +0x32e says 1, re-check its status
// (FUN_022d9ffc); a status of 0x40 means the peer has gone, so it is dropped
// with reason 0x20 and the link is torn down.
//
// FUN_022d991c taking the same flag word is INFERRED from register liveness:
// r0 is untouched between the function entry and that bl, and spelling it
// FUN_022d991c(void) frees r0 so every scratch register in the prologue shifts
// down by one against the ROM.  If FUN_022d991c is declared void() elsewhere in
// src/, that declaration and this one disagree - reloc slots are wildcarded, so
// only this site's register pressure is evidence either way.
//
// The redundant-looking guard on state+0x322 before the loop is real: the guard
// reads through the hoisted `state` snapshot while the loop condition re-derefs
// 0x0380fff4 every trip, so mwcc cannot fold the two into one test.

typedef unsigned short u16;

extern int FUN_022ded7c(int slot);
extern int FUN_022d991c(const u16 *flags);
extern int FUN_022d9ffc(int peer);
extern void FUN_022d9c60(u16 peer, int reason);
extern void FUN_022deb1c(void);

void FUN_022dee74(const u16 *flags)
{
    unsigned int slot;
    int peer;
    unsigned char *state = *(unsigned char **)0x0380fff4;

    if (*flags & 1) {
        slot = 1;

        if (*(u16 *)(state + 0x322) > 1) {
            while (slot < *(u16 *)(*(unsigned char **)0x0380fff4 + 0x322)) {
                FUN_022ded7c(slot);
                slot++;
            }
        }
    } else {
        peer = FUN_022d991c(flags);

        if (peer != 0xff) {
            FUN_022ded7c(peer);
        }
        if (*(u16 *)(*(unsigned char **)0x0380fff4 + 0x32e) == 1) {
            if (FUN_022d9ffc(peer) == 0x40) {
                FUN_022d9c60((u16)peer, 0x20);
                FUN_022deb1c();
            }
        }
    }
}
