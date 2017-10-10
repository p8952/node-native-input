#include "getThree.h"

NAN_METHOD(getThree)
{
    v8::Local<v8::Array> returnValue = Nan::New<v8::Array>(2);
    Nan::Set(returnValue, 0, Nan::New(3));
    Nan::Set(returnValue, 1, Nan::New(3));
    info.GetReturnValue().Set(returnValue);
}
