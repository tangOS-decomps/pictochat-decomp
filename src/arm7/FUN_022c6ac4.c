// decomp: module=arm7 addr=0x022c6ac4 name=FUN_022c6ac4
// flags: -O4,s -noThumb

typedef struct Node {
    char pad0[8];
    int owner;          // +0x08
    char pad8[0x0c];
    struct Node *next;  // +0x18
} Node;

typedef struct List {
    char pad0[0x0c];
    Node *head;         // +0x0c
} List;

extern List G_0380520c;

extern int FUN_022c6d40(void);
extern void FUN_022c6d54(int state);
extern void FUN_022c6e94(void);
extern void FUN_022c6a78(Node *n);

void FUN_022c6ac4(int owner)
{
    Node *p;
    Node *next;
    int state;

    state = FUN_022c6d40();
    if (owner == 0) {
        FUN_022c6e94();
    }

    p = G_0380520c.head;
    next = p != 0 ? p->next : 0;
    while (p != 0) {
        if (p->owner == owner) {
            FUN_022c6a78(p);
        }
        p = next;
        next = p != 0 ? p->next : 0;
    }

    FUN_022c6d54(state);
}
