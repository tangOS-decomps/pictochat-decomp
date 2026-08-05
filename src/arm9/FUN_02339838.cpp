//cpp
// decomp: module=unk_autoload_0 addr=0x02339838 name=FUN_02339838

#pragma thumb on
extern "C" {
struct Node { void (*func)(int); int arg; int pad; struct Node* next; };
void FUN_02339838(struct Node* node) { while (node != 0) { node->func(node->arg); node = node->next; } }
}
