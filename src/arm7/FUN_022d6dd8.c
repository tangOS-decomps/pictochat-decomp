// decomp: module=arm7 addr=0x022d6dd8 name=FUN_022d6dd8
// flags: -O4,s -noThumb

// Walks the chain hanging off +0 (terminated by -1, not NULL) and hands every
// link to func_037c5998 along with the owner, but only when the count at +8 is
// non-zero. The successor is cached before the callback because the callback
// consumes the link.

typedef struct Link {
    struct Link *f0;
    struct Link *next;
} Link;

typedef struct Owner {
    Link *head;
    int f4;
    unsigned short f8;
} Owner;

extern void func_037c5998(Owner *owner, Link *link);

void FUN_022d6dd8(Owner *owner)
{
    Link *link = owner->head;
    if (owner->f8 != 0) {
        while (link != (Link *)-1) {
            Link *next = link->next;
            func_037c5998(owner, link);
            link = next;
        }
    }
}
