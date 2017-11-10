#include "getScreenDimensions.h"

#ifdef Windows
#endif

#ifdef MacOS
#endif

#ifdef Linux
#include <X11/Xlib.h>
#endif

NAN_METHOD(getScreenDimensions)
{
    int screenWidth;
    int screenHeight;

#ifdef Windows
    screenWidth = GetSystemMetrics(SM_CXVIRTUALSCREEN);
    screenHeight = GetSystemMetrics(SM_CYVIRTUALSCREEN);
#endif

#ifdef MacOS
#endif

#ifdef Linux
    Display *mainDisplay = XOpenDisplay(NULL);
    Window rootWindow = DefaultRootWindow(mainDisplay);
    XWindowAttributes rootWindowAttributes;
    XGetWindowAttributes(mainDisplay, rootWindow, &rootWindowAttributes);

    screenWidth = rootWindowAttributes.width;
    screenHeight = rootWindowAttributes.height;

    XDestroyWindow(mainDisplay, rootWindow);
    XCloseDisplay(mainDisplay);
#endif

    v8::Local<v8::Array> screenDimensions = Nan::New<v8::Array>(2);
    Nan::Set(screenDimensions, 0, Nan::New(screenWidth));
    Nan::Set(screenDimensions, 1, Nan::New(screenHeight));
    info.GetReturnValue().Set(screenDimensions);
}
