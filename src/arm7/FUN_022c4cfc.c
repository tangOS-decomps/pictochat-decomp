// decomp: module=arm7 addr=0x022c4cfc name=FUN_022c4cfc
// flags: -O4,s -noThumb

// Unlinks `target` from a doubly-linked list (head/tail pair) by walking the
// chain from the head. Returns the node that was removed, or NULL when the
// target was not on this list.

typedef struct Node022c4cfc {
    unsigned char body[0x60];              /* +0x00 */
    struct Node022c4cfc *prev;             /* +0x60 */
    struct Node022c4cfc *next;             /* +0x64 */
} Node022c4cfc;

typedef struct {
    Node022c4cfc *head;                    /* +0x00 */
    Node022c4cfc *tail;                    /* +0x04 */
} List022c4cfc;

Node022c4cfc *FUN_022c4cfc(List022c4cfc *list, Node022c4cfc *target)
{
    Node022c4cfc *node = list->head;

    while (node != 0) {
        Node022c4cfc *next = node->next;
        if (node == target) {
            Node022c4cfc *prev = node->prev;
            if (list->head == node) {
                list->head = next;
            } else {
                prev->next = next;
            }
            if (list->tail == node) {
                list->tail = prev;
            } else {
                next->prev = prev;
            }
            break;
        }
        node = next;
    }
    return node;
}
