//cpp
// decomp: module=unk_autoload_0 addr=0x0233895c name=FUN_0233895c
// verify: python tools/match.py --c src/arm9/FUN_0233895c.cpp --func FUN_0233895c --addr 0x0233895c --size 0xc4 --module unk_autoload_0 --version 2.0/sp1

extern "C" {
void FUN_02332274(void);
int FUN_02332080(void);
void FUN_02332094(int);
void FUN_0233846c(void *, int);
int FUN_0233879c(void *, int);
void FUN_02338908(void *);
void FUN_023388b4(void);

struct Node_0233895c {
    Node_0233895c *next;
    int field04;
    Node_0233895c *parent;
    unsigned int flags;
    int field10;
    int state;
};

int FUN_0233895c(Node_0233895c *self, int value, int activate)
{
    Node_0233895c *parent = self->parent;
    int result = 0;
    int enabled = (self->flags & 1) ? 1 : result;

    if (enabled != 0) {
        FUN_02332274();
    }
    if (parent == 0) {
        self->state = 6;
        return 0;
    }

    self->state = 2;
    unsigned int *flags = &self->flags;
    *flags = (*flags & 0xffff00ff) | (value << 8) | 1;
    self->next = 0;
    if (activate) {
        *flags |= 4;
    }

    int lock = FUN_02332080();
    if (parent->state & 0x80) {
        FUN_0233846c(self, 3);
    } else {
        Node_0233895c **link = &parent->parent;
        while (*link != 0) {
            link = &(*link)->next;
        }
        *link = self;
    }
    FUN_02332094(lock);

    if (self->state != 3) {
        int found = FUN_0233879c(parent, 0);
        if (activate) {
            FUN_02338908(self);
            result = self->state == 0;
        } else {
            if (found != 0) {
                FUN_023388b4();
            }
            result = 1;
        }
    }
    return result;
}
}
