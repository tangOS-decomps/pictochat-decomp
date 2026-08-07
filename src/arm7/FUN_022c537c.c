// decomp: module=arm7 addr=0x022c537c name=FUN_022c537c
// flags: -noThumb

typedef struct Node {
    char pad[0x48];
    int state;
    struct Node *next;
} Node;

extern char G_03804f68[];

Node *FUN_022c537c(void)
{
    Node *node = (Node *)G_03804f68;

    node = *(Node **)((char *)node + 0x24);

    while (node != 0 && node->state != 1) {
        node = node->next;
    }
    return node;
}
