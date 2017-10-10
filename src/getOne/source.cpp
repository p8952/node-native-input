#include "header.h"

NAN_METHOD(getOne)
{
    v8::Local<v8::Array> returnValue = Nan::New<v8::Array>(2);
    Nan::Set(returnValue, 0, Nan::New(1));
    Nan::Set(returnValue, 1, Nan::New(1));
    info.GetReturnValue().Set(returnValue);
}
