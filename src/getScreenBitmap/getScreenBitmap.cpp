#include "getScreenBitmap.h"

#ifdef Windows
#endif

#ifdef MacOS
#endif

#ifdef Linux
#include <X11/Xutil.h>
#include <X11/Xlib.h>
#endif

typedef struct
{
unsigned int   bfSize;
unsigned short bfReserved1;
unsigned short bfReserved2;
unsigned int   bfOffBits;
} BITMAPFILEHEADER;

typedef struct
{
unsigned int   biSize;
int            biWidth;
int            biHeight;
unsigned short biPlanes;
unsigned short biBitCount;
unsigned int   biCompression;
unsigned int   biSizeImage;
int            biXPelsPerMeter;
int            biYPelsPerMeter;
unsigned int   biClrUsed;
unsigned int   biClrImportant;
} BITMAPINFOHEADER;

BITMAPFILEHEADER bfh;
BITMAPINFOHEADER bih;

NAN_METHOD(getScreenBitmap)
{

    char *bitmapData;
    int bitmapSize;

#ifdef Windows
#endif

#ifdef MacOS
#endif

#ifdef Linux
    Display *mainDisplay = XOpenDisplay(NULL);
    Window rootWindow = DefaultRootWindow(mainDisplay);
    XWindowAttributes rootWindowAttributes;
    XGetWindowAttributes(mainDisplay, rootWindow, &rootWindowAttributes);
    XImage *rootWindowImage = XGetImage(mainDisplay, rootWindow, 0, 0, rootWindowAttributes.width, rootWindowAttributes.height, AllPlanes, ZPixmap);

    bitmapSize = 2 + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + rootWindowAttributes.width * rootWindowAttributes.height * 3;

    unsigned short bfType=0x4d42;

    bfh.bfReserved1 = 0;
    bfh.bfReserved2 = 0;
    bitmapSize = bitmapSize;
    bfh.bfOffBits = 0x36;

    bih.biSize = sizeof(BITMAPINFOHEADER);
    bih.biWidth = rootWindowAttributes.width;
    bih.biHeight = rootWindowAttributes.height;
    bih.biPlanes = 1;
    bih.biBitCount = 24;
    bih.biCompression = 0;
    bih.biSizeImage = 0;
    bih.biXPelsPerMeter = 2835;
    bih.biYPelsPerMeter = 2835;
    bih.biClrUsed = 0;
    bih.biClrImportant = 0;

    char *rootWindowBitmap = new char[bitmapSize];
    char *rootWindowBitmapPtr = rootWindowBitmap;
    memset(rootWindowBitmap, 0, bitmapSize);

    memcpy(rootWindowBitmapPtr, &bfType, sizeof(bfType));
    rootWindowBitmapPtr += sizeof(bfType);

    memcpy(rootWindowBitmapPtr, &bfh, sizeof(bfh));
    rootWindowBitmapPtr += sizeof(bfh);

    memcpy(rootWindowBitmapPtr, &bih, sizeof(bih));
    rootWindowBitmapPtr += sizeof(bih);

    unsigned long blueMask = rootWindowImage->blue_mask;
    unsigned long greenMask = rootWindowImage->green_mask;
    unsigned long redMask = rootWindowImage->red_mask;

    for (int y = bih.biHeight - 1; y >= 0; y--)
    {
        for (int x = 0; x < bih.biWidth; x++)
        {
            unsigned long imagePixel = XGetPixel(rootWindowImage, x, y);
            char bluePixel = (imagePixel & blueMask);
            char greenPixel = (imagePixel & greenMask) >> 8;
            char redPixel = (imagePixel & redMask) >> 16;

            memcpy(rootWindowBitmapPtr, &bluePixel, sizeof(bluePixel));
            rootWindowBitmapPtr += sizeof(bluePixel);

            memcpy(rootWindowBitmapPtr, &greenPixel, sizeof(greenPixel));
            rootWindowBitmapPtr += sizeof(greenPixel);

            memcpy(rootWindowBitmapPtr, &redPixel, sizeof(redPixel));
            rootWindowBitmapPtr += sizeof(redPixel);
        }
    }

    bitmapData = rootWindowBitmap;

    delete[] rootWindowBitmap;
    XDestroyImage(rootWindowImage);
    XDestroyWindow(mainDisplay, rootWindow);
    XCloseDisplay(mainDisplay);
#endif

    v8::MaybeLocal<v8::Object> screenBitmap = Nan::NewBuffer(bitmapData, bitmapSize);
    info.GetReturnValue().Set(screenBitmap.ToLocalChecked());
}
