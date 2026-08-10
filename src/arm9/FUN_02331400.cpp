//cpp
// decomp: module=unk_autoload_0 addr=0x02331400 name=FUN_02331400
#pragma thumb on
struct Node_02331400 {
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
};
extern "C" {
extern Node_02331400 *FUN_02330bcc(void *);
extern void FUN_02330f6c(Node_02331400 *);
void FUN_02331400(void *self)
{
    if (*(void **)((unsigned char *)self + 0x88) != 0) {
        void *list = (unsigned char *)self + 0x88;
        do {
            Node_02331400 *node = FUN_02330bcc(list);
            node->field_0c = 0;
            node->field_08 = 0;
            FUN_02330f6c(node);
        } while (*(void **)((unsigned char *)self + 0x88) != 0);
    }
}
}
