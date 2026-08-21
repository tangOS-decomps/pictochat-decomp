// decomp: module=unk_autoload_0 addr=0x02337df4 name=FUN_02337df4
#pragma thumb on

struct Node02337df4 {
    void *val;
    struct Node02337df4 *next;
};

struct Obj02337df4 {
    char pad[0x18];
    struct Node02337df4 *head;
};

extern void FUN_02337700(void);
extern void FUN_02337710(void);
extern void FUN_02331268(void *, int);

void FUN_02337df4(struct Obj02337df4 *obj)
{
    struct Node02337df4 *cur;
    struct Node02337df4 *next;

    FUN_02337700();
    cur = obj->head;
    if (cur != 0) {
        do {
            next = cur->next;
            cur->val = 0;
            cur->next = 0;
            FUN_02331268(cur, 8);
            cur = next;
        } while (next != 0);
    }
    FUN_02337710();
}
