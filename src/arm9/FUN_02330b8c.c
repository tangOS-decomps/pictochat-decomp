// decomp: module=unk_autoload_0 addr=0x02330b8c name=FUN_02330b8c
typedef struct Node_0b8c {
    unsigned char pad[0x7c];
    struct Node_0b8c *prev;
    struct Node_0b8c *next;
} Node_0b8c;

typedef struct List_0b8c {
    Node_0b8c *head;
    Node_0b8c *tail;
} List_0b8c;

Node_0b8c *FUN_02330b8c(List_0b8c *list, Node_0b8c *target) {
    Node_0b8c *next;
    Node_0b8c *n;
    Node_0b8c *prev;
    Node_0b8c *head;
    n = head = list->head;
    while (n != 0) {
        next = n->next;
        if (n == target) {
            prev = n->prev;
            if (head == n) {
                list->head = next;
            } else {
                prev->next = next;
            }
            if (list->tail == n) {
                list->tail = prev;
            } else {
                next->prev = prev;
            }
            break;
        }
        n = next;
    }
    return n;
}
