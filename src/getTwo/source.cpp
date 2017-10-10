#include "header.h"

NAN_METHOD(getTwo)
{
    v8::Local<v8::Array> returnValue = Nan::New<v8::Array>(2);
    Nan::Set(returnValue, 0, Nan::New(2));
    Nan::Set(returnValue, 1, Nan::New(2));
    info.GetReturnValue().Set(returnValue);
}
