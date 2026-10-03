//cpp
// decomp: module=unk_autoload_0 addr=0x02330be8 name=FUN_02330be8
struct Node {unsigned int a[26]; Node *next; unsigned int pad; unsigned int priority;};
extern "C" unsigned int G_023c07c4[];
extern "C" void FUN_02330be8(Node *node) {
Node *cur; Node *prev; Node *head;prev=0; head=(Node*)G_023c07c4[9]; cur=head;
  while (cur && cur->priority < node->priority) {prev = cur; cur = cur->next;}
  if (!prev) {node->next = head; G_023c07c4[9] = (unsigned int)node;}
  else {node->next = prev->next; prev->next = node;}
}
