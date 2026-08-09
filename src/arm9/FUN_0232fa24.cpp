//cpp
// decomp: module=unk_autoload_0 addr=0x0232fa24 name=FUN_0232fa24
extern "C" {

extern void *FUN_0232f688(void);
extern void *FUN_0232f84c(void *buffer, void *context, int arg2, int arg3, int arg4);
extern void *FUN_0232f6a8(void *arg0, void *arg1, void *arg2, int arg3);
extern void FUN_023314e8(void *buffer, void *context);

void *FUN_0232fa24(void *arg0, int arg1, int arg2, int arg3, void *buffer)
{
    void *context;
    void *result;

    context = FUN_0232f688();
    if (context == 0) {
        return 0;
    }
    if (buffer == 0) {
        return 0;
    }
    result = FUN_0232f84c(buffer, (char *)context + 0x20, arg1, arg2, arg3);
    if (result == 0) {
        return 0;
    }
    if (context != FUN_0232f6a8(arg0, result, context, 0)) {
        return 0;
    }
    FUN_023314e8(result, context);
    return result;
}

}
