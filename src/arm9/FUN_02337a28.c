// decomp: module=unk_autoload_0 addr=0x02337a28 name=FUN_02337a28

// Takes the next pre-built buffer chain from the 9-entry ring at G_023c1984
// and appends it to the free list at G_023c1960, unless the shared counter
// says nothing new is available. With bit 0 of `wait` set it sleeps 50 ms
// at a time until something is; otherwise it returns 0 immediately.

typedef struct Node Node;
struct Node {
    Node *next;
};

typedef struct Q {
    Node *head;
    int count;
    Node *head2;
    Node *tail2;
    Node *tail;
    int index;
    int pad18;
    int avail;
} Q;

extern Q G_023c1960;
extern Node *G_023c1984[];
extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern void FUN_023320fc(int);
extern int FUN_02337eec(void);

Node *FUN_02337a28(int wait)
{
    int irq = FUN_02332080();
    Node *node;
    Node *last;

    if (wait & 1) {
        while (G_023c1960.count == FUN_02337eec()) {
            FUN_02332094(irq);
            FUN_023320fc(0x32);
            irq = FUN_02332080();
        }
    } else if (G_023c1960.count == FUN_02337eec()) {
        FUN_02332094(irq);
        return 0;
    }

    node = G_023c1984[G_023c1960.index];
    if (++G_023c1960.index > 8) G_023c1960.index = 0;

    last = node;
    while (last->next != 0) last = last->next;

    if (G_023c1960.tail != 0) G_023c1960.tail->next = node;
    else G_023c1960.head = node;
    G_023c1960.tail = last;
    G_023c1960.avail--;
    G_023c1960.count++;
    FUN_02332094(irq);
    return node;
}
