// decomp: module=unk_autoload_0 addr=0x02337b54 name=FUN_02337b54

// Flushes the pending chain at G_023c1960+8 to the other CPU: waits (bit 0 of
// `flags`) for a free slot in the 9-entry ring at G_023c1984, flushes the
// shared buffer, posts FIFO command 7 with the chain head, then records it in
// the ring and clears the pending chain. Bit 1 also waits for the reply.
// Returns 0 only when it would have to block and blocking was not requested.

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
    int index2;
    int avail;
    int sent;
} Q;

extern Q G_023c1960;
extern Node *G_023c1984[];
extern char G_023c1c40[];
extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern void FUN_02331504(void *, int);
extern int FUN_0233831c(int, int, int);
extern Node *FUN_02337a28(int);
extern void FUN_02337dc0(void);

int FUN_02337b54(int flags)
{
    int irq = FUN_02332080();

    if (G_023c1960.head2 == 0) {
        FUN_02332094(irq);
        return 1;
    }
    if (G_023c1960.avail >= 8) {
        if (!(flags & 1)) {
            FUN_02332094(irq);
            return 0;
        }
        do {
            FUN_02337a28(1);
        } while (G_023c1960.avail >= 8);
        if (G_023c1960.head2 == 0) {
            FUN_02332094(irq);
            return 1;
        }
    }

    FUN_02331504(G_023c1c40, 0x1800);
    if (FUN_0233831c(7, (int)G_023c1960.head2, 0) < 0) {
        if (!(flags & 1)) {
            FUN_02332094(irq);
            return 0;
        }
        while (G_023c1960.avail >= 8 || FUN_0233831c(7, (int)G_023c1960.head2, 0) < 0) {
            FUN_02332094(irq);
            FUN_02337a28(0);
            irq = FUN_02332080();
            FUN_02331504(G_023c1c40, 0x1800);
            if (G_023c1960.head2 == 0) {
                FUN_02332094(irq);
                return 1;
            }
        }
    }

    G_023c1984[G_023c1960.index2] = G_023c1960.head2;
    if (++G_023c1960.index2 > 8) G_023c1960.index2 = 0;
    G_023c1960.head2 = 0;
    G_023c1960.tail2 = 0;
    G_023c1960.avail++;
    G_023c1960.sent++;
    FUN_02332094(irq);

    if (flags & 2) FUN_02337dc0();
    return 1;
}
