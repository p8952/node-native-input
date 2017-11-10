#include "getOne/getOne.h"
#include "getTwo/getTwo.h"
#include "getThree/getThree.h"
#include "getScreenDimensions/getScreenDimensions.h"
#include "getScreenBitmap/getScreenBitmap.h"

using v8::FunctionTemplate;
using v8::String;

using Nan::GetFunction;
using Nan::New;
using Nan::Set;

NAN_MODULE_INIT(InitAll)
{
    Set(target, New<String>("getOne").ToLocalChecked(),
        GetFunction(New<FunctionTemplate>(getOne)).ToLocalChecked());

    Set(target, New<String>("getTwo").ToLocalChecked(),
        GetFunction(New<FunctionTemplate>(getTwo)).ToLocalChecked());

    Set(target, New<String>("getThree").ToLocalChecked(),
        GetFunction(New<FunctionTemplate>(getThree)).ToLocalChecked());

    Set(target, New<String>("getScreenDimensions").ToLocalChecked(),
        GetFunction(New<FunctionTemplate>(getScreenDimensions)).ToLocalChecked());

    Set(target, New<String>("getScreenBitmap").ToLocalChecked(),
        GetFunction(New<FunctionTemplate>(getScreenBitmap)).ToLocalChecked());
}

NODE_MODULE(NativeExtension, InitAll)
