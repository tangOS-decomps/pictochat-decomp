// decomp: module=arm7 addr=0x022c4d84 name=FUN_022c4d84
// flags: -O4,s -noThumb

// Inserts `item` into the singly linked list hanging off +0x24 of the
// scheduler block at 0x03804f68, keeping it sorted by the key at +0x54 in
// ascending order (the new node lands after every strictly smaller key).

typedef struct Node {
    char pad[0x4c];
    struct Node *next;
    char pad2[4];
    unsigned int key;
} Node;

typedef struct Sched {
    char pad[0x24];
    Node *head;
} Sched;

extern Sched G_03804f68;

void FUN_022c4d84(Node *item)
{
    Node *cur;
    Node *prev = 0;
    Node *head = G_03804f68.head;

    for (cur = head; cur != 0 && cur->key < item->key; cur = cur->next) {
        prev = cur;
    }

    if (prev == 0) {
        item->next = head;
        G_03804f68.head = item;
    } else {
        item->next = prev->next;
        prev->next = item;
    }
}
