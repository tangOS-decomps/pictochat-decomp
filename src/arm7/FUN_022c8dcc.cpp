//cpp
// decomp: module=arm7 addr=0x022c8dcc name=FUN_022c8dcc
// flags: -O4,s -thumb
typedef unsigned char u8;

struct Node {
    u8 _pad[0x50];
    Node* next;
};

extern "C" void FUN_022c83d0(Node* node);

extern "C" void FUN_022c8dcc(void* self)
{
    Node* node = *(Node**)((u8*)self + 0x3c);

    for (; node != 0; node = node->next) {
        FUN_022c83d0(node);
    }

    *(Node**)((u8*)self + 0x3c) = 0;
}
