//cpp
// decomp: module=unk_autoload_0 addr=0x0232e0ac name=FUN_0232e0ac

extern "C" {
struct Node0232e0ac {
    void *head;
    char *tail;
    unsigned short count;
    unsigned short offset;
};

extern void FUN_0232e090(Node0232e0ac *, char *);

void FUN_0232e0ac(Node0232e0ac *node, char *buffer)
{
    if (node->head == 0) {
        FUN_0232e090(node, buffer);
        return;
    }

    unsigned short offset = node->offset;
    *(char **)(buffer + offset) = node->tail;
    *(int *)(buffer + offset + 4) = 0;
    *(char **)(node->tail + node->offset + 4) = buffer;
    node->tail = buffer;
    node->count++;
}
}
