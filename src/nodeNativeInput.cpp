#include "getOne/getOne.h"
#include "getTwo/getTwo.h"
#include "getThree/getThree.h"
#include "getScreenDimensions/getScreenDimensions.h"

using v8::FunctionTemplate;
using v8::String;

using Nan::Set;
using Nan::New;
using Nan::GetFunction;

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
}

NODE_MODULE(NativeExtension, InitAll)
