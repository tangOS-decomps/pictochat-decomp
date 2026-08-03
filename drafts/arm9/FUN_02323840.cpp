// decomp: module=unk_autoload_0 addr=0x02323840 name=FUN_02323840
typedef unsigned short u16;
typedef unsigned int u32;
#define NULL 0

struct MsgHeader {
    char pad[6];
    u16 type;
};

struct Bounds {
    char pad[12];
    u16 max_val;
};

struct AppState {
    char pad_00[0x0c];
    struct MsgHeader *msg;       // +0x0c
    struct MsgHeader *msg_next;  // +0x10
    struct Bounds *bounds;       // +0x14
    void (*cb)(void *, u16, int, int); // +0x18
    void *cb_arg;                // +0x1c
    char pad_20[0x0c];
    u16 type;                    // +0x2c
    u16 subtype;                 // +0x2e
    u16 flags;                   // +0x30
    u16 unk_32;                  // +0x32
    u32 unk_34;                  // +0x34
    struct MsgHeader *hdr;       // +0x38
    u32 unk_3c;                  // +0x3c
    u32 conn_state;              // +0x40
};

extern struct AppState G_0238ef0c;
extern struct AppState G_0238ef18;
extern struct AppState G_0238ef30;

extern int FUN_02322da8(void);
extern int FUN_02320978(int);
extern int FUN_02325278(void);
extern void *FUN_0232310c(struct AppState *, void *, int);
extern int FUN_0232414c(struct AppState *, struct AppState *);
extern int FUN_023212bc(void);
extern int FUN_023212e0(void);
extern int FUN_023212ec(void);
extern int FUN_023212f8(void);
extern int FUN_02321304(void);
extern int FUN_023251e4(struct AppState *);
extern int FUN_0232519c(struct AppState *);
extern int FUN_023251cc(struct AppState *);
extern int FUN_023251c4(struct AppState *);
extern u16 FUN_02323c90(struct AppState *, u16);

extern "C" void FUN_02323840(void) {
    struct AppState *const state = &G_0238ef0c;
    u16 type;
    state->type = 0;
    state->subtype = 0;
    
    if (state->unk_3c != 0) {
        state->unk_3c = 0;
        struct MsgHeader *hdr = state->hdr;
        type = hdr->type;
        state->type = type;
        if (type != 0) {
            if (type == 1) {
                if (state->conn_state != 0 && !FUN_02322da8()) {
                    goto end_t1;
                }
                FUN_02320978(8);
                end_t1:;
            } else if (type == 2) {
                if (state->conn_state != 0) {
                    FUN_02320978(15);
                } else {
                    FUN_02320978(10);
                }
            } else if (state->bounds != NULL && type <= state->bounds->max_val) {
                FUN_02320978(6);
            } else if (type != 0) {
                FUN_02320978(6);
            }
        }
    } else {
        u32 events = FUN_02325278();
        if (events & 2) {
            state->type = 1;
            if (state->conn_state != 0 && !FUN_02322da8()) {
                goto end_t2;
            }
            FUN_02320978(8);
            end_t2:;
        } else {
            events = FUN_02325278();
            if (events & 0x400) {
                if (state->unk_34 == 0) {
                    if (state->unk_32 == 0) {
                        state->type = 4;
                    } else if (state->unk_32 == 4) {
                        state->type = 5;
                    } else if (state->unk_32 == 5) {
                        state->type = 5;
                    }
                }
                FUN_02320978(6);
            } else {
                events = FUN_02325278();
                if (events & 0x40) {
                    FUN_02320978(0x28);
                } else {
                    events = FUN_02325278();
                    if (events & 0x10) {
                        FUN_0232414c(state, &G_0238ef18);
                    } else {
                        events = FUN_02325278();
                        if (events & 0x20) {
                            FUN_0232414c(state, &G_0238ef18);
                        } else {
                            events = FUN_02325278();
                            if (events & 0x80) {
                                FUN_0232414c(state, &G_0238ef18);
                            }
                        }
                    }
                }
            }
        }
    }

    if (FUN_023212e0()) {
        int a = FUN_023212f8();
        int b = FUN_02321304();
        FUN_0232310c(&G_0238ef18, (void*)a, b);
    }

    int state_mode = FUN_023212ec();
    if (state_mode == 1) {
        int a = FUN_023212f8();
        int b = FUN_02321304();
        struct MsgHeader *m = (struct MsgHeader *)FUN_0232310c(state, (void*)a, b);
        state->msg = m;
        if (m != NULL) {
            u16 t = m->type;
            if (t == 1) {
                if (state->conn_state != 0 && !FUN_02322da8()) {
                    goto end_t3;
                }
                FUN_02320978(8);
                end_t3:;
            } else if (t == 2) {
                if (state->conn_state != 0) {
                    FUN_02320978(10);
                }
            } else if (t != 0 && state->bounds != NULL && t <= state->bounds->max_val) {
                FUN_02320978(6);
            } else if (t != 0) {
                FUN_02320978(6);
            }
        }
    } else if (state_mode == 3) {
        if (state->msg != NULL && FUN_023251e4(&G_0238ef30) == 0) {
            int a = FUN_023212f8();
            int b = FUN_02321304();
            struct MsgHeader *res = (struct MsgHeader *)FUN_0232310c(&G_0238ef18, (void*)a, b);
            if (res != NULL) {
                struct MsgHeader *msg = state->msg;
                if (msg != NULL && res->type == msg->type) {
                    state->type = msg->type;
                    u16 t = msg->type;
                    if (t == 1) {
                        if (state->conn_state != 0 && !FUN_02322da8()) {
                            goto end_t4;
                        }
                        FUN_02320978(9);
                        end_t4:;
                    } else if (t == 2) {
                        if (state->conn_state == 0) {
                            FUN_02320978(11);
                        }
                    } else if (t != 0) {
                        struct Bounds *b = state->bounds;
                        if (b == NULL || t > b->max_val) {
                            if (t != 0) {
                                FUN_02320978(7);
                            }
                        } else {
                            FUN_02320978(7);
                        }
                    }
                }
            }
        }
    }

    if (state->cb != NULL && state->flags != 0) {
        int arg1 = FUN_023212f8();
        int arg2 = FUN_02321304();
        state->cb(state->cb_arg, state->flags, arg1, arg2);
    }
    state->flags = 0;
    state->msg = NULL;

    int active = 0;
    struct MsgHeader *msg1 = state->msg;
    if (msg1 != NULL) {
        struct MsgHeader *msg2 = state->msg_next;
        if (msg2 != NULL) {
            if (msg1->type == msg2->type) {
                active = 1;
            }
        }
    }
    if (active) {
        FUN_0232519c(state);
        if (FUN_023251cc(state)) {
            struct MsgHeader *m = state->msg;
            state->type = m->type;
            u16 t = m->type;
            if (t == 1) {
                if (state->conn_state != 0 && !FUN_02322da8()) {
                    goto end_t5;
                }
                FUN_02320978(8);
                end_t5:;
            } else if (t == 2) {
                if (state->conn_state == 0) {
                    FUN_02320978(10);
                }
            } else if (t != 0) {
                struct Bounds *bounds = state->bounds;
                if (bounds == NULL || t > bounds->max_val) {
                    if (t != 0) {
                        FUN_02320978(6);
                    }
                } else {
                    FUN_02320978(6);
                }
            }
        }
    } else {
        FUN_023251c4(state);
    }

    int a = FUN_023212f8();
    int b = FUN_02321304();
    struct MsgHeader *res = (struct MsgHeader *)FUN_0232310c(&G_0238ef18, (void*)a, b);
    struct MsgHeader *msg = state->msg;
    if (msg != NULL) {
        if (res == NULL || res->type != msg->type) {
            u16 len = FUN_02323c90(state, msg->type);
            if (len >= 0x20) {
                state->flags = len;
            }
        }
    }
    u16 len = FUN_02323c90(state, state->type);
    state->subtype = len;
    if (state->type != 0) {
        struct Bounds *b = state->bounds;
        if (b != NULL) {
            state->unk_34 = (u32)b;
        }
    }
}
