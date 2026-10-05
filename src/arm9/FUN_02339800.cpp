//cpp
// decomp: module=unk_autoload_0 addr=0x02339800 name=FUN_02339800
extern "C" int FUN_02332080(void);
extern "C" void FUN_02332094(int);
struct Node { void *a; void *b; void *c; Node *next; };
extern "C" void FUN_02339800(Node **head, Node *node) {
 if (head) {
  int irq=FUN_02332080();
  Node *cur=*head, *prev=cur;
  while(cur) {
   if(cur==node) {
    if(cur==prev) *head=cur->next;
    else prev->next=cur->next;
    break;
   }
   prev=cur; cur=cur->next;
  }
  FUN_02332094(irq);
 }
}
